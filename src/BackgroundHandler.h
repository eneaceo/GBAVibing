#ifndef BACKGROUNDHANDLER_H
#define BACKGROUNDHANDLER_H

#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

class BackgroundHandler {
public:
    BackgroundHandler() = default;
    ~BackgroundHandler() = default;

    void Update();
    void LoadBackground(bn::regular_bg_item aBackground);
    void ResetBackground();

private:
    bn::optional<bn::regular_bg_ptr> Background;
    
};

#endif