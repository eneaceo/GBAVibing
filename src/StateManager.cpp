#include "StateManager.h"
#include "MainMenuState.h"

void StateManager::Update()
{
    CurrentState->Update();
}

void StateManager::ChangeState(bn::unique_ptr<State> aState)
{
    if (CurrentState)
    {
        CurrentState->Exit();
    }
    CurrentState = bn::move(aState);
    CurrentState->Enter();
}
