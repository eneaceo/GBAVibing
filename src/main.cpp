#include "bn_core.h"

#include "bn_string.h"
#include "bn_array.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sound_items.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"

#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_variable_8x16_font_red.h"

#include "bn_regular_bg_items_background_menu.h"

#include "data.h"

namespace
{
    void process_videoclip(bn::optional<bn::regular_bg_ptr> &image_optional)
    {
        // Videoclip variables
        uint8_t audio_counter = 0;
        uint16_t image_counter = 0;

        uint16_t audio_frames = 0;
        uint8_t image_frames = 0;
        
        image_optional.reset();

        Data::audio_items[audio_counter].play();
        image_optional = Data::image_items[image_counter].create_bg(0, 0);

        for (uint32_t frame = 0; frame < 14400; frame++)
        {
            if (audio_frames == 600)
            {
                audio_frames = 0;
                audio_counter++;
                if (audio_counter < Data::audio_items.size())
                {
                    Data::audio_items[audio_counter].play();
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
            audio_frames++;
            image_frames++;
            bn::core::update();
        }

        image_optional.reset();
        image_optional = bn::regular_bg_items::background_menu.create_bg(0, 0);
    }

    void text_wigle(bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites, bn::fixed &angle, const bn::fixed angle_inc, const uint8_t SelectedOption)
    {
        angle -= angle_inc;

        if (angle == 0)
        {
            angle += 360;
        }

        bn::fixed local_angle = angle;

        for (bn::sprite_ptr &SelectedTextSprite : SelectedTextSprites)
        {
            local_angle += angle_inc * 4;

            if (local_angle >= 360)
            {
                local_angle -= 360;
            }

            SelectedTextSprite.set_y(SelectedOption * 10 + bn::degrees_lut_sin(local_angle) * 2);
        }
    }

    void selected_option(const uint8_t SelectedOption, const uint8_t NumberOptions,
                         bn::vector<bn::sprite_ptr, 32> &TextSprites, bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites,
                         bn::sprite_text_generator TextGenerator, const bn::array<bn::string<16>, 2> Texts, bn::fixed &angle,
                         const bn::fixed angle_inc)
    {

        for (uint8_t option = 0; option < NumberOptions; ++option)
        {
            if (option != SelectedOption)
            {
                TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                TextGenerator.generate(0, 10 * option, Texts[option], TextSprites);
            }
            else
            {
                TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                TextGenerator.set_one_sprite_per_character(true);
                TextGenerator.generate(0, 10 * option, Texts[option], SelectedTextSprites);
                TextGenerator.set_one_sprite_per_character(false);
            }
        }

        text_wigle(SelectedTextSprites, angle, angle_inc, SelectedOption);
    }
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    // Texts
    bn::sprite_text_generator TextGenerator(common::variable_8x16_sprite_font);

    // Wigle variables
    bn::fixed angle = 360;
    const bn::fixed angle_inc = 4;

    bn::string<8> TextBandName = "VVV";
    bn::string<8> TextAlbumName = "VACIADOR";

    bn::string<16> TextAlbum = "Album";
    bn::string<16> TextVideoclip = "KLF - Videoclip";

    uint8_t SelectedOption = 0;
    const uint8_t NumberOptionsMenu = 2;

    const bn::array<bn::string<16>, 2> MenuTexts = {TextAlbum, TextVideoclip};

    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;

    // Background pointer
    bn::optional<bn::regular_bg_ptr> image_optional;
    image_optional = bn::regular_bg_items::background_menu.create_bg(0, 0);

    while (true)
    {
        TextSprites.clear();
        SelectedTextSprites.clear();

        // Generate static texts
        TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
        TextGenerator.generate(-50, -50, TextBandName, TextSprites);
        TextGenerator.generate(-40, -40, TextAlbumName, TextSprites);

        // WIP Keypad
        if (bn::keypad::up_pressed())
        {
            SelectedOption = 0;
        }
        if (bn::keypad::down_pressed())
        {
            SelectedOption = 1;
        }
        if (bn::keypad::start_pressed())
        {
            if (SelectedOption == 1)
            {
                TextSprites.clear();
                SelectedTextSprites.clear();
                process_videoclip(image_optional);
            }
        }

        selected_option(SelectedOption, NumberOptionsMenu, TextSprites, SelectedTextSprites, TextGenerator, MenuTexts, angle, angle_inc);

        bn::core::update();
    }
}
