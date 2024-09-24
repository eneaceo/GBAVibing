#include "TextGenerator.h"

TextGenerator::TextGenerator()
    : SpriteTextGenerator(common::variable_8x16_sprite_font)
{
}

TextGenerator::~TextGenerator()
{
}

void TextGenerator::Update()
{
}

void TextGenerator::ClearText()
{
    TextSprites.clear();
}

void TextGenerator::GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText)
{
    SpriteTextGenerator.generate(aXPos, aYPos, aText, TextSprites);
}

void TextGenerator::SetTextAlignement(bn::sprite_text_generator::alignment_type aTextAlignement)
{
    SpriteTextGenerator.set_alignment(aTextAlignement);
}