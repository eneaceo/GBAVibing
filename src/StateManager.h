#ifndef StateManager_H
#define StateManager_H

#include "bn_unique_ptr.h"

class State;

class StateManager
{
public:
    StateManager();

    void Update();
    void ChangeState(bn::unique_ptr<State> aState);

private:
    bn::unique_ptr<State> CurrentState;
};

#endif
