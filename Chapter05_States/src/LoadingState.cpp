#include "LoadingState.h"
#include <cmath>
#include "Logger.h"
LoadingState::LoadingState(StateStack& stack, Context context)
: State(stack, context)
, mLoadingText()
, mProgressBarBackground()
, mProgressBar()
{
    LOG(INFO) << "LoadingState construct";
    sf::RenderWindow& window = *(context.window);
    sf::Vector2f viewSize = window.getView().getSize();
    sf::Font& font = context.fontHolder->Get(FontID::Main);

    mLoadingText.setFont(font);
    mLoadingText.setString("Loading Resources");
    sf::FloatRect bounds = mLoadingText.getLocalBounds();
    mLoadingText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    mLoadingText.setPosition(sf::Vector2f(viewSize.x/2.f, viewSize.y/2.f+50.f));

    mProgressBarBackground.setFillColor(sf::Color::White);
    mProgressBarBackground.setSize(sf::Vector2f(viewSize.x - 20, 10));
    mProgressBarBackground.setPosition(10, viewSize.y-40);

    mProgressBar.setFillColor(sf::Color(100, 100, 100));
    mProgressBar.setSize(sf::Vector2f(200,10));
    mProgressBar.setPosition(10, viewSize.y - 40);

    SetCompletion(0.f);

    mLoadingTask.Execute();
}

bool LoadingState::HandleEvent(const sf::Event& event)
{
    return true;
}

bool LoadingState::Update(sf::Time dt)
{
    if (mLoadingTask.IsFinished()) {
        RequestStatePop();
        RequestStatePush(StateID::Game);
    } else {
        SetCompletion(mLoadingTask.GetCompletion());
    }
    return true;
}

void LoadingState::Draw()
{
    sf::RenderWindow& window = *(GetContext().window);
    window.draw(mLoadingText);
    window.draw(mProgressBarBackground);
    window.draw(mProgressBar);
}

void LoadingState::SetCompletion(float percent)
{
    if (percent > 1.f) {
        percent = 1.f;
    }
    mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));
}