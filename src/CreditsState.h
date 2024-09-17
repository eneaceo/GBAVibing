#ifndef CREDITSTATE_H
#define CREDITSTATE_H

#include "State.h"

class CreditsState : public State
{
public:
    CreditsState();
    ~CreditsState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;
    void Back() override;
};

#endif