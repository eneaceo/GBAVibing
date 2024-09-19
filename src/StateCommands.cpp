#include "StateCommands.h"
#include "State.h"

void SelectCommand::Execute(State &aState)
{
    aState.Select();
}

void BackCommand::Execute(State &aState)
{
    aState.Back();
}

void MenuUpCommand::Execute(State &aState)
{
    aState.MenuUp();
}

void MenuDownCommand::Execute(State &aState)
{
    aState.MenuDown();
}

void AutoCommand::Execute(State &aState)
{
    aState.Auto();
}