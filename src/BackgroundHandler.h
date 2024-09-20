#ifndef BACKGROUNDHANDLER_H
#define BACKGROUNDHANDLER_H

#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_array.h"

#include "bn_regular_bg_items_background_0.h"
#include "bn_regular_bg_items_background_1.h"
#include "bn_regular_bg_items_background_2.h"
#include "bn_regular_bg_items_background_3.h"
#include "bn_regular_bg_items_background_4.h"
#include "bn_regular_bg_items_intro_0.h"
#include "bn_regular_bg_items_intro_1.h"
#include "bn_regular_bg_items_intro_2.h"
#include "bn_regular_bg_items_intro_3.h"
#include "bn_regular_bg_items_intro_4.h"
#include "bn_regular_bg_items_intro_5.h"
#include "bn_regular_bg_items_intro_6.h"
#include "bn_regular_bg_items_intro_7.h"
#include "bn_regular_bg_items_intro_8.h"
#include "bn_regular_bg_items_intro_9.h"
#include "bn_regular_bg_items_intro_10.h"
#include "bn_regular_bg_items_intro_11.h"
#include "bn_regular_bg_items_intro_12.h"
#include "bn_regular_bg_items_intro_13.h"
#include "bn_regular_bg_items_intro_14.h"
#include "bn_regular_bg_items_intro_15.h"
#include "bn_regular_bg_items_intro_16.h"
#include "bn_regular_bg_items_intro_17.h"
#include "bn_regular_bg_items_intro_18.h"
#include "bn_regular_bg_items_intro_19.h"
#include "bn_regular_bg_items_intro_20.h"
#include "bn_regular_bg_items_intro_21.h"
#include "bn_regular_bg_items_intro_22.h"
#include "bn_regular_bg_items_intro_23.h"
#include "bn_regular_bg_items_intro_24.h"
#include "bn_regular_bg_items_intro_25.h"
#include "bn_regular_bg_items_intro_26.h"
#include "bn_regular_bg_items_intro_27.h"
#include "bn_regular_bg_items_intro_28.h"
#include "bn_regular_bg_items_intro_29.h"
#include "bn_regular_bg_items_intro_30.h"

class BackgroundHandler
{
public:
    BackgroundHandler() = default;
    ~BackgroundHandler() = default;

    void Update();
    void LoadBackground(bn::regular_bg_item aBackground);
    void AnimateBackground();
    void PlayIntro();
    void ResetBackground();

private:

    uint16_t CurrentFrame = 0;
    const uint16_t AnimationSpeed = 5;

    bn::optional<bn::regular_bg_ptr> Background;

    const bn::array<bn::regular_bg_item, 5> BackgroundItems =
        {
            bn::regular_bg_items::background_0,
            bn::regular_bg_items::background_1,
            bn::regular_bg_items::background_2,
            bn::regular_bg_items::background_3,
            bn::regular_bg_items::background_4};

    const bn::array<bn::regular_bg_item, 31> IntroItems =
        {
            bn::regular_bg_items::intro_0,
            bn::regular_bg_items::intro_1,
            bn::regular_bg_items::intro_2,
            bn::regular_bg_items::intro_3,
            bn::regular_bg_items::intro_4,
            bn::regular_bg_items::intro_5,
            bn::regular_bg_items::intro_6,
            bn::regular_bg_items::intro_7,
            bn::regular_bg_items::intro_8,
            bn::regular_bg_items::intro_9,
            bn::regular_bg_items::intro_10,
            bn::regular_bg_items::intro_11,
            bn::regular_bg_items::intro_12,
            bn::regular_bg_items::intro_13,
            bn::regular_bg_items::intro_14,
            bn::regular_bg_items::intro_15,
            bn::regular_bg_items::intro_16,
            bn::regular_bg_items::intro_17,
            bn::regular_bg_items::intro_18,
            bn::regular_bg_items::intro_19,
            bn::regular_bg_items::intro_20,
            bn::regular_bg_items::intro_21,
            bn::regular_bg_items::intro_22,
            bn::regular_bg_items::intro_23,
            bn::regular_bg_items::intro_24,
            bn::regular_bg_items::intro_25,
            bn::regular_bg_items::intro_26,
            bn::regular_bg_items::intro_27,
            bn::regular_bg_items::intro_28,
            bn::regular_bg_items::intro_29,
            bn::regular_bg_items::intro_30};
};

#endif