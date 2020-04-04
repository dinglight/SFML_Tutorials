#include "State.h"

#include <SFML/Window/Window.hpp>

#include "StateStack.h"
#include "Logger.h"
State::Context::Context(sf::RenderWindow& window, TextureHolder& textureHolder, FontHolder& fontHolder)
: window(&window)
, textureHolder(&textureHolder)
, fontHolder(&fontHolder)
{
}

/////////////////////////////////////////////////////////

State::State(StateStack& stack, Context context)
:mStack(&stack)
,mContext(context)
{
    LOG(INFO) << "State construct";
}

State::~State()
{
    LOG(INFO) << "State desctruct";
}

void State::RequestStatePush(StateID stateID)
{
    LOG(INFO) << "State::RequestStatePush";
    mStack->PushState(stateID);
}
void State::RequestStatePop()
{
    LOG(INFO) << "State::RequestStatePop";
    mStack->PopState();
}
void State::RequestStateClear()
{
    LOG(INFO) << "State::RequestStateClear";
    mStack->ClearStates();
}

State::Context State::GetContext() const
{
    return mContext;
}