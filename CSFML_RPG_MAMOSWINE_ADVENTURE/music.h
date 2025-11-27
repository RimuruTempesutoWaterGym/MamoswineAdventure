#include "tools.h"


typedef enum {
	Menu, Overworld, Fire, Water, Grass, Elec
}Music;
Music music;


void initMusic();
void volumeMusic(float _volume);
void setMusic(Music _music);