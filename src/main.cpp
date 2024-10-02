#include "bn_core.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"
#include "bn_sound_items.h"

#include "TextGenerator.h"
#include "InputHandler.h"
#include "StateHandler.h"
#include "ImageHandler.h"
#include "MusicHandler.h"

namespace
{
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    InputHandler CurrentInputHandler = InputHandler();
    TextGenerator CurrentTextGenerator = TextGenerator();
    ImageHandler CurrentImageHandler = ImageHandler();
    MusicHandler CurrentMusicHandler = MusicHandler();

    bn::sound_items::intro.play();
    CurrentImageHandler.PlayIntro();
    
    StateHandler::GetInstance().initialize(&CurrentTextGenerator, &CurrentImageHandler, &CurrentMusicHandler);
    CurrentMusicHandler.PlayBackground();

    while (true)
    {
        CurrentMusicHandler.Update();
        CurrentImageHandler.Update();
        CurrentTextGenerator.Update();
        StateHandler::GetInstance().Update();
        CurrentInputHandler.Update(StateHandler::GetInstance().GetCurrentState());
        bn::core::update();
    };
}
