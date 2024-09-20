#include "MusicHandler.h"
#include "AlbumMenuState.h"
#include "bn_sound_actions.h"

void MusicHandler::Update()
{
    if (IsPlaying && !SoundHandler.get()->active())
    {
        CurrentIndex++;
        if (CurrentIndex <= CurrentSongMaxIndex)
        {
            SoundHandler = AudioItems[CurrentIndex].play_with_priority(CurrentIndex);
        }
        else if (AutoPlayEnabled && CurrentSong != MaxSongs)
        {
            CurrentSong++;
            PlayMusic(CurrentSong);
            NotifySelectedOption();
        }
        else
        {
            IsPlaying = false;
        }
    }
}

void MusicHandler::PlayMusic(uint8_t aSongNumber)
{
    SoundHandler.get()->stop();
    CurrentSong = aSongNumber;
    CurrentIndex = GetSongStart(aSongNumber);
    CurrentSongMaxIndex = GetSongEnd(aSongNumber);
    SoundHandler = AudioItems[CurrentIndex].play();
    IsPlaying = true;
}

void MusicHandler::StopMusic()
{
    IsPlaying = false;
    SoundHandler.get()->stop();
}

void MusicHandler::AutoPlay()
{
    AutoPlayEnabled = !AutoPlayEnabled;
    NotifyAutoPlay();
}

uint8_t MusicHandler::GetSongStart(const uint8_t aSongNumber) const
{
    return SongsIndexs[aSongNumber * 2];
};

uint8_t MusicHandler::GetSongEnd(const uint8_t aSongNumber) const
{
    return SongsIndexs[(aSongNumber * 2) + 1];
};

void MusicHandler::Attach(Observer *aObserver)
{
    MusicObserver = bn::unique_ptr<Observer>(aObserver);
}

void MusicHandler::NotifySelectedOption()
{
    MusicObserver->UpdateSelectedOption();
};

void MusicHandler::NotifyAutoPlay()
{
    MusicObserver->UpdateAutoPlay();
};