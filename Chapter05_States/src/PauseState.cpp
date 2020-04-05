#include "PauseState.h"
#include <cmath>
#include "Logger.h"
PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundShape()
, mTexts()
, mSelectedTextIndex(0)
{
    LOG(INFO) << "PauseState construct";
    sf::Vector2f viewSize = context.window->getView().getSize();
    mBackgroundShape.setFillColor(sf::Color(0,150,0,150));
    mBackgroundShape.setSize(viewSize);

    sf::Font& font = context.fontHolder->Get(FontID::Main);

    sf::Text playText;
    playText.setFont(font);
    playText.setString("Resume");
    sf::FloatRect bounds = playText.getLocalBounds();
    playText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    playText.setPosition(context.window->getView().getSize() / 2.f);
    mTexts.emplace_back(playText);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString("Menu");
    bounds = exitText.getLocalBounds();
    exitText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    exitText.setPosition(playText.getPosition() + sf::Vector2f(0.f, 30.f));
    mTexts.emplace_back(exitText);
    UpdateSelectedText();
}

bool PauseState::HandleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }

    if (event.key.code == sf::Keyboard::Return) {
        if (mSelectedTextIndex == 0) {
            RequestStatePop();
        } else if (mSelectedTextIndex == 1) {
            RequestStateClear();
            RequestStatePush(StateID::Menu);
        }
    } else if (event.key.code == sf::Keyboard::Up) {
        mSelectedTextIndex = (mSelectedTextIndex - 1) % mTexts.size();
        UpdateSelectedText();
    } else if (event.key.code == sf::Keyboard::Down) {
        mSelectedTextIndex = (mSelectedTextIndex + 1) % mTexts.size();
        UpdateSelectedText();
    }

    return true;
}

bool PauseState::Update(sf::Time dt)
{
    return true;
}

void PauseState::Draw()
{
    sf::RenderWindow& window = *(GetContext().window);

    window.draw(mBackgroundShape);
    for (auto& text: mTexts) {
        window.draw(text);
    }
}

void PauseState::UpdateSelectedText()
{
    if (mTexts.empty()) {
        return;
    }
    for (std::size_t i = 0; i < mTexts.size(); ++i) {
        if (mSelectedTextIndex == i) {
            mTexts[i].setFillColor(sf::Color::Red);
        } else {
            mTexts[i].setFillColor(sf::Color::White);
        }
    }
}