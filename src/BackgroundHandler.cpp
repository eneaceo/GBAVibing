#include "BackgroundHandler.h"
#include "bn_core.h"

void BackgroundHandler::Update()
{
    LoadBackground(BackgroundItems[BackgroundIndex]);
    if (Counter == AnimationSpeed)
    {
        Counter = 0;
        BackgroundIndex = Random.get_int(BackgroundItems.size());
    }
    Counter++;
}

void BackgroundHandler::LoadBackground(bn::regular_bg_item aBackground)
{
    Background.reset();
    Background = aBackground.create_bg(0, 0);
}

void BackgroundHandler::AnimateBackground()
{
}

void BackgroundHandler::ResetBackground()
{
    Background.reset();
}