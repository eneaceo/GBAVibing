#include "MenuState.h"

class MainMenuState : public MenuState
{
public:
    MainMenuState();

    void Update() override;
    void Enter() override {};
    void Exit() override;
    void ChangeSelectedOption(bool aChangeSelectedOption) override;
    uint8_t GetStateInfo() const override { return STATES::MAINMENU; };

private:
    // Texts
    const bn::string<32> TextBandName = "VVV -Trippin'you-";
    const bn::string<32> TextAlbumName = "- Vaciador -";
    const bn::string<32> TextAlbum = "Escuchar Album";
    const bn::string<32> TextCreditos = "Créditos";
    const bn::array<bn::string<32>, 2> MenuTexts = {TextAlbum, TextCreditos};
    void SelectedText(uint8_t aSelectedOption) override;
};