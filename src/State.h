#ifndef STATE_H
#define STATE_H

#include "bn_array.h"
#include "bn_string.h"
#include "bn_vector.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_items_variable_8x16_font_red.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_regular_bg_item.h"

class State
{
public:
    virtual ~State() = default;
    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual void ChangeSelectedOption(bool aChangeSelectedOption) = 0;
    virtual uint8_t GetState() const = 0;
    
    enum STATES
    {
        NONE,
        MAINMENU,
        ALBUMMENU
    };

protected:
    uint8_t SelectedOption = 0;
    virtual void SelectedText(uint8_t aSelectedOption) = 0;
};

class MainMenuState : public State
{
public:
    MainMenuState();

    void Update() override;
    void Enter() override {};
    void Exit() override;
    void ChangeSelectedOption(bool aChangeSelectedOption) override;
    uint8_t GetState() const override { return STATES::MAINMENU; };

private:
    // Texts
    const bn::string<32> TextBandName = "VVV -Trippin'you-";
    const bn::string<32> TextAlbumName = "- Vaciador -";
    const bn::string<32> TextAlbum = "Escuchar Album";
    const bn::string<32> TextCreditos = "Créditos";
    const bn::array<bn::string<32>, 2> MenuTexts = {TextAlbum, TextCreditos};

    bn::sprite_text_generator TextGenerator;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;
    bn::optional<bn::regular_bg_ptr> ImageOptional;
    uint8_t TextSeparation = 15;
    void SelectedText(uint8_t aSelectedOption) override;
};

class AlbumMenuState : public State
{
public:
    AlbumMenuState();

    void Update() override;
    void Enter() override {};
    void Exit() override;
    void ChangeSelectedOption(bool aChangeSelectedOption) override;
    uint8_t GetState() const override { return STATES::ALBUMMENU; };

private:
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

    bn::sprite_text_generator TextGenerator;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;
    bn::optional<bn::regular_bg_ptr> ImageOptional;
    uint8_t TextSeparation = 15;
    void SelectedText(uint8_t aSelectedOption) override;
};

#endif