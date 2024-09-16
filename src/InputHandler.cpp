#include "InputHandler.h"
#include "core/Command.h"
#include "core/State.h"
#include "bn_keypad.h"

void InputHandler::BindButton(uint8_t aButton, bn::unique_ptr<Command> aNewCommand)
{
    switch (aButton)
    {
    case BUTTONS::A:
        ButtonA = bn::move(aNewCommand);
        break;
    case BUTTONS::B:
        ButtonB = bn::move(aNewCommand);
        break;
    case BUTTONS::UP:
        ButtonUp = bn::move(aNewCommand);
        break;
    case BUTTONS::DOWN:
        ButtonDown = bn::move(aNewCommand);
        break;
    }
}

void InputHandler::HandleInput(State &aState)
{
    if (bn::keypad::any_pressed())
    {
        if (bn::keypad::a_pressed() && ButtonA)
        {
            ButtonA->Execute(aState);
        }
        else if (bn::keypad::b_pressed() && ButtonB)
        {
            ButtonB->Execute(aState);
        }
        else if (bn::keypad::up_pressed() && ButtonUp)
        {
            ButtonUp->Execute(aState);
        }
        else if (bn::keypad::down_pressed() && ButtonDown)
        {
            ButtonDown->Execute(aState);
        }
    }
}