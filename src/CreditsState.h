#ifndef CREDITSTATE_H
#define CREDITSTATE_H

#include "StateBase.h"
#include "bn_string.h"

class CreditsState : public StateBase
{
public:
    CreditsState(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler);
    ~CreditsState() = default;

    void Update() override;
    void Enter() override;
    void Exit() override;

    void Back() override;

private:
    const bn::string<32> TextCredits01 = "Gracias a VVV -Trippin'you-";
    const bn::string<32> TextCredits02 = "por dejarme usar su música";
};

#endif