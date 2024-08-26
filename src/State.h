#ifndef STATE_H
#define STATE_H

class State
{
public:
    virtual ~State() = default;
    virtual void Update() {};
    virtual void Enter() {};
    virtual void Exit() {};
    bool IsActive() const
    {
        return ActiveState;
    };

protected:
    bool ActiveState = false;
};

class MainMenuState : public State
{
public:
    MainMenuState()
    {
        ActiveState = true;
    };
};

class AlbumMenuState : public State
{
public:
    AlbumMenuState()
    {
        ActiveState = true;
    };
};

#include "bn_vector.h"

class StateStack
{
public:
    StateStack() {};
    ~StateStack() {};
    void Push(State aState)
    {
        GetCurrentState().Exit();
        StatesStack.push_back(aState);
        CurrentState = aState;
        aState.Enter();
    };
    void Pop()
    {
        GetCurrentState().Exit();
        StatesStack.pop_back();
        CurrentState = GetCurrentState();
        CurrentState.Enter();
    };
    void Update()
    {
        CurrentState.Update();
    };

private:
    bn::vector<State, 3> StatesStack = bn::vector<State, 3>();
    State CurrentState;
    State GetCurrentState() const
    {
        State Ret;
        for (State StateIterator : StatesStack)
        {
            if (StateIterator.IsActive())
            {
                Ret = StateIterator;
            }
        }
        return Ret;
    };
};

#endif