#ifndef BACKGROUNDHANDLER_H
#define BACKGROUNDHANDLER_H

#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_array.h"
#include "bn_random.h"

#include "bn_regular_bg_items_background_0.h"
#include "bn_regular_bg_items_background_1.h"
#include "bn_regular_bg_items_background_2.h"
#include "bn_regular_bg_items_background_3.h"
#include "bn_regular_bg_items_background_4.h"

class BackgroundHandler
{
public:
    BackgroundHandler() = default;
    ~BackgroundHandler() = default;

    void Update();
    void LoadBackground(bn::regular_bg_item aBackground);
    void AnimateBackground();
    void ResetBackground();
    void SetAnimationSpeed(uint8_t aSpeed) { AnimationSpeed = aSpeed; };

private:
    uint8_t BackgroundIndex = 0;
    uint8_t Counter = 0;
    uint8_t AnimationSpeed = 5;
    bn::random Random;
    bn::optional<bn::regular_bg_ptr> Background;

    const bn::array<bn::regular_bg_item, 5> BackgroundItems =
        {
            bn::regular_bg_items::background_0,
            bn::regular_bg_items::background_1,
            bn::regular_bg_items::background_2,
            bn::regular_bg_items::background_3,
            bn::regular_bg_items::background_4};
};

#endif