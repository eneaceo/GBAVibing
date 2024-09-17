#ifndef ALBUMSTATE_H
#define ALBUMSTATE_H

#include "MusicHandler.h"
#include "State.h"
#include "bn_string.h"
#include "bn_array.h"
#include "bn_sound_items.h"

class AlbumMenuState : public State
{
public:
    AlbumMenuState();
    ~AlbumMenuState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;
    void Select() override;
    void Back() override;
    void MenuUp() override;
    void MenuDown() override;

private:
    MusicHandler MusicManager;

    // Texts
    const bn::string<32> VVV01 = "Zugzwang";
    const bn::string<32> VVV02 = "El Ángel de la Historia";
    const bn::string<32> VVV03 = "Mediocres y Agresivos";
    const bn::string<32> VVV04 = "Hikutsu";
    const bn::string<32> VVV05 = "Rush";
    const bn::string<32> VVV06 = "Bellver";
    const bn::string<32> VVV07 = "KLF";
    const bn::string<32> VVV08 = "La Grieta";
    const bn::string<32> VVV09 = "Ctrl + Alt + Supr";
    const bn::array<bn::string<32>, 9> AlbumTexts = {VVV01, VVV02, VVV03, VVV04, VVV05, VVV06, VVV07, VVV08, VVV09};
    const uint8_t TextSeparation = 15;

    bool IsPlaying = false;

    // TODO Music Component
    const bn::array<uint8_t, 18> SongsIndexs =
        {
            0, 15,
            16, 33,
            34, 47,
            48, 61,
            62, 76,
            77, 91,
            92, 106,
            107, 125,
            126, 133};

    const bn::array<uint16_t, 9> SongFrames =
        {
            14160,
            16080,
            12480,
            12000,
            13380,
            13080,
            14400,
            16200,
            7140};

    const bn::array<bn::sound_item, 134> AudioItems =
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
            bn::sound_items::vvv_01_zugzwang_015,
            // 16 - 33
            bn::sound_items::vvv_02_elangeldelahistoria_000,
            bn::sound_items::vvv_02_elangeldelahistoria_001,
            bn::sound_items::vvv_02_elangeldelahistoria_002,
            bn::sound_items::vvv_02_elangeldelahistoria_003,
            bn::sound_items::vvv_02_elangeldelahistoria_004,
            bn::sound_items::vvv_02_elangeldelahistoria_005,
            bn::sound_items::vvv_02_elangeldelahistoria_006,
            bn::sound_items::vvv_02_elangeldelahistoria_007,
            bn::sound_items::vvv_02_elangeldelahistoria_008,
            bn::sound_items::vvv_02_elangeldelahistoria_009,
            bn::sound_items::vvv_02_elangeldelahistoria_010,
            bn::sound_items::vvv_02_elangeldelahistoria_011,
            bn::sound_items::vvv_02_elangeldelahistoria_012,
            bn::sound_items::vvv_02_elangeldelahistoria_013,
            bn::sound_items::vvv_02_elangeldelahistoria_014,
            bn::sound_items::vvv_02_elangeldelahistoria_015,
            bn::sound_items::vvv_02_elangeldelahistoria_016,
            bn::sound_items::vvv_02_elangeldelahistoria_017,
            // 34 - 47
            bn::sound_items::vvv_03_mediocresyagresivos_000,
            bn::sound_items::vvv_03_mediocresyagresivos_001,
            bn::sound_items::vvv_03_mediocresyagresivos_002,
            bn::sound_items::vvv_03_mediocresyagresivos_003,
            bn::sound_items::vvv_03_mediocresyagresivos_004,
            bn::sound_items::vvv_03_mediocresyagresivos_005,
            bn::sound_items::vvv_03_mediocresyagresivos_006,
            bn::sound_items::vvv_03_mediocresyagresivos_007,
            bn::sound_items::vvv_03_mediocresyagresivos_008,
            bn::sound_items::vvv_03_mediocresyagresivos_009,
            bn::sound_items::vvv_03_mediocresyagresivos_010,
            bn::sound_items::vvv_03_mediocresyagresivos_011,
            bn::sound_items::vvv_03_mediocresyagresivos_012,
            bn::sound_items::vvv_03_mediocresyagresivos_013,
            // 48 - 61
            bn::sound_items::vvv_04_hikutsu_000,
            bn::sound_items::vvv_04_hikutsu_001,
            bn::sound_items::vvv_04_hikutsu_002,
            bn::sound_items::vvv_04_hikutsu_003,
            bn::sound_items::vvv_04_hikutsu_004,
            bn::sound_items::vvv_04_hikutsu_005,
            bn::sound_items::vvv_04_hikutsu_006,
            bn::sound_items::vvv_04_hikutsu_007,
            bn::sound_items::vvv_04_hikutsu_008,
            bn::sound_items::vvv_04_hikutsu_009,
            bn::sound_items::vvv_04_hikutsu_010,
            bn::sound_items::vvv_04_hikutsu_011,
            bn::sound_items::vvv_04_hikutsu_012,
            bn::sound_items::vvv_04_hikutsu_013,
            // 62 - 76
            bn::sound_items::vvv_05_rush_000,
            bn::sound_items::vvv_05_rush_001,
            bn::sound_items::vvv_05_rush_002,
            bn::sound_items::vvv_05_rush_003,
            bn::sound_items::vvv_05_rush_004,
            bn::sound_items::vvv_05_rush_005,
            bn::sound_items::vvv_05_rush_006,
            bn::sound_items::vvv_05_rush_007,
            bn::sound_items::vvv_05_rush_008,
            bn::sound_items::vvv_05_rush_009,
            bn::sound_items::vvv_05_rush_010,
            bn::sound_items::vvv_05_rush_011,
            bn::sound_items::vvv_05_rush_012,
            bn::sound_items::vvv_05_rush_013,
            bn::sound_items::vvv_05_rush_014,
            // 77 - 91
            bn::sound_items::vvv_06_bellver_000,
            bn::sound_items::vvv_06_bellver_001,
            bn::sound_items::vvv_06_bellver_002,
            bn::sound_items::vvv_06_bellver_003,
            bn::sound_items::vvv_06_bellver_004,
            bn::sound_items::vvv_06_bellver_005,
            bn::sound_items::vvv_06_bellver_006,
            bn::sound_items::vvv_06_bellver_007,
            bn::sound_items::vvv_06_bellver_008,
            bn::sound_items::vvv_06_bellver_009,
            bn::sound_items::vvv_06_bellver_010,
            bn::sound_items::vvv_06_bellver_011,
            bn::sound_items::vvv_06_bellver_012,
            bn::sound_items::vvv_06_bellver_013,
            bn::sound_items::vvv_06_bellver_014,
            // 92 - 106
            bn::sound_items::vvv_07_klf_000,
            bn::sound_items::vvv_07_klf_001,
            bn::sound_items::vvv_07_klf_002,
            bn::sound_items::vvv_07_klf_003,
            bn::sound_items::vvv_07_klf_004,
            bn::sound_items::vvv_07_klf_005,
            bn::sound_items::vvv_07_klf_006,
            bn::sound_items::vvv_07_klf_007,
            bn::sound_items::vvv_07_klf_008,
            bn::sound_items::vvv_07_klf_009,
            bn::sound_items::vvv_07_klf_010,
            bn::sound_items::vvv_07_klf_011,
            bn::sound_items::vvv_07_klf_012,
            bn::sound_items::vvv_07_klf_013,
            bn::sound_items::vvv_07_klf_014,
            // 107 - 125
            bn::sound_items::vvv_08_lagrieta_000,
            bn::sound_items::vvv_08_lagrieta_001,
            bn::sound_items::vvv_08_lagrieta_002,
            bn::sound_items::vvv_08_lagrieta_003,
            bn::sound_items::vvv_08_lagrieta_004,
            bn::sound_items::vvv_08_lagrieta_005,
            bn::sound_items::vvv_08_lagrieta_006,
            bn::sound_items::vvv_08_lagrieta_007,
            bn::sound_items::vvv_08_lagrieta_008,
            bn::sound_items::vvv_08_lagrieta_009,
            bn::sound_items::vvv_08_lagrieta_010,
            bn::sound_items::vvv_08_lagrieta_011,
            bn::sound_items::vvv_08_lagrieta_012,
            bn::sound_items::vvv_08_lagrieta_013,
            bn::sound_items::vvv_08_lagrieta_014,
            bn::sound_items::vvv_08_lagrieta_015,
            bn::sound_items::vvv_08_lagrieta_016,
            bn::sound_items::vvv_08_lagrieta_017,
            bn::sound_items::vvv_08_lagrieta_018,
            // 126 - 133
            bn::sound_items::vvv_09_ctrlaltsupr_000,
            bn::sound_items::vvv_09_ctrlaltsupr_001,
            bn::sound_items::vvv_09_ctrlaltsupr_002,
            bn::sound_items::vvv_09_ctrlaltsupr_003,
            bn::sound_items::vvv_09_ctrlaltsupr_004,
            bn::sound_items::vvv_09_ctrlaltsupr_005,
            bn::sound_items::vvv_09_ctrlaltsupr_006,
            bn::sound_items::vvv_09_ctrlaltsupr_007};
};

#endif