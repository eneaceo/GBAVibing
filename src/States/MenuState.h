#include "../core/State.h"

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