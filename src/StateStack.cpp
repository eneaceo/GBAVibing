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
    // TODO Think about a reference to the current state just for this
    StatesStack.back().get()->Update();
    InputManager->HandleInput(*this);
}

void StateStack::AdvanceState()
{
    switch (StatesStack.back().get()->GetStateInfo())
    {
    case State::STATES::MAINMENU:
    {
        if (StatesStack.back().get()->GetSelectedOption() == 0)
        {
            Push(std::make_unique<AlbumMenuState>());
        }
        else
        {
            Push(std::make_unique<CreditsState>());
        }
        break;
    }
    case State::STATES::ALBUMMENU:
        Push(std::make_unique<PlayingSongState>());
        break;
    }
}

void StateStack::MenuUp()
{
    uint8_t StateInfo = StatesStack.back().get()->GetStateInfo()
    if (StateInfo == State::STATES::MAINMENU || StateInfo == State::STATES::ALBUMMENU)
    {
        StatesStack.back().get()->ChangeSelectedOption(true);
    }
}

void StateStack::MenuDown()
{
    uint8_t StateInfo = StatesStack.back().get()->GetStateInfo()
    if (StateInfo == State::STATES::MAINMENU || StateInfo == State::STATES::ALBUMMENU)
    {
        StatesStack.back().get()->ChangeSelectedOption(false);
    }
}

void StateStack::PreviousState()
{
    State* CurrentState = StatesStack.back().get();
    if (CurrentState && CurrentState->GetState() != State::STATES::MAINMENU)
    {
        Pop();
    }
}

void StateStack::Push(std::unique_ptr<State> aState)
{
    State *CurrentState = StatesStack.back().get();
    if (CurrentState)
    {
        CurrentState->Exit();
    }
    StatesStack.push_back(std::move(aState));
    StatesStack.back().get()->Enter();
}

void StateStack::Pop()
{
    if (StatesStack.size() > 1)
    {
        State *CurrentState = StatesStack.back().get();
        if (CurrentState)
        {
            CurrentState->Exit();
            StatesStack.pop_back();
            StatesStack.back().get()->Enter();
        }
    }
}
