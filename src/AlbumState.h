#ifndef ALBUMSTATE_H
#define ALBUMSTATE_H

#include "StateBase.h"
#include "bn_string.h"
#include "bn_array.h"


class AlbumState : public StateBase
{
public:
    AlbumState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler);
    ~AlbumState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;

    void Select() override;
    void Back() override;
    void MenuUp() override;
    void MenuDown() override;
    void Auto() override;

private:
    const uint8_t TextSeparation = 15;
    const bn::array<bn::string<32>, 9> AlbumTexts = {"Zugzwang", "El Ángel de la Historia", 
        "Mediocres y Agresivos", "Hikutsu", "Rush", "Bellver", "KLF", "La Grieta", "Ctrl + Alt + Supr"};
};

#endif