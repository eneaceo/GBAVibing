#ifndef StateManager_H
#define StateManager_H

#include "bn_vector.h"
#include <memory>

#include "State.h"

class StateManager
{
public:
    StateManager();

    void Update();
    void ChangeState(std::unique_ptr<State> aState);

private:
    std::unique_ptr<State> CurrentState;
};

#endif
