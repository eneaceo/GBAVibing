#include "bn_core.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"

#include "TextGenerator.h"

namespace
{
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    TextGenerator CurrentTextGenerator = TextGenerator();
    CurrentTextGenerator.SetTextAlignement(bn::sprite_text_generator::alignment_type::CENTER);
    CurrentTextGenerator.GenerateText(0, 10, "Hello, World!");
    CurrentTextGenerator.GenerateText(0, 20, "Hello, World!");
    CurrentTextGenerator.GenerateText(0, 30, "Hello, World!");
    CurrentTextGenerator.GenerateText(0, 40, "Hello, World!");

    while (true)
    {
        
        bn::core::update();
    };
}
