#ifndef _PAUSE_STATE_H_
#define _PAUSE_STATE_H_

#include "State.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>

class PauseState : public State {
public:
    PauseState(StateStack& stack, Context context);

    virtual bool HandleEvent(const sf::Event& event) override;
    virtual bool Update(sf::Time dt) override;
    virtual void Draw() override;
private:
    void UpdateSelectedText();
private:
    sf::RectangleShape mBackgroundShape;
    std::vector<sf::Text> mTexts;
    std::size_t mSelectedTextIndex;
};

#endif // _MENU_STATE_H_