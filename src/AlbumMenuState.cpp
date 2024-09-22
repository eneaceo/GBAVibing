#include "AlbumMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"
#include "MainMenuState.h"

#include "bn_regular_bg_items_background_0.h"

AlbumMenuState::AlbumMenuState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::LEFT);
    InputManager->BindButton(InputHandler::BUTTONS::A, bn::make_unique<SelectCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::B, bn::make_unique<BackCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::UP, bn::make_unique<MenuUpCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::DOWN, bn::make_unique<MenuDownCommand>());
    InputManager->BindButton(InputHandler::BUTTONS::START, bn::make_unique<AutoCommand>());
    MusicManager = bn::make_unique<MusicHandler>();
    MusicManager->Attach(this);
    BackgroundManager->LoadBackground(bn::regular_bg_items::background_0);
}

void AlbumMenuState::Update()
{
    BackgroundManager->Update();
    MusicManager->Update();
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

void AlbumMenuState::Enter(const bool aReset)
{
}

void AlbumMenuState::Exit()
{
    TextManager->ClearText();
    BackgroundManager->ResetBackground();
}

void AlbumMenuState::Select()
{
    bn::sound_items::button.play();
    MusicManager->PlayMusic(SelectedOption);
}

void AlbumMenuState::Back()
{
    bn::sound_items::button.play();
    if (MusicManager->GetIsPlaying())
    {
        MusicManager->StopMusic();
    }
    else
    {
        StateManager::GetInstance().ChangeState(bn::make_unique<MainMenuState>());
    }
}

void AlbumMenuState::MenuUp()
{
    if (!MusicManager->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    SelectedOption = (SelectedOption + AlbumTexts.size() - 1) % AlbumTexts.size();
}

void AlbumMenuState::MenuDown()
{
    if (!MusicManager->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    SelectedOption = (SelectedOption + 1) % AlbumTexts.size();
}

void AlbumMenuState::Auto()
{
    if (!MusicManager->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    MusicManager->AutoPlay();
}

void AlbumMenuState::UpdateSelectedOption()
{
    SelectedOption = MusicManager->GetCurrentSong();
}

void AlbumMenuState::UpdateAutoPlay()
{
    TextManager->ClearStaticText();
    if (MusicManager->GetAutoPlayEnabled())
    {
        TextManager->GenerateStaticText(80, -70, "AUTO");
    }
}