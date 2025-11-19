#include "music.h"

void initMusic()
{
	sfMusic* music = sfMusic_createFromFile("..\\Ressources\\Musics\\Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
}
