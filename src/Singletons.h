#ifndef SINGLETONS_H
#define SINGLETONS_H

// Texts includes
#include "bn_sprite_text_generator.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_variable_8x16_font_red.h"

namespace Singletons
{
    // Texts generator
    inline bn::sprite_text_generator TextGenerator(common::variable_8x16_sprite_font);

}

#endif