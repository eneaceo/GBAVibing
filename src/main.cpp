#include "bn_core.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"

#include "StateManager.h"
#include "MainMenuState.h"

namespace
{
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 31, 0));

    StateManager& StateSingleton = StateManager::GetInstance();
    StateSingleton.ChangeState(bn::make_unique<MainMenuState>());

    while (true)
    {
        StateSingleton.Update();
        bn::core::update();
    };
}
