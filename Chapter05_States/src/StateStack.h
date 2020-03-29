#ifndef _STATE_STACK_H_
#define _STATE_STACK_H_

#include <functional>
#include <utility>
#include <unordered_map>
#include <vector>

#include <SFML/System/Time.hpp>

#include "State.h"

namespace sf {
    class Event;
}

class StateStack {
public:
    enum class Action {
        Push,
        Pop,
        Clear
    };
public:
    explicit StateStack(State::Context context);
    ~StateStack();
    template<typename T>
    void RegisterState(StateID stateID);

    void HandleEvent(const sf::Event& event);
    void Update(sf::Time dt);
    void Draw();

    void PushState(StateID stateID);
    void PopState();
    void ClearStates();

    bool IsEmpty() const;
private:
    StateStack();
    StateStack(const StateStack&);
    StateStack& operator=(const StateStack&);
private:
    struct PendingChange {
        explicit PendingChange(Action action, StateID stateID = StateID::None);
        Action action;
        StateID stateID;
    };
    State::Ptr CreateState(StateID stateID);
    void ApplyPendingChanges();
private:
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;
    State::Context mContext;
    std::unordered_map<StateID, std::function<State::Ptr()>> mFactories;

};

template<typename T>
void StateStack::RegisterState(StateID stateID)
{
    mFactories[stateID] = [this] ()
    {
        return State::Ptr(new T(*this, mContext));
    };
}

#endif // _STATE_STACK_H_