#include "MenuState.h"
#include "bn_sprite_items_variable_8x16_font_red.h"
#include "bn_regular_bg_items_background.h"
#include "bn_math.h"

void MenuState::TextWiggle(const uint8_t aSelectedOption, const int8_t aPositionOffset)
{
    Angle -= AngleIncrement;

    if (Angle == 0)
    {
        Angle += 360;
    }

    bn::fixed LocalAngle = Angle;

    for (bn::sprite_ptr &SelectedTextSprite : SelectedTextSprites)
    {
        LocalAngle += AngleIncrement * 4;

        if (LocalAngle >= 360)
        {
            LocalAngle -= 360;
        }

        SelectedTextSprite.set_y(aPositionOffset + aSelectedOption * TextSeparation + bn::degrees_lut_sin(LocalAngle) * 2);
    }
}