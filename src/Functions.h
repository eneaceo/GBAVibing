#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Data.h"
#include "Singletons.h"

namespace Functions
{
    /*
    static uint16_t GetSongFrames(const uint8_t aSongNumber)
    {
        uint16_t Ret = 0;
        uint8_t Index = aSongNumber;
        if (Index < Data::SongFrames.size())
        {
            Ret = Data::SongFrames[Index];
        }
        return Ret;
    };

    static uint8_t GetSongStart(const uint8_t aSongNumber)
    {
        uint8_t Ret = 0;
        uint8_t Index = aSongNumber * 2;
        if (Index < Data::SongsIndexs.size())
        {
            Ret = Data::SongsIndexs[Index];
        }
        return Ret;
    };

    static uint8_t GetSongEnd(const uint8_t aSongNumber)
    {
        uint8_t Ret = 0;
        uint8_t Index = (aSongNumber * 2) + 1;
        if (Index < Data::SongsIndexs.size())
        {
            Ret = Data::SongsIndexs[Index];
        }
        return Ret;
    };

    static void TextWigle(const uint8_t aSelectedOption, const int8_t aPositionOffset = 0)
    {
        Data::Angle -= Data::AngleIncrement;

        if (Data::Angle == 0)
        {
            Data::Angle += 360;
        }

        bn::fixed LocalAngle = Data::Angle;

        for (bn::sprite_ptr &SelectedTextSprite : Singletons::SelectedTextSprites)
        {
            LocalAngle += Data::AngleIncrement * 4;

            if (LocalAngle >= 360)
            {
                LocalAngle -= 360;
            }

            SelectedTextSprite.set_y(aPositionOffset + aSelectedOption * Data::TextSeparation + bn::degrees_lut_sin(LocalAngle) * 2);
        }
    };

    static void AnimateBackground()
    {
        if (Data::AnimatingBackground)
        {
            if (Singletons::Random.get_int(Data::AnimationVariation) == 0)
            {
                Singletons::ImageOptional.reset();
                Singletons::ImageOptional = Data::BackgroundItems[Singletons::Random.get_int(Data::BackgroundItems.size())].create_bg(0, 0);
            }
            if (Data::BackgroundAnimationFrames > Data::BackgroundAnimationPlaying)
            {
                Data::AnimatingBackground = false;
                Data::BackgroundAnimationFrames = 0;
                Data::BackgroundAnimationPause = 60 * Singletons::Random.get_int(Data::BackgroundAnimationPauseTime);
                Singletons::ImageOptional.reset();
                Singletons::ImageOptional = bn::regular_bg_items::background.create_bg(0, 0);
            }
        }
        else
        {
            if (Data::BackgroundAnimationFrames > Data::BackgroundAnimationPause)
            {
                Data::AnimatingBackground = true;
                Data::BackgroundAnimationFrames = 0;
                Data::BackgroundAnimationPlaying = 30 * Singletons::Random.get_int(Data::BackgroundAnimationPlayingTime);
            }
        }
        Data::BackgroundAnimationFrames++;
    };
    */
}

#endif