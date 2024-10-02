#ifndef MUSICHANDLER_H
#define MUSICHANDLER_H

#include "Album.h"
#include "bn_optional.h"

class MusicHandler
{
public:
    MusicHandler() = default;
    ~MusicHandler() = default;

    void Update();
    void PlayBackground();
    void PlaySong(int aSongNumber);
    void StopMusic();
    void AutoPlay();

    bool GetIsPlaying() const { return IsPlaying; };
    bool GetIsPlayingBackground() const { return IsPlayingBackground; };
    bool GetAutoPlayEnabled() const { return AutoPlayEnabled; };
    int GetCurrentSong() const { return CurrentSong; };

private:
    bool IsPlayingBackground = false;
    bool IsPlaying = false;
    bool AutoPlayEnabled = false;
    int CurrentSong = 0;

    int CurrentIndex = 0;
    int CurrentSongMaxIndex = 0;
    bn::optional<bn::sound_handle> SoundHandler;

    int GetSongStart(const int aSongNumber) const;
    int GetSongEnd(const int aSongNumber) const;
};

#endif