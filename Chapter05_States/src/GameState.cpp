#include "GameState.h"

#include "SFML/Graphics/Texture.hpp"
#include <cmath>

#include "Logger.h"

GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mPlayer()
, mPlayerSpeed(100.f, 100.f)
{
    LOG(INFO) << "GameState construct";
    TextureHolder& textureHolder = *(context.textureHolder);
    textureHolder.Load(TextureID::Eagle, "res/textures/Eagle.png");
    LOG(INFO) << "load texture successful";

    sf::Texture& texture = context.textureHolder->Get(TextureID::Eagle);
    mPlayer.setTexture(texture);
    LOG(INFO) << "set texture";

    sf::FloatRect bounds = mPlayer.getLocalBounds();
    LOG(INFO) << "player local bounds : " << "width:" << bounds.width <<" height:" << bounds.height;

    mPlayer.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

bool GameState::HandleEvent(const sf::Event& event)
{
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }

    if (event.key.code == sf::Keyboard::Escape) {
        RequestStatePush(StateID::Pause);
    }
    return true;
}
bool GameState::Update(sf::Time dt)
{
    sf::FloatRect spriteBounds = mPlayer.getLocalBounds();
    sf::Vector2f spritePosition = mPlayer.getPosition();
    sf::RenderWindow& window = *(GetContext().window);
    sf::Vector2u windowSize = window.getSize();

    if (((spritePosition.x + spriteBounds.width/2.f > windowSize.x) && mPlayerSpeed.x > 0)
    || ((spritePosition.x - spriteBounds.width/2.f < 0) && mPlayerSpeed.x < 0)) {
        mPlayerSpeed.x = - mPlayerSpeed.x;
    }
    if (((spritePosition.y + spriteBounds.height/2.f > windowSize.y) && mPlayerSpeed.y > 0)
    || ((spritePosition.y - spriteBounds.height/2.f < 0) && mPlayerSpeed.y < 0)) {
        mPlayerSpeed.y = - mPlayerSpeed.y;
    }

    mPlayer.setPosition(spritePosition + mPlayerSpeed * dt.asSeconds());
    return true;
}
void GameState::Draw()
{
    sf::RenderWindow& window = *(GetContext().window);
    window.draw(mPlayer);
}