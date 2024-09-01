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

namespace
{
    /*
    // Animate the current selected option in the menu
    void selected_option_menu(const uint8_t aSelectedOption)
    {
        for (uint8_t Option = 0; Option < Data::MenuTexts.size(); ++Option)
        {
            if (Option != aSelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(0, Data::TextSeparation * Option, Data::MenuTexts[Option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(0, Data::TextSeparation * Option, Data::MenuTexts[Option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        Functions::TextWigle(aSelectedOption);
    }

    // Animate the current selected option in the album menu
    void selected_option_album(const uint8_t aSelectedOption)
    {
        const int8_t YOffset = -60;
        for (uint8_t Option = 0; Option < Data::AlbumTexts.size(); ++Option)
        {
            if (Option != aSelectedOption)
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
                Singletons::TextGenerator.generate(-100, YOffset + (Data::TextSeparation * Option), Data::AlbumTexts[Option], Singletons::TextSprites);
            }
            else
            {
                Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
                Singletons::TextGenerator.set_one_sprite_per_character(true);
                Singletons::TextGenerator.generate(-80, YOffset + (Data::TextSeparation * Option), Data::AlbumTexts[Option], Singletons::SelectedTextSprites);
                Singletons::TextGenerator.set_one_sprite_per_character(false);
            }
        }

        Functions::TextWigle(aSelectedOption, YOffset);
    }

    // SONG PLAYING SCENE
    void PlaySong(const uint8_t aSelectedOption)
    {

        Singletons::TextSprites.clear();
        Singletons::SelectedTextSprites.clear();

        Singletons::TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);

        Singletons::TextGenerator.set_palette_item(bn::sprite_items::variable_8x16_font_red.palette_item());
        Singletons::TextGenerator.generate(0, 0, Data::AlbumTexts[aSelectedOption], Singletons::SelectedTextSprites);

        uint8_t AudioCounter = Functions::GetSongStart(aSelectedOption);
        uint8_t MaxAudioCounter = Functions::GetSongEnd(aSelectedOption);

        uint16_t AudioFrames = 0;
        uint16_t MaxTotalFrames = Functions::GetSongFrames(aSelectedOption);

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
            Functions::AnimateBackground();
            bn::core::update();
        }

        Singletons::SoundHandler.get()->stop();
        Singletons::TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);
    };

    // SONG MENU SCENE
    void SongSelection()
    {
        Singletons::SoundHandler.get()->stop();
        Singletons::ImageOptional.reset();

        Singletons::TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);

        Singletons::ImageOptional = bn::regular_bg_items::background.create_bg(0, 0);

        const uint8_t NumberOptionsMenu = Data::AlbumTexts.size();
        uint8_t SelectedOption = 0;
        bool PlayingSong = false;

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
                PlayingSong = true;
                PlaySong(SelectedOption);
            }

            if (bn::keypad::b_pressed())
            {
                if (PlayingSong)
                {
                    PlayingSong = false;
                }
                else
                {
                    Data::CurrentState = Data::STATES::MENU;
                }
            }

            Functions::AnimateBackground();
            bn::core::update();
        }
    }

    // MAIN MENU SCENE
    void MainMenu()
    {
        Singletons::SoundHandler.get()->stop();
        Singletons::ImageOptional.reset();

        Singletons::TextGenerator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);

        Singletons::ImageOptional = bn::regular_bg_items::background.create_bg(0, 0);

        uint8_t SelectedOption = 0;

        while (Data::CurrentState == Data::STATES::MENU)
        {
            Singletons::TextSprites.clear();
            Singletons::SelectedTextSprites.clear();

            Singletons::TextGenerator.set_palette_item(bn::sprite_items::common_variable_8x16_font.palette_item());
            Singletons::TextGenerator.generate(0, -40, Data::TextBandName, Singletons::TextSprites);
            Singletons::TextGenerator.generate(0, -30, Data::TextAlbumName, Singletons::TextSprites);

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
                    break;
                }
            }

            Functions::AnimateBackground();
            bn::core::update();
        }
    }
    */
}

#include "StateStack.h"

int main()
{
    // TODO -> New Album, save scripts for better future
    // TODO -> Creditos
    // TODO -> Better background animations
    // TODO -> Better text animations
    // TODO -> Music Player like behavior?
    // TODO -> Change song automatically?
    // TODO -> Better scene/state handling, only one loop?

    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(31, 0, 0));

    // WIP
    // States - menu - credits - album menu - song playing
 
    //std::unique_ptr<InputHandler> InputManager(new InputHandler);
    //InputManager->BindButton(InputHandler::BUTTONS::A, std::make_unique<NextStateCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::B, std::make_unique<PreviousStateCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::UP, std::make_unique<MenuUpCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::DOWN, std::make_unique<MenuDownCommand>());

    std::unique_ptr<StateStack> StateManager(new StateStack);


    while (true)
    {
        // update events
        // update text
        // update animations
        StateManager->Update();
        bn::core::update();
    };

    // END WIP
    /*
    while (true)
    {
        switch (Data::CurrentState)
        {
        case Data::STATES::MENU:
            MainMenu();
            break;
        case Data::STATES::SONG_MENU:
            SongSelection();
            break;
        }

        bn::core::update();
    }
    */
}
