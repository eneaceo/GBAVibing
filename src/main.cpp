#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "StateManager.h"

namespace
{
}

int main()
{
    // TODO -> New Album, save scripts for better future
    // TODO -> Creditos
    // TODO -> Better background animations
    // TODO -> Better text animations
    // TODO -> Music Player like behavior?
    // TODO -> Change song automatically?
    // TODO -> Better scene/state handling, only one loop?

    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    // WIP
    // States - menu - credits - album menu - song playing
 
    //std::unique_ptr<InputHandler> InputManager(new InputHandler);
    //InputManager->BindButton(InputHandler::BUTTONS::A, std::make_unique<NextStateCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::B, std::make_unique<PreviousStateCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::UP, std::make_unique<MenuUpCommand>());
    //InputManager->BindButton(InputHandler::BUTTONS::DOWN, std::make_unique<MenuDownCommand>());

    std::unique_ptr<StateManager> _StateManager(new StateManager);

    while (true)
    {
        // update events
        // update text
        // update animations
        _StateManager->Update();
        bn::core::update();
    };
}
