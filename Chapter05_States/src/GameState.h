#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "State.h"
#include <SFML/Graphics/Sprite.hpp>

class GameState : public State {
public:
    GameState(StateStack& stack, Context context);

    virtual bool HandleEvent(const sf::Event& event) override;
    virtual bool Update(sf::Time dt) override;
    virtual void Draw() override;

private:
    sf::Sprite mPlayer;
    sf::Vector2f mPlayerSpeed;

};

#endif // _GAME_STATE_H_