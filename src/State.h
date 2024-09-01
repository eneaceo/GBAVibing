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
    void Exit() override {};
    void ChangeSelectedOption(bool aChangeSelectedOption) override;

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

    void Update() override {};
    void Enter() override {};
    void Exit() override {};
    void ChangeSelectedOption(bool aChangeSelectedOption) override {};

private:
    bn::sprite_text_generator TextGenerator;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;
    bn::optional<bn::regular_bg_ptr> ImageOptional;
    uint8_t TextSeparation = 15;
    
    void SelectedText(uint8_t aSelectedOption) override {};
};

#endif