#ifndef STATE_H
#define STATE_H

#include "bn_unique_ptr.h"
#include "InputHandler.h"
#include "TextHandler.h"

class State
{
public:
    State()
    {
        InputManager = bn::make_unique<InputHandler>();
        TextManager = bn::make_unique<TextHandler>();
    };

    virtual ~State()
    {
        InputManager.reset();
        TextManager.reset();
    }
    
    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;

    virtual void Select() {};
    virtual void Back() {};
    virtual void MenuUp() {};
    virtual void MenuDown() {};

protected:
    bn::unique_ptr<InputHandler> InputManager;
    bn::unique_ptr<TextHandler> TextManager;

    uint8_t SelectedOption = 0;
};

#endif