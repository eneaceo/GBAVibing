#include "bn_core.h"

#include "bn_string.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_unordered_map.h"

#include "common_variable_8x8_sprite_font.h"

namespace
{
    

}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(6, 25, 6));

    bn::vector<bn::sprite_ptr, 16> TextSprites;
    bn::string<128> Text = " ";
    bn::sprite_text_generator TextGenerator(common::variable_8x8_sprite_font);

    while(true)
    {
        TextSprites.clear();
        Text = "Music";
        TextGenerator.generate(-6 * 16, -68, Text, TextSprites);
        bn::core::update();
    }
}



