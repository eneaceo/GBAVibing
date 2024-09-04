#include "StateCommands.h"
#include "StateStack.h"

void NextStateCommand::Execute(StateStack &aStateStack)
{
    aStateStack.AdvanceState();
}

void PreviousStateCommand::Execute(StateStack &aStateStack)
{
    aStateStack.PreviousState();
}

void MenuUpCommand::Execute(StateStack &aStateStack)
{
    aStateStack.MenuUp();
}

void MenuDownCommand::Execute(StateStack &aStateStack)
{
    aStateStack.MenuDown();
}
