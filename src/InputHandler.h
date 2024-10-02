#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class StateBase;

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

    InputHandler() = default;
    ~InputHandler() = default;

    void Update(StateBase *aState);
};

#endif