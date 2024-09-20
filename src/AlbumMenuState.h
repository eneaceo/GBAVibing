#ifndef ALBUMSTATE_H
#define ALBUMSTATE_H

#include "MusicHandler.h"
#include "Observer.h"
#include "bn_unique_ptr.h"
#include "State.h"
#include "bn_string.h"
#include "bn_array.h"

class AlbumMenuState : public State, public Observer
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
    void Auto() override;

    void UpdateSelectedOption() override;
    void UpdateAutoPlay() override;

private:
    bn::unique_ptr<MusicHandler> MusicManager;

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
};

#endif