#ifndef STATE_H
#define STATE_H

#include "bn_array.h"
#include "bn_string.h"
#include "bn_vector.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sound_handle.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_items_variable_8x16_font_red.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_regular_bg_item.h"
#include "bn_sound_items.h"

#include "InputHandler.h"
#include "StateCommands.h"

class State
{
public:
    enum STATES
    {
        NONE,
        MAINMENU,
        CREDITS,
        ALBUMMENU,
        PLAYINGSONG
    };
    State()
    {
        InputManager = std::make_unique<InputHandler>();
        InputManager->BindButton(InputHandler::BUTTONS::A, std::make_unique<SelectCommand>());
        //InputManager->BindButton(InputHandler::BUTTONS::B, std::make_unique<PreviousStateCommand>());
        InputManager->BindButton(InputHandler::BUTTONS::UP, std::make_unique<MenuUpCommand>());
        InputManager->BindButton(InputHandler::BUTTONS::DOWN, std::make_unique<MenuDownCommand>());
    };
    virtual ~State() = default;
    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual uint8_t GetStateInfo() const = 0;

private:
    std::unique_ptr<InputHandler> InputManager;
};

class MenuState : public State
{
public:
    MenuState() : State(), TextGenerator(common::variable_8x16_sprite_font) {};
    virtual ~MenuState() = default;

    virtual void Update() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual uint8_t GetStateInfo() const = 0;
    virtual void ChangeSelectedOption(bool aChangeSelectedOption) = 0;
    uint8_t GetSelectedOption() { return SelectedOption; };
    void Select(){};
    void MenuUp(){};
    void MenuDown(){};

protected:
    // TODO Text component
    uint8_t SelectedOption = 0;
    virtual void SelectedText(uint8_t aSelectedOption) = 0;
    bn::sprite_text_generator TextGenerator;
    bn::vector<bn::sprite_ptr, 32> TextSprites;
    bn::vector<bn::sprite_ptr, 32> SelectedTextSprites;
    bn::optional<bn::regular_bg_ptr> ImageOptional;
    uint8_t TextSeparation = 15;
    void TextWiggle(const uint8_t aSelectedOption, const int8_t aPositionOffset = 0);
    bn::fixed Angle = 360;
    const bn::fixed AngleIncrement = 4;
};

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

class AlbumMenuState : public MenuState
{
public:
    AlbumMenuState();

    void Update() override;
    void Enter() override {};
    void Exit() override;
    void ChangeSelectedOption(bool aChangeSelectedOption) override;
    uint8_t GetStateInfo() const override { return STATES::ALBUMMENU; };

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
    void SelectedText(uint8_t aSelectedOption) override;
};

class CreditsState : public State
{
public:
    CreditsState() : State() {};

    void Update() override {};
    void Enter() override {};
    void Exit() override {};
    uint8_t GetStateInfo() const override { return STATES::CREDITS; };
};

class PlayingSongState : public State
{
public:
    PlayingSongState() : State() { SoundHandler = AudioItems[AudioCounter].play(); };

    void Update() override;
    void Enter() override {};
    void Exit() override {};
    uint8_t GetStateInfo() const override { return STATES::PLAYINGSONG; };

private:
    // TODO Music component
    bn::optional<bn::sound_handle> SoundHandler;
    uint8_t AudioCounter = 0;

    const bn::array<bn::sound_item, 16> AudioItems =
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
            bn::sound_items::vvv_01_zugzwang_015};
};

#endif