#ifndef _STATE_H_
#define _STATE_H_

#include <memory>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

class StateStack;

class State {
public:
    //typedef std::unique_ptr<State> Ptr;
    using Ptr = std::unique_ptr<State>;

    struct Context {
        sf::RenderWindow* window;
        TextureHolder* textureHolder;
        FontHolder* fontHolder;
        Context(sf::RenderWindow& window, TextureHolder& texture, FontHolder& font);
    };
public:
    State(StateStack& stack, Context context);
    virtual ~State();

    virtual bool HandleEvent(const sf::Event& event) = 0;
    virtual bool Update(sf::Time dt) = 0;
    virtual void Draw() = 0;
protected:
    void RequestStatePush(StateID stateID);
    void RequestStatePop();
    void RequestStateClear();

    Context GetContext() const;
private:
    StateStack* mStack;
    Context mContext;
};
#endif // _STATE_H_
