#ifndef STATESTACK_H
#define STATESTACK_H

#include "bn_vector.h"
#include <memory>

#include "State.h"
#include "InputHandler.h"

class StateStack
{
public:
    StateStack();

    void Update();
    void AdvanceState();
    void PreviousState();
    void MenuUp();
    void MenuDown();

private:
    std::unique_ptr<InputHandler> InputManager;
    bn::vector<std::unique_ptr<State>, 3> StatesStack;

    void Push(std::unique_ptr<State> aState);
    void Pop();
};

#endif
