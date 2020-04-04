#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ResourceIdentifiers.h"
#include "StateStack.h"

class Application {
public:
    Application();
    ~Application();
    void Run();
private:
    void ProcessInput();
    void Update(sf::Time dt);
    void Render();

    void RegisterStates();
private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow mWindow;
    TextureHolder mTexturesHolder;
    FontHolder mFontHolder;
    StateStack mStateStack;
};

#endif // APPLICATION_H