#include "InputHandler.h"
#include "Command.h"

InputHandler::InputHandler()
    :   ButtonA(std::make_unique<NextStateCommand>()), 
        ButtonB(std::make_unique<PreviousStateCommand>()), 
        ButtonUp(std::make_unique<MenuUpCommand>()), 
        ButtonDown(std::make_unique<MenuDownCommand>())
{
}

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

void InputHandler::HandleInput()
{
    if (bn::keypad::any_pressed())
    {
        if (bn::keypad::a_pressed() && ButtonA)
        {
            ButtonA->Execute();
        }
        else if (bn::keypad::b_pressed() && ButtonB)
        {
            ButtonB->Execute();
        }
        else if (bn::keypad::up_pressed() && ButtonUp)
        {
            ButtonUp->Execute();
        }
        else if (bn::keypad::down_pressed() && ButtonDown)
        {
            ButtonDown->Execute();
        }
    }
}