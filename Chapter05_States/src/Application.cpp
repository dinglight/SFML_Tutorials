#include "Application.h"

#include <SFML/Window/Event.hpp>

#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"

#include "Logger.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(640, 480), "States", sf::Style::Close)
, mTexturesHolder()
, mFontHolder()
, mStateStack(State::Context(mWindow, mTexturesHolder, mFontHolder))
{
    mTexturesHolder.Load(TextureID::TitleScreen, "res/textures/TitleScreen.png");
    mTexturesHolder.Load(TextureID::MenuScreen, "res/textures/MenuScreen.png");
    mFontHolder.Load(FontID::Main, "res/fonts/Sansation.ttf");

    LOG(INFO) << "Application construct";
    RegisterStates();
    mStateStack.PushState(StateID::Title);
}
Application::~Application()
{
    LOG(INFO) << "Application destruct";
}
void Application::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            ProcessInput();
            Update(TimePerFrame);

            if (mStateStack.IsEmpty()) {
                mWindow.close();
            }
        }
        Render();
    }
}
////////////////////////////////////////////////////
void Application::ProcessInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack.HandleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Application::Update(sf::Time dt)
{
	mStateStack.Update(dt);
}

void Application::Render()
{
	mWindow.clear();

	mStateStack.Draw();

	mWindow.setView(mWindow.getDefaultView());

	mWindow.display();
}
void Application::RegisterStates()
{
    LOG(INFO) << "RegisterStates";
    mStateStack.RegisterState<TitleState>(StateID::Title);
    mStateStack.RegisterState<MenuState>(StateID::Menu);
    mStateStack.RegisterState<GameState>(StateID::Game);
    mStateStack.RegisterState<PauseState>(StateID::Pause);
}