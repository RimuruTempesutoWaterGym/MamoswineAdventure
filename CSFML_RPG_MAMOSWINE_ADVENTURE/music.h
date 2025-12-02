#include "tools.h"
#pragma once


typedef enum {
	Menu, Overworld, Fire, Water, Grass, Elec
}Music;
Music music;


void initMusic();
void initSound();
void volumeMusic(float _volume);
void setMusic(int* _music);
void playSoundAttack();
void playSoundBoulder();
void playSoundTree();
void soundMute();
void soundUnmute();
void changeMusic();
void updateMusic(int* chosedMusic);
sfMusic* getActualMusic();