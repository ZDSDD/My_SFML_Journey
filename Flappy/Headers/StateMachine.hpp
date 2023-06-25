#pragma once


#include "State.hpp"


typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
    StateMachine() = default;

    ~StateMachine() = default;

    void AddState(StateRef newState, bool isReplacing = true);

    void RemoveState();

    // Run at start of each loop in Game.cpp
    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving{};
    bool _isAdding{}, _isReplacing{};
};
