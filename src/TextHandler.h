#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"

class TextHandler
{
public:
    TextHandler();
    ~TextHandler();

    void Update();
    void GenerateStaticText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText);
    void GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText);
    void GenerateSelectedText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText);
    void ClearText();
    void ClearStaticText();
    void TextWiggle(const int16_t aXPos, const int16_t aYPos);
    void SetTextAlignement(bn::sprite_text_generator::alignment_type aTextAlignement);

private:
    bn::sprite_text_generator TextGenerator;
    bn::vector<bn::sprite_ptr, 32> StaticTextSprites;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;
    bn::fixed Angle = 360;
    const bn::fixed AngleIncrement = 4;
};

#endif