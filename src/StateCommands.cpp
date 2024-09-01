#include "StateCommands.h"
#include "StateStack.h"
#include "Actor.h"

void NextStateCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack &>(aActor);
    aStateStack.AdvanceState();
}

void PreviousStateCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack &>(aActor);
    aStateStack.PreviousState();
}

void MenuUpCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack &>(aActor);
    aStateStack.GetCurrentState()->ChangeSelectedOption(true);
}

void MenuDownCommand::Execute(Actor &aActor)
{
    StateStack &aStateStack = static_cast<StateStack &>(aActor);
    aStateStack.GetCurrentState()->ChangeSelectedOption(false);
}
