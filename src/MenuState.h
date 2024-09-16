#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"

class MenuState : public State
{
public:
    MenuState() {};
    virtual ~MenuState() = default;

    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual uint8_t GetStateInfo() const = 0;
    virtual void ChangeSelectedOption(bool aChangeDirection) = 0;
    virtual void Select() = 0;
    virtual void Back() = 0;
    virtual void MenuUp() = 0;
    virtual void MenuDown() = 0;

    uint8_t GetSelectedOption() { return SelectedOption; };

protected:
    uint8_t SelectedOption = 0;
};

#endif