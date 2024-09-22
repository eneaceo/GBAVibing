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
    BackgroundManager->Update();
    if (EnteringState)
    {
        if (!SoundHandler.get()->active())
        {
            EnteringState = false;
            TextManager->GenerateStaticText(0, -40, TextBandName);
            TextManager->GenerateStaticText(0, -30, TextAlbumName);
        }
    }
    else
    {
        if (!SoundHandler.get()->active())
        {
            SoundCounter++;
            if (SoundCounter == SoundTimer)
            {
                SoundCounter = 0;
                SoundTimer = Random.get_int(120, ConstAudioCounter);
                SoundHandler = bn::sound_items::loop.play(0.2);
            }
        }
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
}

void MainMenuState::Enter(const bool aReset)
{
    if (aReset)
    {
        SoundHandler = bn::sound_items::intro.play();
        EnteringState = true;
    }
    else
    {
        TextManager->GenerateStaticText(0, -40, TextBandName);
        TextManager->GenerateStaticText(0, -30, TextAlbumName);
    }
}

void MainMenuState::Exit()
{
    SoundHandler.get()->stop();
    TextManager->ClearText();
    BackgroundManager->ResetBackground();
}

void MainMenuState::Select()
{
    bn::sound_items::button.play();
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
    bn::sound_items::button.play();
    SelectedOption = 1 - SelectedOption;
}

void MainMenuState::MenuDown()
{
    bn::sound_items::button.play();
    SelectedOption = 1 - SelectedOption;
}