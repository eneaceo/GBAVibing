#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "MenuState.h"
#include "bn_string.h"
#include "bn_array.h"

class MainMenuState : public MenuState
{
public:
    MainMenuState();
    virtual ~MainMenuState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;
    uint8_t GetStateInfo() const override { return STATES::MAINMENU; };
    void ChangeSelectedOption(bool aChangeDirection) override;

    virtual void Select() override;
    virtual void Back() override;
    virtual void MenuUp() override;
    virtual void MenuDown() override;

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