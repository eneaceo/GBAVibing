#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "bn_string.h"
#include "bn_array.h"

class MainMenuState : public State
{
public:
    MainMenuState();
    ~MainMenuState() = default;

    void Update() override;
    void Enter() override;
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
};

#endif