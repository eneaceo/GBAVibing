#include "MainMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"
#include "CreditsState.h"
#include "AlbumMenuState.h"

MainMenuState::MainMenuState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
    InputManager->BindButton(InputHandler::BUTTONS::A, bn::make_unique<SelectCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::UP, bn::make_unique<MenuUpCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::DOWN, bn::make_unique<MenuDownCommand>());
}

void MainMenuState::Update()
{
    TextManager->Update();
    for (uint8_t Option = 0; Option < MenuTexts.size(); ++Option)
    {
        if (Option != SelectedOption)
        {
            TextManager->GenerateText(0, TextSeparation * Option, MenuTexts[Option]);
        }
        else
        {
            TextManager->GenerateSelectedText(0, TextSeparation * Option, MenuTexts[Option]);
        }
    }
    InputManager->HandleInput(*this);
}

void MainMenuState::Enter()
{
    TextManager->GenerateStaticText(0, -40, TextBandName);
    TextManager->GenerateStaticText(0, -30, TextAlbumName);
}

void MainMenuState::Exit()
{
    TextManager->ClearText();
}

void MainMenuState::Select()
{
    switch (SelectedOption)
    {
    case 0:
        StateManager::GetInstance().ChangeState(bn::make_unique<AlbumMenuState>());
        break;
    case 1:
        StateManager::GetInstance().ChangeState(bn::make_unique<CreditsState>());
        break;
    default:
        break;
    }
}

void MainMenuState::MenuUp()
{
    SelectedOption = 1 - SelectedOption;
}

void MainMenuState::MenuDown()
{
    SelectedOption = 1 - SelectedOption;
}