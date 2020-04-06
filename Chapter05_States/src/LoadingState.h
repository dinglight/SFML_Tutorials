#ifndef _LOADING_STATE_H_
#define _LOADING_STATE_H_

#include "State.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ParallelTask.h"
#include "LoadingTask.h"

class LoadingState : public State {
public:
    LoadingState(StateStack& stack, Context context);

    virtual bool HandleEvent(const sf::Event& event) override;
    virtual bool Update(sf::Time dt) override;
    virtual void Draw() override;
private:
    void SetCompletion(float percent);
private:
    sf::Text mLoadingText;
    sf::RectangleShape mProgressBarBackground;
    sf::RectangleShape mProgressBar;

    //ParallelTask mLoadingTask;
    LoadingTask mLoadingTask;
};

#endif // _LOADING_STATE_H_