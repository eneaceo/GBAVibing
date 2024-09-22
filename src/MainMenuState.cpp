#include "MainMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"
#include "CreditsState.h"
#include "AlbumMenuState.h"

#include "bn_regular_bg_items_background_0.h"

MainMenuState::MainMenuState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
    InputManager->BindButton(InputHandler::BUTTONS::A, bn::make_unique<SelectCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::UP, bn::make_unique<MenuUpCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::DOWN, bn::make_unique<MenuDownCommand>());
    BackgroundManager->LoadBackground(bn::regular_bg_items::background_0);
}

void MainMenuState::Update()
{
    if (EnteringState)
    {
        if (!SoundHandler.get()->active())
        {
            BackgroundManager->SetAnimationSpeed(120);
            EnteringState = false;
        }
    }
    else
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
    BackgroundManager->Update();
}

void MainMenuState::Enter(const bool aReset)
{
    if (aReset)
    {
        BackgroundManager->SetAnimationSpeed(5);
        EnteringState = true;
        SoundHandler = bn::sound_items::intro.play();
    }
    else
    {
        TextManager->GenerateStaticText(0, -40, TextBandName);
        TextManager->GenerateStaticText(0, -30, TextAlbumName);
    }
}

void MainMenuState::Exit()
{
    TextManager->ClearText();
    BackgroundManager->ResetBackground();
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