#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "bn_unique_ptr.h"
#include "Command.h"

class State;

class InputHandler
{
public:
    enum BUTTONS
    {
        A,
        B,
        UP,
        DOWN,
        START
    };

    InputHandler() {};
    ~InputHandler() = default;

    void BindButton(uint8_t aButton, bn::unique_ptr<Command> aNewCommand);
    void HandleInput(State &aState);

private:
    bn::unique_ptr<Command> ButtonA;
    bn::unique_ptr<Command> ButtonB;
    bn::unique_ptr<Command> ButtonUp;
    bn::unique_ptr<Command> ButtonDown;
    bn::unique_ptr<Command> ButtonStart;
};

#endif