#include "InputHandler.h"
#include "bn_keypad.h"
#include "StateBase.h"

void InputHandler::Update(StateBase *aState)
{
    if (bn::keypad::any_pressed() && aState != nullptr)
    {
        if (bn::keypad::a_pressed())
        {
            aState->Select();
        }
        else if (bn::keypad::b_pressed())
        {
            aState->Back();
        }
        else if (bn::keypad::up_pressed())
        {
            aState->MenuUp();
        }
        else if (bn::keypad::down_pressed())
        {
            aState->MenuDown();
        }
        else if (bn::keypad::start_pressed())
        {
            aState->Auto();
        }
    }
}