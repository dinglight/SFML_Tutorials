#include "MenuState.h"
#include <cmath>
#include "Logger.h"
MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite()
, mTexts()
, mSelectedTextIndex(0)
{
    LOG(INFO) << "MenuState construct";
    sf::Texture& texture = context.textureHolder->Get(TextureID::MenuScreen);
    mBackgroundSprite.setTexture(texture);

    sf::Font& font = context.fontHolder->Get(FontID::Main);

    sf::Text playText;
    playText.setFont(font);
    playText.setString("Play");
    sf::FloatRect bounds = playText.getLocalBounds();
    playText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    playText.setPosition(context.window->getView().getSize() / 2.f);
    mTexts.emplace_back(playText);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    bounds = exitText.getLocalBounds();
    exitText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    exitText.setPosition(playText.getPosition() + sf::Vector2f(0.f, 30.f));
    mTexts.emplace_back(exitText);
    UpdateSelectedText();
}

bool MenuState::HandleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }

    if (event.key.code == sf::Keyboard::Return) {
        if (mSelectedTextIndex == 0) {
            
        } else if (mSelectedTextIndex == 1) {
            RequestStatePop();
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

bool MenuState::Update(sf::Time dt)
{
    return true;
}

void MenuState::Draw()
{
    sf::RenderWindow& window = *(GetContext().window);
    window.draw(mBackgroundSprite);
    for (auto& text: mTexts) {
        window.draw(text);
    }
}

void MenuState::UpdateSelectedText()
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