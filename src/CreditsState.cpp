#include "CreditsState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "StateCommands.h"
#include "bn_regular_bg_items_background_0.h"

CreditsState::CreditsState()
{
    TextManager->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
    InputManager->BindButton(InputHandler::BUTTONS::B, bn::make_unique<BackCommand>());
    BackgroundManager->LoadBackground(bn::regular_bg_items::background_0);
}

void CreditsState::Update()
{
    BackgroundManager->Update();
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
    InputManager->HandleInput(*this);
}

void CreditsState::Enter(const bool aReset)
{
    TextManager->GenerateStaticText(0, -40, "Créditos");
    TextManager->GenerateStaticText(-60, -10, "Música");
    TextManager->GenerateStaticText(40, -10, "VVV -Trippin'you-");
    TextManager->GenerateStaticText(-60, 10, "Programación");
    TextManager->GenerateStaticText(40, 10, "MilleLire");
    TextManager->GenerateStaticText(0, 60, "2024");
}

void CreditsState::Exit()
{
    TextManager->ClearText();
}

void CreditsState::Back()
{
    StateManager::GetInstance().ChangeState(bn::make_unique<MainMenuState>());
}