#include "TextGenerator.h"
#include "bn_math.h"

#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_variable_8x16_font_red.h"

TextGenerator::TextGenerator()
    : SpriteTextGenerator(common::variable_8x16_sprite_font)
{
}

TextGenerator::~TextGenerator()
{
    ClearText();
}

void TextGenerator::Update()
{
    TextSprites.clear();
    SelectedTextSprites.clear();   
}

void TextGenerator::ClearText()
{
    TextSprites.clear();
    SelectedTextSprites.clear();
    StaticTextSprites.clear();
}

void TextGenerator::GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText, const bool aTextWiggle)
{
    if (aTextWiggle)
    {
        SpriteTextGenerator.set_one_sprite_per_character(true);
        SpriteTextGenerator.generate(aXPos, aYPos, aText, TextSprites);
        SpriteTextGenerator.set_one_sprite_per_character(false);
        TextWiggle(aYPos, TextSprites);
    }
    else
    {
        SpriteTextGenerator.generate(aXPos, aYPos, aText, TextSprites);
    }
}

void TextGenerator::GenerateStaticText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText)
{
    SpriteTextGenerator.generate(aXPos, aYPos, aText, StaticTextSprites);
}

void TextGenerator::GenerateSelectedText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText, const bool aTextWiggle)
{
    SpriteTextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
    if (aTextWiggle)
    {
        SpriteTextGenerator.set_one_sprite_per_character(true);
        SpriteTextGenerator.generate(aXPos, aYPos, aText, SelectedTextSprites);
        SpriteTextGenerator.set_one_sprite_per_character(false);
        TextWiggle(aYPos, SelectedTextSprites);
    }
    else
    {
        SpriteTextGenerator.generate(aXPos, aYPos, aText, SelectedTextSprites);
    }
    SpriteTextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
}

void TextGenerator::TextWiggle(const int16_t aYPos, bn::vector<bn::sprite_ptr, 32> aTextSprites)
{
    Angle -= AngleIncrement;

    if (Angle == 0)
    {
        Angle += 360;
    }

    bn::fixed LocalAngle = Angle;

    for (bn::sprite_ptr &Sprite : aTextSprites)
    {
        LocalAngle += AngleIncrement * 4;

        if (LocalAngle >= 360)
        {
            LocalAngle -= 360;
        }

        Sprite.set_y(aYPos + bn::degrees_lut_sin(LocalAngle) * 2);
    }
}

void TextGenerator::SetTextAlignement(bn::sprite_text_generator::alignment_type aTextAlignement)
{
    SpriteTextGenerator.set_alignment(aTextAlignement);
}