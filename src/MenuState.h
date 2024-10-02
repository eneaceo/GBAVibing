#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "StateBase.h"
#include "bn_string.h"
#include "bn_array.h"

class MenuState : public StateBase
{
public:
    MenuState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler);
    ~MenuState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;

    void Select() override;
    void MenuUp() override;
    void MenuDown() override;

private:

    const bn::string<32> TextBandName = "VVV -Trippin'you-";
    const bn::string<32> TextAlbumName = "- Vaciador -";

    const int TextSeparation = 15;
    const bn::array<bn::string<32>, 2> MenuTexts = {"Escuchar Album", "Créditos"};
    
};

#endif