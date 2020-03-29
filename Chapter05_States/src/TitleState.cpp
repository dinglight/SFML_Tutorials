#include "TitleState.h"

#include <cmath>

#include "ResourceHolder.h"
#include "Logger.h"

TitleState::TitleState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite()
, mText()
, mShowText(true)
, mTextEffectTime(sf::Time::Zero)
{
    Logger::WriteLog("TitleState construct");
    mBackgroundSprite.setTexture(context.textureHolder->Get(TextureID::TitleScreen));

    mText.setFont(context.fontHolder->Get(FontID::Main));
    mText.setString("Please press any key to start");
    sf::FloatRect bounds = mText.getLocalBounds();
    mText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    mText.setPosition(context.window->getView().getSize() / 2.f);
}

bool TitleState::HandleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        RequestStatePop();
    }
    return true;
}

bool TitleState::Update(sf::Time dt)
{
    mTextEffectTime += dt;
    if (mTextEffectTime >= sf::seconds(0.5f)) {
        mShowText = !mShowText;
        mTextEffectTime = sf::Time::Zero;
    }
    return true;
}

void TitleState::Draw()
{
    sf::RenderWindow& window = *(GetContext().window);
    window.draw(mBackgroundSprite);
    if (mShowText) {
        window.draw(mText);
    }
}
