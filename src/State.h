#ifndef STATE_H
#define STATE_H

#include "bn_unique_ptr.h"
#include "InputHandler.h"
#include "TextHandler.h"
#include "BackgroundHandler.h"

class State
{
public:
    State()
    {
        InputManager = bn::make_unique<InputHandler>();
        TextManager = bn::make_unique<TextHandler>();
        BackgroundManager = bn::make_unique<BackgroundHandler>(); 
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
    virtual void Auto() {};

protected:
    bn::unique_ptr<InputHandler> InputManager;
    bn::unique_ptr<TextHandler> TextManager;
    bn::unique_ptr<BackgroundHandler> BackgroundManager;

    uint8_t SelectedOption = 0;
};

#endif