#include "StateCommands.h"
#include "StateStack.h"
#include "Actor.h"

void NextStateCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack&>(aActor);
    aStateStack.AdvanceState();
}

void PreviousStateCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack&>(aActor);
    aStateStack.PreviousState();
}

#include "bn_bg_palettes.h"
#include "bn_color.h"

void MenuUpCommand::Execute(Actor &aActor)
{
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
}

void MenuDownCommand::Execute(Actor &aActor)
{
    bn::bg_palettes::set_transparent_color(bn::color(31, 31, 31));
}
