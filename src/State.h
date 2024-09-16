#ifndef STATE_H
#define STATE_H

#include "bn_unique_ptr.h"
#include "InputHandler.h"
#include "TextHandler.h"

class State
{
public:
    enum STATES
    {
        NONE,
        MAINMENU,
        CREDITS,
        ALBUMMENU,
        PLAYINGSONG
    };

    State()
    {
        InputManager = bn::make_unique<InputHandler>();
        TextManager = bn::make_unique<TextHandler>();
    };

    virtual ~State() = default;
    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual uint8_t GetStateInfo() const = 0;

protected:
    bn::unique_ptr<InputHandler> InputManager;
    bn::unique_ptr<TextHandler> TextManager;
};

#endif