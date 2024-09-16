#include "StateCommands.h"
#include "states/MenuState.h"

void SelectCommand::Execute(MenuState &aState)
{
    aState.Select();
}

void MenuUpCommand::Execute(MenuState &aState)
{
    aState.MenuUp();
}

void MenuDownCommand::Execute(MenuState &aState)
{
    aState.MenuDown();
}
