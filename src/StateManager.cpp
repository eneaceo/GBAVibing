#include "StateManager.h"
#include "core/State.h"
#include "states/MainMenuState.h"

StateManager::StateManager()
{
    CurrentState = bn::make_unique<MainMenuState>();
    CurrentState->Enter();
}

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
