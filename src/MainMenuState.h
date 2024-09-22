#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "bn_string.h"
#include "bn_array.h"
#include "bn_optional.h"
#include "bn_sound_items.h"

class MainMenuState : public State
{
public:
    MainMenuState();
    ~MainMenuState() = default;

    void Update() override;
    void Enter(const bool aReset) override;
    void Exit() override;
    void Select() override;
    void MenuUp() override;
    void MenuDown() override;

private:
    // Texts
    const bn::string<32> TextBandName = "VVV -Trippin'you-";
    const bn::string<32> TextAlbumName = "- Vaciador -";
    const bn::string<32> TextAlbum = "Escuchar Album";
    const bn::string<32> TextCreditos = "Créditos";
    const bn::array<bn::string<32>, 2> MenuTexts = {TextAlbum, TextCreditos};
    const uint8_t TextSeparation = 15;

    bn::optional<bn::sound_handle> SoundHandler;
};

#endif