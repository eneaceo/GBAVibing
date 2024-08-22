#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.h"
#include "Singletons.h"

namespace Functions
{

    static uint16_t GetSongFrames(const uint8_t aSongNumber)
    {
        uint16_t ret = 0;
        uint8_t index = aSongNumber;
        if (index < Data::SongFrames.size())
        {
            ret = Data::SongFrames[index];
        }
        return ret;
    };

    static uint8_t GetSongStart(const uint8_t aSongNumber)
    {
        uint8_t ret = 0;
        uint8_t index = aSongNumber * 2;
        if (index < Data::SongsIndexs.size())
        {
            ret = Data::SongsIndexs[index];
        }
        return ret;
    };

    static uint8_t GetSongEnd(const uint8_t aSongNumber)
    {
        uint8_t ret = 0;
        uint8_t index = (aSongNumber * 2) + 1;
        if (index < Data::SongsIndexs.size())
        {
            ret = Data::SongsIndexs[index];
        }
        return ret;
    };

    static void text_wigle(const uint8_t SelectedOption, const int8_t PositionOffset)
    {
        Data::angle -= Data::angle_inc;

        if (Data::angle == 0)
        {
            Data::angle += 360;
        }

        bn::fixed local_angle = Data::angle;

        for (bn::sprite_ptr &SelectedTextSprite : Singletons::SelectedTextSprites)
        {
            local_angle += Data::angle_inc * 4;

            if (local_angle >= 360)
            {
                local_angle -= 360;
            }

            SelectedTextSprite.set_y(PositionOffset + SelectedOption * 15 + bn::degrees_lut_sin(local_angle) * 2);
        }
    };

    static void play_song(const uint8_t SelectedOption)
    {
        uint8_t audio_counter = GetSongStart(SelectedOption);
        uint8_t max_audio_counter = GetSongEnd(SelectedOption);

        uint16_t audio_frames = 0;
        uint16_t max_total_frames = GetSongFrames(SelectedOption);

        Singletons::sound_handler.get()->stop();
        Singletons::sound_handler = Data::audio_items[audio_counter].play();

        for (uint32_t frame = 0; frame < max_total_frames; frame++)
        {
            if (bn::keypad::b_pressed())
            {
                break;
            }
            
            if (audio_frames == Data::max_audio_frames)
            {
                audio_frames = 0;
                audio_counter++;
                if (audio_counter <= max_audio_counter)
                {
                    Singletons::sound_handler = Data::audio_items[audio_counter].play();
                }
            }

            audio_frames++;
            bn::core::update();
        }

        Singletons::sound_handler.get()->stop();
    };

}

#endif