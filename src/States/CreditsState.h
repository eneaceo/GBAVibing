#include "../core/State.h"

class CreditsState : public State
{
public:
    CreditsState() : State() {};

    void Update() override {};
    void Enter() override {};
    void Exit() override {};
    uint8_t GetStateInfo() const override { return STATES::CREDITS; };
};