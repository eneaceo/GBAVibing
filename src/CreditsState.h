#ifndef CREDITSTATE_H
#define CREDITSTATE_H

#include "State.h"
#include "bn_random.h"
#include "bn_optional.h"
#include "bn_sound_items.h"

class CreditsState : public State
{
public:
    CreditsState();
    ~CreditsState() = default;

    void Update() override;
    void Enter(const bool aReset) override;
    void Exit() override;
    void Back() override;
private:
    const uint16_t ConstAudioCounter = 480;
    uint16_t SoundCounter = 0; 
    uint16_t SoundTimer = 60;
    bn::random Random;
    bn::optional<bn::sound_handle> SoundHandler;
};

#endif