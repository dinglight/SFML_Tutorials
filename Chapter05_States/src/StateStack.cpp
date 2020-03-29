#include "StateStack.h"

#include <cassert>

#include "Logger.h"

StateStack::StateStack(State::Context context)
: mStack()
, mPendingList()
, mContext(context)
, mFactories()
{
    Logger::WriteLog("StateStack construct");
}
StateStack::~StateStack()
{
    Logger::WriteLog("StateStack desctruct");
}
void StateStack::HandleEvent(const sf::Event& event)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
        if ((*itr)->HandleEvent(event))
            break;
    }
    ApplyPendingChanges();
}

void StateStack::Update(sf::Time dt)
{
    for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
        if ((*itr)->Update(dt))
            break;
    }
    ApplyPendingChanges();
}

void StateStack::Draw()
{
    for (auto& state: mStack) {
        state->Draw();
    }
}

void StateStack::PushState(StateID stateID)
{
    Logger::WriteLog("StateStack::PushState");
    mPendingList.emplace_back(PendingChange(Action::Push, stateID));
}

void StateStack::PopState()
{
    mPendingList.emplace_back(PendingChange(Action::Pop));
}

void StateStack::ClearStates()
{
    mPendingList.emplace_back(PendingChange(Action::Clear));
}

bool StateStack::IsEmpty() const
{
    return mStack.empty();
}

State::Ptr StateStack::CreateState(StateID stateID)
{
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());
    return found->second();
}
void StateStack::ApplyPendingChanges()
{
    for (auto & change : mPendingList) {
        switch (change.action) {
        case Action::Push:
            mStack.emplace_back(CreateState(change.stateID));
            break;
        case Action::Pop:
            mStack.pop_back();
            break;
        case Action::Clear:
            mStack.clear();
            break;
        }
    }
    mPendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, StateID stateID)
: action(action)
, stateID(stateID)
{

}