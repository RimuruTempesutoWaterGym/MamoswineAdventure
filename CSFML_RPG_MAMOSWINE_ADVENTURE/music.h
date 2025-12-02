#pragma once
#include "tools.h"






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