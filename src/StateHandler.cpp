#include "StateHandler.h"
#include "MenuState.h"
#include "AlbumState.h"
#include "CreditsState.h"

void StateHandler::Update()
{
    CurrentState->Update();
}

void StateHandler::SetState(int aState)
{
    if (CurrentState != nullptr)
    {
        CurrentState->Exit();
        delete CurrentState;
    }
    switch (aState)
    {
    case STATES::MENU:
        CurrentState = new MenuState(CurrentTextGenerator, CurrentImageHandler, CurrentMusicHandler);
        break;
    case STATES::ALBUM:
        CurrentState = new AlbumState(CurrentTextGenerator, CurrentImageHandler, CurrentMusicHandler);
        break;
    case STATES::CREDITS:
        CurrentState = new CreditsState(CurrentTextGenerator, CurrentImageHandler, CurrentMusicHandler);
        break;
    default:
        break;
    }
    CurrentState->Enter();
}

void StateHandler::initialize(TextGenerator *aTextGenerator, ImageHandler *aImageHandler, MusicHandler *aMusicHandler)
{
    CurrentTextGenerator = aTextGenerator;
    CurrentImageHandler = aImageHandler;
    CurrentMusicHandler = aMusicHandler;
    SetState(STATES::MENU);
}