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
    // Animate the current selected option in the menu
    void selected_option_menu(const uint8_t aSelectedOption)
    {
        for (uint8_t Option = 0; Option < Data::MenuTexts.size(); ++Option)
        {
            if (Option != aSelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(0, 15 * Option, Data::MenuTexts[Option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(0, 15 * Option, Data::MenuTexts[Option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }
        
        Functions::TextWigle(aSelectedOption);
    }

    // Animate the current selected option in the album menu
    void selected_option_album(const uint8_t aSelectedOption)
    {
        for (uint8_t Option = 0; Option < Data::AlbumTexts.size(); ++Option)
        {
            if (Option != aSelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(-40, -50 + (15 * Option), Data::AlbumTexts[Option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(-20, -50 + (15 * Option), Data::AlbumTexts[Option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        Functions::TextWigle(aSelectedOption, -50);
    }

    // SONG PLAYING SCENE
    void PlaySong(const uint8_t aSelectedOption)
    {

        Singletons::TextSprites.clear();
        Singletons::SelectedTextSprites.clear();

        // TODO
        // Name of the song playing
        // Background animation

        uint8_t AudioCounter = GetSongStart(aSelectedOption);
        uint8_t MaxAudioCounter = GetSongEnd(aSelectedOption);

        uint16_t AudioFrames = 0;
        uint16_t MaxTotalFrames = GetSongFrames(aSelectedOption);

        Singletons::SoundHandler.get()->stop();
        Singletons::SoundHandler = Data::AudioItems[AudioCounter].play();

        for (uint32_t frame = 0; frame < MaxTotalFrames; frame++)
        {
            if (bn::keypad::b_pressed())
            {
                break;
            }
            
            if (AudioFrames == Data::MaxAudioFrames)
            {
                AudioFrames = 0;
                AudioCounter++;
                if (AudioCounter <= MaxAudioCounter)
                {
                    Singletons::SoundHandler = Data::AudioItems[AudioCounter].play();
                }
            }

            AudioFrames++;
            bn::core::update();
        }

        Singletons::SoundHandler.get()->stop();
    };

    // SONG MENU SCENE
    void SongSelection()
    {
        Singletons::SoundHandler.get()->stop();
        Singletons::ImageOptional.reset();

        Singletons::ImageOptional = bn::regular_bg_items::background_menu.create_bg(0, 0);

        // TODO
        // Background animation
        // Better Texts positions

        const uint8_t NumberOptionsMenu = Data::AlbumTexts.size();
        uint8_t SelectedOption = 0;

        bool Playing = false;
        uint8_t AudioCounter = 0;
        uint8_t MaxAudioCounter = 0;
        uint16_t AudioFrames = 0;
        uint32_t Frames = 0;
        uint16_t MaxTotalFrames = 0;
        
        while (Data::CurrentState == Data::STATES::SONG_MENU)
        {
            Singletons::TextSprites.clear();
            Singletons::SelectedTextSprites.clear();

            Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());

            selected_option_album(SelectedOption);
            
            if (bn::keypad::down_pressed())
            {
                SelectedOption = (SelectedOption + 1) % NumberOptionsMenu;
            }
            if (bn::keypad::up_pressed())
            {
                SelectedOption = (SelectedOption + NumberOptionsMenu - 1) % NumberOptionsMenu;
            }

            if (bn::keypad::a_pressed())
            {
                PlaySong(SelectedOption);
            }

            if (bn::keypad::b_pressed())
            {
                Data::CurrentState = Data::STATES::MENU;
            }

            bn::core::update();
        }
    }

    // VIDEOCLIP SCENE
    void ProcessVideoclip()
    {
        Singletons::ImageOptional.reset();
        Singletons::SoundHandler.get()->stop();
        Singletons::TextSprites.clear();
        Singletons::SelectedTextSprites.clear();
        
        uint8_t ImageCounter = 0;
        uint16_t MaxImageCounter = Data::ImageItems.size();

        uint8_t AudioCounter = Functions::GetSongStart(6);
        uint8_t MaxAudioCounter = Functions::GetSongEnd(6);

        uint8_t ImageFrames = 0;
        uint16_t AudioFrames = 0;
        uint16_t MaxTotalFrames = Functions::GetSongFrames(6);

        Singletons::SoundHandler = Data::AudioItems[AudioCounter].play();
        Singletons::ImageOptional = Data::ImageItems[ImageCounter].create_bg(0, 0);

        for (uint16_t frame = 0; frame < MaxTotalFrames; frame++)
        {
            if (AudioFrames == Data::MaxAudioFrames)
            {
                AudioFrames = 0;
                AudioCounter++;
                if (AudioCounter <= MaxAudioCounter)
                {
                    Singletons::SoundHandler = Data::AudioItems[AudioCounter].play();
                }
            }

            if (ImageFrames == Data::MaxImageFrames)
            {
                ImageFrames = 0;
                ImageCounter++;
                Singletons::ImageOptional.reset();
                if (ImageCounter < MaxImageCounter)
                {
                    Singletons::ImageOptional = Data::ImageItems[ImageCounter].create_bg(0, 0);
                }
            }

            AudioFrames++;
            ImageFrames++;
            bn::core::update();

            if (bn::keypad::b_pressed())
            {
                break;
            }
        }

        Data::CurrentState = Data::STATES::MENU;
    }

    // MAIN MENU SCENE
    void MainMenu()
    {
        Singletons::SoundHandler.get()->stop();
        Singletons::ImageOptional.reset();

        Singletons::ImageOptional = bn::regular_bg_items::background_menu.create_bg(0, 0);

        // TODO
        // Background animation
        // Better Texts positions
        
        uint8_t SelectedOption = 0;

        while (Data::CurrentState == Data::STATES::MENU)
        {
            Singletons::TextSprites.clear();
            Singletons::SelectedTextSprites.clear();

            Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
            Singletons::TextGenerator.generate(-50, -50, Data::TextBandName, Singletons::TextSprites);
            Singletons::TextGenerator.generate(-40, -40, Data::TextAlbumName, Singletons::TextSprites);

            selected_option_menu(SelectedOption);
            
            if (bn::keypad::up_pressed() || bn::keypad::down_pressed())
            {
                SelectedOption = 1 - SelectedOption;
            }
            
            if (bn::keypad::a_pressed())
            {
                switch (SelectedOption)
                {
                case 0:
                    Data::CurrentState = Data::STATES::SONG_MENU;
                    break;
                case 1:
                    Data::CurrentState = Data::STATES::VIDEOCLIP;
                    break;
                }
            }

            bn::core::update();
        }
    }

}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    while (true)
    {
        switch(Data::CurrentState)
        {
            case Data::STATES::MENU:
                MainMenu();
            break;
            case Data::STATES::VIDEOCLIP:
                ProcessVideoclip();
            break;
            case Data::STATES::SONG_MENU:
                SongSelection();
            break;
        }

        bn::core::update();
    }
}
