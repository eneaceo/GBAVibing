#include "bn_core.h"

#include "bn_string.h"
#include "bn_array.h"
#include "bn_timer.h"
#include "bn_timers.h"
#include "bn_sprite_ptr.h"
#include "bn_sound_items.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"
#include "common_variable_8x8_sprite_font.h"

#include "bn_fixed.h"

#include "data.h"

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
    
    // Debug texts
    //bn::vector<bn::sprite_ptr, 16> TextSprites;
    //bn::string<512> Text = " ";
    //bn::sprite_text_generator TextGenerator(common::variable_8x8_sprite_font);
    
    uint8_t audio_counter = 0;
    uint16_t image_counter = 0;

    bn::optional<bn::regular_bg_ptr> image_optional;
    
    uint16_t audio_frames = 0;
    uint8_t image_frames = 0;
    
    Data::audio_items[audio_counter].play();
    image_optional = Data::image_items[image_counter].create_bg(0, 0);
   
    while (true)
    {
        //TextSprites.clear();
        //Text = "Audio: " + bn::to_string<64>(audio_counter) + " Image: " + bn::to_string<64>(image_counter);

        if (audio_frames == 600)
        {
            audio_frames = 0;
            audio_counter++;
            if (audio_counter < Data::audio_items.size())
            {
                Data::audio_items[audio_counter].play();
            }
            else
            {
                audio_counter = 0;
                image_counter = 0;
                image_frames = 0;
                Data::audio_items[audio_counter].play();
                image_optional.reset();
                image_optional = Data::image_items[image_counter].create_bg(0, 0);
            }
        }

        if (image_frames == 30)
        {
            image_frames = 0;
            image_counter++;
            image_optional.reset();
            if (image_counter < Data::image_items.size())
            {
                image_optional = Data::image_items[image_counter].create_bg(0, 0);
            }
        }

        //TextGenerator.generate(-6 * 16, -68, Text, TextSprites);
        audio_frames++;
        image_frames++;
        bn::core::update();
    }
}
