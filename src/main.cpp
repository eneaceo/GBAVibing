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

#include "Singletons.h"


#include "bn_regular_bg_items_background_menu.h"

#include "data.h"

namespace
{

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

            SelectedTextSprite.set_y(SelectedOption * 15 + bn::degrees_lut_sin(local_angle) * 2);
        }
    }

    void text_wigle_b(bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites, bn::fixed &angle, const bn::fixed angle_inc, const uint8_t SelectedOption)
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

            SelectedTextSprite.set_y(-50 + SelectedOption * 15 + bn::degrees_lut_sin(local_angle) * 2);
        }
    }

    void selected_option(const uint8_t SelectedOption, const uint8_t NumberOptions,
                         bn::vector<bn::sprite_ptr, 32> &TextSprites, bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites,
                         const bn::array<bn::string<32>, 2> Texts, bn::fixed &angle,
                         const bn::fixed angle_inc)
    {

        for (uint8_t option = 0; option < NumberOptions; ++option)
        {
            if (option != SelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(0, 15 * option, Texts[option], TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(0, 15 * option, Texts[option], SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        text_wigle(SelectedTextSprites, angle, angle_inc, SelectedOption);
    }

    void selected_option(const uint8_t SelectedOption, const uint8_t NumberOptions,
                         bn::vector<bn::sprite_ptr, 32> &TextSprites, bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites,
                         const bn::array<bn::string<32>, 9> Texts, bn::fixed &angle,
                         const bn::fixed angle_inc)
    {

        for (uint8_t option = 0; option < NumberOptions; ++option)
        {
            if (option != SelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(-40, -50 + (15 * option), Texts[option], TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(-20, -50 + (15 * option), Texts[option], SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        text_wigle_b(SelectedTextSprites, angle, angle_inc, SelectedOption);
    }

    void album_selection(bn::vector<bn::sprite_ptr, 32> &TextSprites, bn::vector<bn::sprite_ptr, 32> &SelectedTextSprites, 
                        bn::fixed &angle, const bn::fixed angle_inc)
    {

        const bn::string<32> vvv_01 = "Zugzwang";
        const bn::string<32> vvv_02 = "El Ángel de la Historia";
        const bn::string<32> vvv_03 = "Mediocres y Agresivos";
        const bn::string<32> vvv_04 = "Hikutsu";
        const bn::string<32> vvv_05 = "Rush";
        const bn::string<32> vvv_06 = "Bellver";
        const bn::string<32> vvv_07 = "KLF";
        const bn::string<32> vvv_08 = "La Grieta";
        const bn::string<32> vvv_09 = "Ctrl + Alt + Supr";

        uint8_t SelectedOption = 0;
        const uint8_t NumberOptionsMenu = 9;

        const bn::array<bn::string<32>, 9> MenuTexts = {vvv_01, vvv_02, vvv_03, vvv_04, vvv_05, vvv_06, vvv_07, vvv_08, vvv_09};

        bool waited = false;
        bool loop = true;
        bn::optional<bn::sound_handle> sound_handler;
        while (loop)
        {
            TextSprites.clear();
            SelectedTextSprites.clear();

            // Generate static texts
            Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());

            // WIP Keypad
            if (bn::keypad::down_pressed())
            {
                if (SelectedOption != NumberOptionsMenu - 1)
                {
                    SelectedOption += 1;
                }
                else
                {
                    SelectedOption = 0;
                }
            }
            if (bn::keypad::up_pressed())
            {
                if (SelectedOption != 0)
                {
                    SelectedOption -= 1;
                }
                else
                {
                    SelectedOption = NumberOptionsMenu - 1;
                }
            }
            if (bn::keypad::b_pressed())
            {
                loop = false;
            }
            if (bn::keypad::a_pressed() && waited && loop)
            {
                int audio_counter = 0;
                int audio_frames = 0;
                switch (SelectedOption)
                {
                case 0:
                    sound_handler = Data::audio_items_zugzwang[audio_counter].play();
                    for (uint32_t frame = 0; frame < 14160; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_zugzwang.size())
                            {
                                sound_handler = Data::audio_items_zugzwang[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }

                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 1:
                    sound_handler = Data::audio_items_elangeldelahistoria[audio_counter].play();
                    for (uint32_t frame = 0; frame < 16080; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_elangeldelahistoria.size())
                            {
                                sound_handler = Data::audio_items_elangeldelahistoria[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 2:
                    sound_handler = Data::audio_items_mediocresyagresivos[audio_counter].play();
                    for (uint32_t frame = 0; frame < 12480; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_mediocresyagresivos.size())
                            {
                                sound_handler = Data::audio_items_mediocresyagresivos[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 3:
                    sound_handler = Data::audio_items_hikutsu[audio_counter].play();
                    for (uint32_t frame = 0; frame < 12000; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_hikutsu.size())
                            {
                                sound_handler = Data::audio_items_hikutsu[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 4:
                    sound_handler = Data::audio_items_rush[audio_counter].play();
                    for (uint32_t frame = 0; frame < 13380; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_rush.size())
                            {
                                sound_handler = Data::audio_items_rush[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 5:
                    sound_handler = Data::audio_items_bellver[audio_counter].play();
                    for (uint32_t frame = 0; frame < 13080; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_bellver.size())
                            {
                                sound_handler = Data::audio_items_bellver[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 6:
                    sound_handler = Data::audio_items_klf[audio_counter].play();
                    for (uint32_t frame = 0; frame < 14400; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_klf.size())
                            {
                                sound_handler = Data::audio_items_klf[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                           sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 7:
                    sound_handler = Data::audio_items_lagrieta[audio_counter].play();
                    for (uint32_t frame = 0; frame < 16200; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_lagrieta.size())
                            {
                                sound_handler = Data::audio_items_lagrieta[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                case 8:
                    sound_handler = Data::audio_items_ctrlaltsupr[audio_counter].play();
                    for (uint32_t frame = 0; frame < 7140; frame++)
                    {
                        if (audio_frames == 900)
                        {
                            audio_frames = 0;
                            audio_counter++;
                            if (audio_counter < Data::audio_items_ctrlaltsupr.size())
                            {
                                sound_handler = Data::audio_items_ctrlaltsupr[audio_counter].play();
                            }
                        }
                        if (bn::keypad::b_pressed())
                        {
                            sound_handler->stop();
                            break;
                        }
                        audio_frames++;
                        bn::core::update();
                    }
                    break;
                default:
                    break;
                }
            }

            selected_option(SelectedOption, NumberOptionsMenu, TextSprites, SelectedTextSprites, MenuTexts, angle, angle_inc);

            bn::core::update();

            // FUCK THIS
            for (int i = 0; i < 60; ++i)
            {
                waited = true;
            }
        }
    }

    void process_videoclip(bn::optional<bn::regular_bg_ptr> &image_optional)
    {
        // Videoclip variables
        uint8_t audio_counter = 0;
        uint16_t image_counter = 0;

        uint16_t audio_frames = 0;
        uint8_t image_frames = 0;

        image_optional.reset();

        bn::optional<bn::sound_handle> sound_handler;
        sound_handler = Data::audio_items_klf[audio_counter].play();
        image_optional = Data::image_items[image_counter].create_bg(0, 0);
        for (uint32_t frame = 0; frame < 14400; frame++)
        {
            if (bn::keypad::b_pressed())
            {
                sound_handler->stop();
                break;
            }
            if (audio_frames == 900)
            {
                audio_frames = 0;
                audio_counter++;
                if (audio_counter < Data::audio_items_klf.size())
                {
                    sound_handler = Data::audio_items_klf[audio_counter].play();
                }
            }

            if (image_frames == 60)
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

}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    // Wigle variables
    bn::fixed angle = 360;
    const bn::fixed angle_inc = 4;

    const bn::string<32> TextBandName = "VVV -Trippin'you-";
    const bn::string<32> TextAlbumName = "- Vaciador -";

    const bn::string<32> TextAlbum = "Escuchar Album";
    const bn::string<32> TextVideoclip = "Ver Videoclip - KLF";

    uint8_t SelectedOption = 0;
    const uint8_t NumberOptionsMenu = 2;

    const bn::array<bn::string<32>, 2> MenuTexts = {TextAlbum, TextVideoclip};

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
        Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
        Singletons::TextGenerator.generate(-50, -50, TextBandName, TextSprites);
        Singletons::TextGenerator.generate(-40, -40, TextAlbumName, TextSprites);

        // WIP Keypad
        if (bn::keypad::up_pressed())
        {
            SelectedOption = 0;
        }
        if (bn::keypad::down_pressed())
        {
            SelectedOption = 1;
        }
        if (bn::keypad::a_pressed())
        {
            if (SelectedOption == 1)
            {
                TextSprites.clear();
                SelectedTextSprites.clear();
                process_videoclip(image_optional);
            }
            if (SelectedOption == 0)
            {
                TextSprites.clear();
                SelectedTextSprites.clear();
                album_selection(TextSprites, SelectedTextSprites, angle, angle_inc);
            }
        }

        selected_option(SelectedOption, NumberOptionsMenu, TextSprites, SelectedTextSprites, MenuTexts, angle, angle_inc);

        bn::core::update();
    }
}
