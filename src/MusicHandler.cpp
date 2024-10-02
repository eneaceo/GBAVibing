#include "MusicHandler.h"

void MusicHandler::Update()
{
    if (!SoundHandler.get()->active())
    {
        if (IsPlaying)
        {
            CurrentIndex++;
            if (CurrentIndex <= CurrentSongMaxIndex)
            {
                SoundHandler = AudioItems[CurrentIndex].play_with_priority(CurrentIndex);
            }
            else if (AutoPlayEnabled && CurrentSong != MaxSongs)
            {
                CurrentSong++;
                PlaySong(CurrentSong);
            }
            else
            {
                IsPlaying = false;
                PlayBackground();
            }
        }
        else if (IsPlayingBackground)
        {
            SoundHandler = bn::sound_items::loop.play(0.2);
        }
    }
}

void MusicHandler::PlaySong(int aSongNumber)
{
    IsPlayingBackground = false;
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
}

int MusicHandler::GetSongStart(const int aSongNumber) const
{
    return SongsIndexs[aSongNumber * 2];
};

int MusicHandler::GetSongEnd(const int aSongNumber) const
{
    return SongsIndexs[(aSongNumber * 2) + 1];
};

void MusicHandler::PlayBackground()
{
    if (!IsPlayingBackground)
    {
        IsPlayingBackground = true;
        SoundHandler = bn::sound_items::loop.play(0.2);
    }
}