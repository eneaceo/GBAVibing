#ifndef PLAYINGSONGSTATE_H
#define PLAYINGSONGSTATE_H

#include "State.h"
/*
class PlayingSongState : public State
{
public:
    PlayingSongState() : State() { SoundHandler = AudioItems[AudioCounter].play(); };

    void Update() override;
    void Enter() override {};
    void Exit() override {};
    uint8_t GetStateInfo() const override { return STATES::PLAYINGSONG; };

private:
    // TODO Music component
    bn::optional<bn::sound_handle> SoundHandler;
    uint8_t AudioCounter = 0;

    const bn::array<bn::sound_item, 16> AudioItems =
        {
            // 0 - 15
            bn::sound_items::vvv_01_zugzwang_000,
            bn::sound_items::vvv_01_zugzwang_001,
            bn::sound_items::vvv_01_zugzwang_002,
            bn::sound_items::vvv_01_zugzwang_003,
            bn::sound_items::vvv_01_zugzwang_004,
            bn::sound_items::vvv_01_zugzwang_005,
            bn::sound_items::vvv_01_zugzwang_006,
            bn::sound_items::vvv_01_zugzwang_007,
            bn::sound_items::vvv_01_zugzwang_008,
            bn::sound_items::vvv_01_zugzwang_009,
            bn::sound_items::vvv_01_zugzwang_010,
            bn::sound_items::vvv_01_zugzwang_011,
            bn::sound_items::vvv_01_zugzwang_012,
            bn::sound_items::vvv_01_zugzwang_013,
            bn::sound_items::vvv_01_zugzwang_014,
            bn::sound_items::vvv_01_zugzwang_015};
};
*/
#endif