#include "StateStack.h"
#include "StateCommands.h"

StateStack::StateStack()
{
    Push(std::make_unique<MainMenuState>());
    InputManager = std::make_unique<InputHandler>();
    InputManager->BindButton(InputHandler::BUTTONS::A, std::make_unique<NextStateCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::B, std::make_unique<PreviousStateCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::UP, std::make_unique<MenuUpCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::DOWN, std::make_unique<MenuDownCommand>());
}

void StateStack::Update()
{
    CurrentState->Update();
    InputManager->HandleInput(*this);
}

void StateStack::AdvanceState()
{
    if (CurrentState)
    {
        switch (CurrentState->GetState())
        {
        case State::STATES::MAINMENU:
            if (CurrentState->GetSelectedOption() == 0)
            {
                Push(std::make_unique<AlbumMenuState>());
            }
            else
            {
                Push(std::make_unique<CreditsState>());
            }
            break;
        case State::STATES::ALBUMMENU:
            Push(std::make_unique<PlayingSongState>());
            break;
        }
    }
}

void StateStack::PreviousState()
{
    if (CurrentState && CurrentState->GetState() != State::STATES::MAINMENU)
    {
        Pop();
    }
}

void StateStack::Push(std::unique_ptr<State> aState)
{
    if (CurrentState)
    {
        CurrentState->Exit();
    }
    StatesStack.push_back(std::move(aState));
    CurrentState = StatesStack.back().get();
    if (CurrentState)
    {
        CurrentState->Enter();
    }
}

void StateStack::Pop()
{
    if (StatesStack.size() > 1)
    {
        CurrentState->Exit();
        StatesStack.pop_back();
        CurrentState = StatesStack.back().get();
        CurrentState->Enter();
    }
}
