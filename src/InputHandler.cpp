#include "InputHandler.h"

#include "bn_keypad.h"

void InputHandler::BindButton(uint8_t aButton, std::unique_ptr<Command> aNewCommand)
{
    switch (aButton)
    {
    case BUTTONS::A:
        ButtonA = std::move(aNewCommand);
        break;
    case BUTTONS::B:
        ButtonB = std::move(aNewCommand);
        break;
    case BUTTONS::UP:
        ButtonUp = std::move(aNewCommand);
        break;
    case BUTTONS::DOWN:
        ButtonDown = std::move(aNewCommand);
        break;
    }
}

void InputHandler::HandleInput(Actor &aActor)
{
    if (bn::keypad::any_pressed())
    {
        if (bn::keypad::a_pressed() && ButtonA)
        {
            ButtonA->Execute(aActor);
        }
        else if (bn::keypad::b_pressed() && ButtonB)
        {
            ButtonB->Execute(aActor);
        }
        else if (bn::keypad::up_pressed() && ButtonUp)
        {
            ButtonUp->Execute(aActor);
        }
        else if (bn::keypad::down_pressed() && ButtonDown)
        {
            ButtonDown->Execute(aActor);
        }
    }
}