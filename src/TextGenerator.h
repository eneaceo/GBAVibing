#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"

class TextGenerator
{
public:
    TextGenerator();
    ~TextGenerator();

    void Update();

    void SetTextAlignement(bn::sprite_text_generator::alignment_type aTextAlignement);

    void ClearText();
    void GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText, const bool aTextWiggle = false);
    void GenerateStaticText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText);
    void GenerateSelectedText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText, const bool aTextWiggle = false);

private:
    bn::sprite_text_generator SpriteTextGenerator;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> StaticTextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;

    void TextWiggle(const int16_t aYPos, bn::vector<bn::sprite_ptr, 32> aTextSprites);

    bn::fixed Angle = 360;
    const bn::fixed AngleIncrement = 4;
};

#endif