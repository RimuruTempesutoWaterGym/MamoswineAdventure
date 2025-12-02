#include "tools.h"


<<<<<<< HEAD
void initMusic();
void volumMusic(float _volume);
=======
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
>>>>>>> main
