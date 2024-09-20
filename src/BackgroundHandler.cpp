#include "BackgroundHandler.h"
#include "bn_core.h"

void BackgroundHandler::Update()
{
}

void BackgroundHandler::LoadBackground(bn::regular_bg_item aBackground)
{
    Background.reset();
    Background = aBackground.create_bg(0, 0);
}

void BackgroundHandler::AnimateBackground()
{
}

void BackgroundHandler::PlayIntro()
{
    for (int Counter = 0; Counter < IntroItems.size(); ++Counter)
    {
        LoadBackground(IntroItems[Counter]);
        for (int Frame = 0; Frame < 2; ++Frame)
        {
            bn::core::update();
        }
    }
    LoadBackground(bn::regular_bg_items::background_0);
}

void BackgroundHandler::ResetBackground()
{
    Background.reset();
}