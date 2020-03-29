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
    Logger::WriteLog("State construct");
}

State::~State()
{
    Logger::WriteLog("State desctruct");
}

void State::RequestStatePush(StateID stateID)
{
    mStack->PushState(stateID);
}
void State::RequestStatePop()
{
    mStack->PopState();
}
void State::RequestStateClear()
{
    mStack->ClearStates();
}

State::Context State::GetContext() const
{
    return mContext;
}