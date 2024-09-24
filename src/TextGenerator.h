#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"

#include "common_variable_8x16_sprite_font.h"

class TextGenerator
{
public:
    TextGenerator();
    ~TextGenerator();

    void Update();

    void SetTextAlignement(bn::sprite_text_generator::alignment_type aTextAlignement);

    void ClearText();
    void GenerateText(const int16_t aXPos, const int16_t aYPos, const bn::string<32> aText);

private:
    bn::sprite_text_generator SpriteTextGenerator;

    bn::vector<bn::sprite_ptr, 32> TextSprites;
};

#endif