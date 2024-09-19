#include "MusicHandler.h"
#include "AlbumMenuState.h"
#include "bn_sound_actions.h"

void MusicHandler::Update()
{
    if (IsPlaying)
    {
        CurrentFrame++;
        if (CurrentFrame == MaxIndexFrames)
        {
            CurrentFrame = 0;
            CurrentIndex++;
            if (CurrentIndex <= CurrentSongMaxIndex)
            {
                SoundHandler = AudioItems[CurrentIndex].play();
            }
            else if (AutoPlayEnabled && CurrentSong + 1 < MaxSongs)
            {
                CurrentSong++;
                PlayMusic(CurrentSong);
            }
            else
            {
                SetIsPlaying(false);
            }
        }
    }
}

void MusicHandler::SetIsPlaying(bool aIsPlaying)
{
    IsPlaying = aIsPlaying;
    NotifyPlaying();
};

void MusicHandler::PlayMusic(uint8_t aSongNumber)
{
    CurrentSong = aSongNumber;
    CurrentFrame = 0;
    CurrentIndex = GetSongStart(aSongNumber);
    CurrentSongMaxIndex = GetSongEnd(aSongNumber);
    SoundHandler = AudioItems[CurrentIndex].play();
    NotifySelectedOption();
    SetIsPlaying(true);
}

void MusicHandler::StopMusic()
{
    SetIsPlaying(false);
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