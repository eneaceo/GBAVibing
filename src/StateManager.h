#ifndef StateManager_H
#define StateManager_H

#include "bn_unique_ptr.h"

class State;

class StateManager
{
public:
    static StateManager &GetInstance()
    {
        static StateManager Instance;
        return Instance;
    }

    StateManager(const StateManager &) = delete;
    StateManager &operator=(const StateManager &) = delete;

    void Update();
    void ChangeState(bn::unique_ptr<State> aState);

private:
    StateManager() = default;
    // TODO Change this to object, no need for pointers
    bn::unique_ptr<State> CurrentState;
};

#endif
