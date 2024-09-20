#include "CreditsState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"

CreditsState::CreditsState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
    InputManager->BindButton(InputHandler::BUTTONS::B, bn::make_unique<BackCommand>());
}

void CreditsState::Update()
{
    InputManager->HandleInput(*this);
}

void CreditsState::Enter(const bool aReset)
{
}

void CreditsState::Exit()
{
    TextManager->ClearText();
}

void CreditsState::Back()
{
    StateManager::GetInstance().ChangeState(bn::make_unique<MainMenuState>());
}