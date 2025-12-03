#pragma once
#include "tools.h"







void initMusic();

typedef enum {
    MUSIC_Menu,
    MUSIC_Overworld,
    MUSIC_Fire,
    MUSIC_Water,
    MUSIC_Grass,
    MUSIC_Elec,
    MUSIC_Void
}MusicChoice;
void ChangeMusic(MusicChoice _music);
void initSound();
void volumeMusic(float _volume);
void setMusic(MusicChoice _music);
void playSoundAttack();
void playSoundBoulder();
void playSoundTree();
void soundMute();
void soundUnmute();
void changeMusic();
void updateMusic();
sfMusic* getActualMusic();
MusicChoice getOldMusic();
void setVolumeIfNotMuted(sfMusic* _music, float _volume);
void setVolumeSFXIfNotMuted(sfSound* _sfx, float _volume);