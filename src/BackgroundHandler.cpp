#include "BackgroundHandler.h"
#include "bn_core.h"

void BackgroundHandler::Update()
{
    if (Animating)
    {    
        SpeedCounter++;
        DurationCounter++;
        if (SpeedCounter == AnimationSpeed)
        {
            SpeedCounter = 0;
            BackgroundIndex = Random.get_int(BackgroundItems.size());
        }
        if (DurationCounter == AnimationDuration)
        {
            Animating = false;
            DurationCounter = 0;
            SpeedCounter = 0;
            BackgroundIndex = 0;
            AnimationDuration = Random.get_int(ConstPauseDuration);
        }
        LoadBackground(BackgroundItems[BackgroundIndex]);
    }
    else
    {
        DurationCounter++;
        if (DurationCounter == AnimationDuration)
        {
            AnimationSpeed = Random.get_int(ConstAnimationSpeed);
            AnimationDuration = Random.get_int(ConstAnimationDuration);
            DurationCounter = 0;
            Animating = true;
        }
    }
}

void BackgroundHandler::LoadBackground(bn::regular_bg_item aBackground)
{
    Background.reset();
    Background = aBackground.create_bg(0, 0);
}

void BackgroundHandler::AnimateBackground(const bool aAnimate)
{
    Animating = aAnimate;
}

void BackgroundHandler::ResetBackground()
{
    Background.reset();
}