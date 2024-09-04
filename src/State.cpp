#include "State.h"
#include "bn_sprite_items_variable_8x16_font_red.h"
#include "bn_regular_bg_items_background.h"

#include "bn_math.h"

void MenuState::TextWiggle(const uint8_t aSelectedOption, const int8_t aPositionOffset)
{
    Angle -= AngleIncrement;

    if (Angle == 0)
    {
        Angle += 360;
    }

    bn::fixed LocalAngle = Angle;

    for (bn::sprite_ptr &SelectedTextSprite : SelectedTextSprites)
    {
        LocalAngle += AngleIncrement * 4;

        if (LocalAngle >= 360)
        {
            LocalAngle -= 360;
        }

        SelectedTextSprite.set_y(aPositionOffset + aSelectedOption * TextSeparation + bn::degrees_lut_sin(LocalAngle) * 2);
    }
}

MainMenuState::MainMenuState()
    : MenuState()
{
    TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);
    ImageOptional = bn::regular_bg_items::background.create_bg(0, 0);
}

void MainMenuState::Update()
{
    TextSprites.clear();
    SelectedTextSprites.clear();

    TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
    TextGenerator.generate(0, -40, TextBandName, TextSprites);
    TextGenerator.generate(0, -30, TextAlbumName, TextSprites);

    SelectedText(SelectedOption);
    TextWiggle(SelectedOption);
}

void MainMenuState::SelectedText(const uint8_t aSelectedOption)
{
    for (uint8_t Option = 0; Option < MenuTexts.size(); ++Option)
    {
        if (Option != aSelectedOption)
        {
            TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
            TextGenerator.generate(0, TextSeparation * Option, MenuTexts[Option], TextSprites);
        }
        else
        {
            TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
            TextGenerator.set_one_sprite_per_character(true);
            TextGenerator.generate(0, TextSeparation * Option, MenuTexts[Option], SelectedTextSprites);
            TextGenerator.set_one_sprite_per_character(false);
        }
    }
}

void MainMenuState::ChangeSelectedOption(bool aChangeSelectedOption)
{
    SelectedOption = 1 - SelectedOption;
}

void MainMenuState::Exit()
{
    TextSprites.clear();
    SelectedTextSprites.clear();
}

AlbumMenuState::AlbumMenuState()
    : MenuState()
{
    TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);
    ImageOptional = bn::regular_bg_items::background.create_bg(0, 0);
}

void AlbumMenuState::Update()
{
    TextSprites.clear();
    SelectedTextSprites.clear();
    SelectedText(SelectedOption);
    TextWiggle(SelectedOption, -60);
}

void AlbumMenuState::SelectedText(const uint8_t aSelectedOption)
{
    for (uint8_t Option = 0; Option < AlbumTexts.size(); ++Option)
    {
        if (Option != aSelectedOption)
        {
            TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
            TextGenerator.generate(-100, -60 + TextSeparation * Option, AlbumTexts[Option], TextSprites);
        }
        else
        {
            TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
            TextGenerator.set_one_sprite_per_character(true);
            TextGenerator.generate(-80, -60 + TextSeparation * Option, AlbumTexts[Option], SelectedTextSprites);
            TextGenerator.set_one_sprite_per_character(false);
        }
    }
}

void AlbumMenuState::ChangeSelectedOption(bool aChangeSelectedOption)
{
    if (aChangeSelectedOption)
    {
        SelectedOption = (SelectedOption + AlbumTexts.size() - 1) % AlbumTexts.size();
    }
    else
    {
        SelectedOption = (SelectedOption + 1) % AlbumTexts.size();
    }
}

void AlbumMenuState::Exit()
{
    TextSprites.clear();
    SelectedTextSprites.clear();
}

void PlayingSongState::Update()
{
    if (!SoundHandler.get()->active())
    {
        AudioCounter++;
        if (AudioCounter <= 15)
        {
            SoundHandler = AudioItems[AudioCounter].play();
        }
        else
        {
            SoundHandler.get()->stop();
        }
    }
}