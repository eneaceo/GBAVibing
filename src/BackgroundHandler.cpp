#include "BackgroundHandler.h"

void BackgroundHandler::Update() 
{
}

void BackgroundHandler::LoadBackground(bn::regular_bg_item aBackground)
{
    Background.reset();
    Background = aBackground.create_bg(0, 0);
}

void BackgroundHandler::ResetBackground()
{
    Background.reset();
}