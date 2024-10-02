#include "AlbumState.h"
#include "TextGenerator.h"
#include "StateHandler.h"
#include "MusicHandler.h"
#include "bn_sound_items.h"

AlbumState::AlbumState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler)
    : StateBase(aTextGenerator, aImageHandler, aMusicHandler)
{
    TextGeneratorPTR->SetTextAlignement(bn::sprite_text_generator::alignment_type::LEFT);
}

void AlbumState::Update()
{
    for (uint8_t Option = 0; Option < AlbumTexts.size(); ++Option)
    {
        if (Option != SelectedOption)
        {
            TextGeneratorPTR->GenerateText(-110, -60 + TextSeparation * Option, AlbumTexts[Option]);
        }
        else
        {
            TextGeneratorPTR->GenerateSelectedText(-100, -60 + TextSeparation * Option, AlbumTexts[Option], true);
        }
    }

    if (MusicHandlerPTR->GetIsPlaying())
    {
        TextGeneratorPTR->GenerateSelectedText(-120, -60 + TextSeparation * MusicHandlerPTR->GetCurrentSong(), ">");
    }

    if (MusicHandlerPTR->GetAutoPlayEnabled())
    {
        TextGeneratorPTR->GenerateSelectedText(70, -70, "AUTO");
    }
}

void AlbumState::Enter()
{
    MusicHandlerPTR->PlayBackground();
}

void AlbumState::Exit()
{
}

void AlbumState::Select()
{
    bn::sound_items::button.play();
    MusicHandlerPTR->PlaySong(SelectedOption);
}

void AlbumState::Back()
{
    if (MusicHandlerPTR->GetIsPlaying())
    {
        MusicHandlerPTR->StopMusic();
    }
    else
    {
        bn::sound_items::button.play();
        StateHandler::GetInstance().SetState(StateHandler::STATES::MENU);
    }
}

void AlbumState::MenuUp()
{
    if (!MusicHandlerPTR->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    SelectedOption = (SelectedOption + AlbumTexts.size() - 1) % AlbumTexts.size();
}

void AlbumState::MenuDown()
{
    if (!MusicHandlerPTR->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    SelectedOption = (SelectedOption + 1) % AlbumTexts.size();
}

void AlbumState::Auto()
{
    if (!MusicHandlerPTR->GetIsPlaying())
    {
        bn::sound_items::button.play();
    }
    MusicHandlerPTR->AutoPlay();
}