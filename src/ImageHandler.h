#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_array.h"
#include "bn_random.h"
#include "Background.h"

class ImageHandler
{
public:
    ImageHandler() = default;
    ~ImageHandler() = default;

    void PlayIntro();
    void Update();
    void SetBackground(bn::regular_bg_item aBackground);

private:
    bn::optional<bn::regular_bg_ptr> Background;
    bn::array<bn::regular_bg_item, 2> CurrentAnimation = AnimationA;

    bool Animating = false;
    int SpeedCounter = 0;
    int AnimationSpeed = 5;
    int DurationCounter = 0;
    int AnimationDuration = 60;
    int BackgroundIndex = 0;
    const int ConstAnimationSpeed = 10;
    const int ConstAnimationDuration = 60;
    const int ConstPauseDuration = 240;

    bn::random Random;
};

#endif