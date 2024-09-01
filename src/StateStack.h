#ifndef STATESTACK_H
#define STATESTACK_H

#include "bn_vector.h"
#include <memory>

#include "Actor.h"
#include "State.h"
#include "InputHandler.h"

class StateStack : public Actor
{
public:
    StateStack();

    void Update() override;
    void AdvanceState();
    void PreviousState();
    State* GetCurrentState() { return CurrentState;};

private:
    std::unique_ptr<InputHandler> InputManager;
    bn::vector<std::unique_ptr<State>, 3> StatesStack;
    State *CurrentState = nullptr;

    void Push(std::unique_ptr<State> aState);
    void Pop();
};

#endif
