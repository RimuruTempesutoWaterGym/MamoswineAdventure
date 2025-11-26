#include "music.h"
sfMusic* playedMusic;
void initMusic()
{
	if(state == MENU)
	{ 
		setMusic("Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	}
	sfMusic_setLoop(playedMusic, sfTrue);
	sfMusic_play(playedMusic);
}

void volumeMusic(float _volume)
{
	sfMusic_setVolume(playedMusic, _volume);
}

void setMusic()
{
	switch (music)
	{
	case Menu:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Overworld:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Fire:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Water:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Grass:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Elec:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	}
}
