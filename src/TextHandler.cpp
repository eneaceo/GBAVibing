#include "TextHandler.h"
#include "bn_math.h"
#include "bn_sprite_items_variable_8x16_font_red.h"
#include "common_variable_8x16_sprite_font.h"

TextHandler::TextHandler()
    : TextGenerator(common::variable_8x16_sprite_font)
{
}

void TextHandler::Update()
{
    TextSprites.clear();
    SelectedTextSprites.clear();
}

void TextHandler::GenerateStaticText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText)
{
    TextGenerator.generate(aXPos, aYPos, aText, StaticTextSprites);
}

void TextHandler::GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText)
{
    TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
    TextGenerator.generate(aXPos, aYPos, aText, TextSprites);
}

void TextHandler::GenerateSelectedText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText)
{
    TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
    TextGenerator.set_one_sprite_per_character(true);
    TextGenerator.generate(aXPos, aYPos, aText, SelectedTextSprites);
    TextGenerator.set_one_sprite_per_character(false);
    TextWiggle(aXPos, aYPos);
}

void TextHandler::TextWiggle(const int16_t aXPos, const int16_t aYPos)
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

        SelectedTextSprite.set_y(aYPos + bn::degrees_lut_sin(LocalAngle) * 2);
    }
}