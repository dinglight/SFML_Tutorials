#ifndef _TITLE_STATE_H_
#define _TITLE_STATE_H_

#include "State.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleState : public State {
public:
    TitleState(StateStack& stack, Context context);

    virtual bool HandleEvent(const sf::Event& event) override;
    virtual bool Update(sf::Time dt) override;
    virtual void Draw() override;
private:
    sf::Sprite mBackgroundSprite;
    sf::Text mText;

    bool mShowText;
    sf::Time mTextEffectTime;
};

#endif // _TITLE_STATE_H_