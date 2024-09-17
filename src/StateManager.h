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

    bn::unique_ptr<State> CurrentState;
};

#endif
