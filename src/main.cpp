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

#include "Data.h"
#include "Functions.h"
#include "Singletons.h"

#include "bn_regular_bg_items_background_menu.h"

namespace
{

    void selected_option_menu(const uint8_t SelectedOption)
    {

        for (uint8_t option = 0; option < Data::MenuTexts.size(); ++option)
        {
            if (option != SelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(0, 15 * option, Data::MenuTexts[option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(0, 15 * option, Data::MenuTexts[option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        Functions::text_wigle(SelectedOption, 0);
    }

    void selected_option_album(const uint8_t SelectedOption)
    {

        for (uint8_t option = 0; option < Data::AlbumTexts.size(); ++option)
        {
            if (option != SelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(-40, -50 + (15 * option), Data::AlbumTexts[option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(-20, -50 + (15 * option), Data::AlbumTexts[option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        Functions::text_wigle(SelectedOption, -50);
    }

    void album_selection()
    {
        uint8_t SelectedOption = 0;
        const uint8_t NumberOptionsMenu = Data::AlbumTexts.size();

        bool waited = false;
        bool loop = true;
        while (loop)
        {
            Singletons::TextSprites.clear();
            Singletons::SelectedTextSprites.clear();

            // Generate static texts
            Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());

            // WIP Keypad
            if (bn::keypad::down_pressed())
            {
                SelectedOption = (SelectedOption + 1) % NumberOptionsMenu;
            }
            if (bn::keypad::up_pressed())
            {
                SelectedOption = (SelectedOption + NumberOptionsMenu - 1) % NumberOptionsMenu;
            }

            if (bn::keypad::b_pressed())
            {
                loop = false;
            }

            if (bn::keypad::a_pressed() && waited && loop)
            {
                Functions::play_song(SelectedOption);
            }

            selected_option_album(SelectedOption);

            bn::core::update();

            // FUCK THIS
            for (int i = 0; i < 60; ++i)
            {
                waited = true;
            }
        }
    }

    void process_videoclip()
    {
        // Videoclip variables
        uint8_t image_counter = 0;
        uint16_t max_image_counter = Data::image_items.size();

        uint8_t audio_counter = Functions::GetSongStart(6);
        uint8_t max_audio_counter = Functions::GetSongEnd(6);

        uint8_t image_frames = 0;
        uint16_t audio_frames = 0;
        uint16_t max_total_frames = Functions::GetSongFrames(6);

        // Reset background and audio
        Singletons::image_optional.reset();
        Singletons::sound_handler.get()->stop();

        Singletons::sound_handler = Data::audio_items[audio_counter].play();
        Singletons::image_optional = Data::image_items[image_counter].create_bg(0, 0);

        // Loop
        for (uint16_t frame = 0; frame < max_total_frames; frame++)
        {
            // Return
            if (bn::keypad::b_pressed())
            {
                break;
            }
            // Audio check
            if (audio_frames == Data::max_audio_frames)
            {
                audio_frames = 0;
                audio_counter++;
                if (audio_counter <= max_audio_counter)
                {
                    Singletons::sound_handler = Data::audio_items[audio_counter].play();
                }
            }
            // Image check
            if (image_frames == Data::max_image_frames)
            {
                image_frames = 0;
                image_counter++;
                Singletons::image_optional.reset();
                if (image_counter < max_image_counter)
                {
                    Singletons::image_optional = Data::image_items[image_counter].create_bg(0, 0);
                }
            }
            // Update
            audio_frames++;
            image_frames++;
            bn::core::update();
        }

        // Return to Menu
        Singletons::sound_handler.get()->stop();
        Singletons::image_optional.reset();
        Singletons::image_optional = bn::regular_bg_items::background_menu.create_bg(0, 0);
    }

}

// TODO STATE MACHINE FOR EASIER UPDATE AND STATE MANAGING, ANIMATIONS ETC
// Posible states:
/*
    MENU
        ANIMATION -> VIDEOCLIP ->? RETURN MENU
        ANIMATION -> ALBUM MENU ->? RETURN MENU
            PLAYING SONG ->? STOP SONG
*/

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    Singletons::image_optional = bn::regular_bg_items::background_menu.create_bg(0, 0);

    uint8_t SelectedOption = 0;

    while (true)
    {
        // Clear Texts
        Singletons::TextSprites.clear();
        Singletons::SelectedTextSprites.clear();

        // Generate Menu static texts
        Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
        Singletons::TextGenerator.generate(-50, -50, Data::TextBandName, Singletons::TextSprites);
        Singletons::TextGenerator.generate(-40, -40, Data::TextAlbumName, Singletons::TextSprites);

        // Menu Keypad
        if (bn::keypad::up_pressed() || bn::keypad::down_pressed())
        {
            SelectedOption = 1 - SelectedOption;
        }
        if (bn::keypad::a_pressed())
        {
            switch (SelectedOption)
            {
            case 0:
                Singletons::TextSprites.clear();
                Singletons::SelectedTextSprites.clear();
                album_selection();
                break;
            case 1:
                Singletons::TextSprites.clear();
                Singletons::SelectedTextSprites.clear();
                process_videoclip();
                break;
            default:
                Singletons::TextSprites.clear();
                Singletons::SelectedTextSprites.clear();
                break;
            }
        }

        // Menu Text animation
        selected_option_menu(SelectedOption);

        // Update
        bn::core::update();
    }
}
