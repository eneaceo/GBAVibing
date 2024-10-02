#include "MenuState.h"
#include "TextGenerator.h"
#include "StateHandler.h"
#include "MusicHandler.h"
#include "bn_sound_items.h"

MenuState::MenuState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler)
    : StateBase(aTextGenerator, aImageHandler, aMusicHandler)
{
    TextGeneratorPTR->SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
}

void MenuState::Update()
{
    for (uint8_t Option = 0; Option < MenuTexts.size(); ++Option)
    {
        if (Option == SelectedOption)
        {
            TextGeneratorPTR->GenerateSelectedText(0, TextSeparation * Option, MenuTexts[Option], true);
        }
        else
        {
            TextGeneratorPTR->GenerateText(0, TextSeparation * Option, MenuTexts[Option]);
        }
    }
}

void MenuState::Enter()
{
    MusicHandlerPTR->PlayBackground();
    TextGeneratorPTR->GenerateStaticText(0, -50, TextBandName);
    TextGeneratorPTR->GenerateStaticText(0, -40, TextAlbumName);
}

void MenuState::Exit()
{
    TextGeneratorPTR->ClearText();
}

void MenuState::Select()
{
    bn::sound_items::button.play();
    if (SelectedOption == 0)
    {
        StateHandler::GetInstance().SetState(StateHandler::STATES::ALBUM);
    }
    else
    {
        StateHandler::GetInstance().SetState(StateHandler::STATES::CREDITS);
    }
}

void MenuState::MenuUp()
{
    bn::sound_items::button.play();
    SelectedOption = 1 - SelectedOption;
}

void MenuState::MenuDown()
{
    bn::sound_items::button.play();
    SelectedOption = 1 - SelectedOption;
}