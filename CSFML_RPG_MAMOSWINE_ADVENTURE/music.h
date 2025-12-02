#pragma once
#include "tools.h"
#pragma once






void initMusic();

typedef enum {
	Menu, Overworld, Fire, Water, Grass, Elec,
}MusicChoice;
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