#include "CreditsState.h"
#include "StateHandler.h"
#include "TextGenerator.h"
#include "MusicHandler.h"
#include "bn_sound_items.h"

CreditsState::CreditsState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler)
    : StateBase(aTextGenerator, aImageHandler, aMusicHandler)
{
    TextGeneratorPTR->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
}

void CreditsState::Update()
{
}

void CreditsState::Enter()
{
    MusicHandlerPTR->PlayBackground();
    TextGeneratorPTR->GenerateStaticText(0, -8, TextCredits01);
    TextGeneratorPTR->GenerateStaticText(0, 8, TextCredits02);
}

void CreditsState::Exit()
{
    TextGeneratorPTR->ClearText();
}

void CreditsState::Back()
{
    bn::sound_items::button.play();
    StateHandler::GetInstance().SetState(StateHandler::STATES::MENU);
}