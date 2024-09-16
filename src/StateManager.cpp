#include "StateManager.h"

StateManager::StateManager()
{
    CurrentState = std::make_unique<MainMenuState>();
}

void StateManager::Update()
{
    CurrentState->Update();
}

void StateManager::ChangeState(std::unique_ptr<State> aState)
{
    if (CurrentState)
    {
        CurrentState->Exit();
    }
    aState->Enter();
    CurrentState = std::move(aState);
}
