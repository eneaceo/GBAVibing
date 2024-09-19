#ifndef MUSICHANDLER_H
#define MUSICHANDLER_H

#include "bn_sound_items.h"
#include "bn_array.h"
#include "bn_optional.h"

class AlbumMenuState;

class MusicHandler
{
public:
    MusicHandler();
    ~MusicHandler() = default;

    void Update();
    void PlayMusic(uint8_t aSongNumber);
    void StopMusic();
    bool GetIsPlaying() const { return IsPlaying; };
    void AutoPlay();

private:
    bool IsPlaying = false;
    bool AutoPlayEnabled = false;
    uint16_t CurrentSong = 0;
    uint16_t CurrentFrame = 0;
    uint16_t CurrentIndex = 0;
    uint16_t CurrentSongMaxIndex = 0;
    bn::optional<bn::sound_handle> SoundHandler;

    uint8_t GetSongStart(const uint8_t aSongNumber) const;
    uint8_t GetSongEnd(const uint8_t aSongNumber) const;

    uint8_t MaxSongs;
    uint16_t MaxIndexFrames;
    bn::array<uint8_t, 18> SongsIndexs;
    bn::array<bn::sound_item, 134> AudioItems;
};

#endif