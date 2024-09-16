#include "bn_core.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"

#include "StateManager.h"

namespace
{
}

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    bn::unique_ptr<StateManager> HandleCurrentState(new StateManager);

    while (true)
    {
        HandleCurrentState->Update();
        bn::core::update();
    };
}
