#include "AlbumMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"
#include "MainMenuState.h"

AlbumMenuState::AlbumMenuState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::LEFT);
    InputManager->BindButton(InputHandler::BUTTONS::A, bn::make_unique<SelectCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::B, bn::make_unique<BackCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::UP, bn::make_unique<MenuUpCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::DOWN, bn::make_unique<MenuDownCommand>());
}

void AlbumMenuState::Update()
{
    TextManager->Update();
    for (uint8_t Option = 0; Option < AlbumTexts.size(); ++Option)
    {
        if (Option != SelectedOption)
        {
            TextManager->GenerateText(-100, -60 + TextSeparation * Option, AlbumTexts[Option]);
        }
        else
        {
            TextManager->GenerateSelectedText(-80, -60 + TextSeparation * Option, AlbumTexts[Option]);
        }
    }
    InputManager->HandleInput(*this);
}

void AlbumMenuState::Enter()
{
}

void AlbumMenuState::Exit()
{
    TextManager->ClearText();
}

void AlbumMenuState::Select()
{
}

void AlbumMenuState::Back()
{
    StateManager::GetInstance().ChangeState(bn::make_unique<MainMenuState>());
}

void AlbumMenuState::MenuUp()
{
    SelectedOption = (SelectedOption + AlbumTexts.size() - 1) % AlbumTexts.size();
}

void AlbumMenuState::MenuDown()
{
    SelectedOption = (SelectedOption + 1) % AlbumTexts.size();
}