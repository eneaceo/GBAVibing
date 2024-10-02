#include "ImageHandler.h"
#include "bn_core.h"
#include "Intro.h"


void ImageHandler::PlayIntro()
{
    for (int i = 0; i < IntroImages.size() * 6; ++i)
    {
        SetBackground(IntroImages[i / 6]);
        bn::core::update();
    }
    SetBackground(bn::regular_bg_items::background_0);
}

void ImageHandler::SetBackground(bn::regular_bg_item aBackground)
{
    Background.reset();
    Background = aBackground.create_bg(0, 0);
}

void ImageHandler::Update()
{
    if (Animating)
    {    
        SpeedCounter++;
        DurationCounter++;
        if (SpeedCounter == AnimationSpeed)
        {
            SpeedCounter = 0;
            BackgroundIndex = Random.get_int(CurrentAnimation.size());
        }
        SetBackground(CurrentAnimation[BackgroundIndex]);
        if (DurationCounter == AnimationDuration)
        {
            Animating = false;
            DurationCounter = 0;
            SpeedCounter = 0;
            BackgroundIndex = 0;
            AnimationDuration = Random.get_int(ConstPauseDuration) + 1;
            SetBackground(bn::regular_bg_items::background_0);
        }
    }
    else
    {
        DurationCounter++;
        if (DurationCounter == AnimationDuration)
        {
            CurrentAnimation = Random.get_int(2) == 0 ? AnimationA : AnimationB;
            AnimationSpeed = Random.get_int(ConstAnimationSpeed) + 1;
            AnimationDuration = Random.get_int(ConstAnimationDuration);
            DurationCounter = 0;
            Animating = true;
        }
    }
}