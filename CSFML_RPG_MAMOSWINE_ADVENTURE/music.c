#include "music.h"
sfMusic* music;
void initMusic()
{
	if(state == MENU)
	{ 
	music = sfMusic_createFromFile("..\\Ressources\\Musics\\Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	}
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
}

void volumMusic(float _volume)
{
	sfMusic_setVolume(music, _volume);
}
