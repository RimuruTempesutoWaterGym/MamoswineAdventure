#include "music.h"


sfMusic* playedMusic;
float actualVolume =100;



void initMusic()
{
	if(state == MENU)
	{ 
		setMusic(Menu);
	}
	sfMusic_setLoop(playedMusic, sfTrue);
	sfMusic_play(playedMusic);
}

void volumeMusic(float _volume)
{
	actualVolume += _volume;
	sfMusic_setVolume(playedMusic, actualVolume);
}

sfMusic* getActualMusic()
{
	return playedMusic;
}
void setMusic(Music _music)
{
	music = _music;
	switch (music)
	{
	case Menu:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
		break;
	case Overworld:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		break;
	case Fire:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu -Combat contre Noctunoir !.mp3");
		break;
		//"area-feu -Combat contre Noctunoir !.mp3"
		//"area-feu -Maison de Monstres ! [TubeRipper.cc].mp3"
	case Water:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		break;
		//"area-eau -Grotte Cascade [TubeRipper.cc].mp3"
		//"area-eau -Grotte et Chemin Lisi�re [TubeRipper.cc].mp3"
		//"area-eau -Lake HD [TubeRipper.cc].mp3"
	case Grass:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		break;
		//"area-plante -Grotte Ab�me [TubeRipper.cc].mp3"
	case Elec:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		break;
		//"area-elek -Grotte Sables Mouvants [TubeRipper.cc].mp3"
		//"area-elek -Mt H�riss� [TubeRipper.cc].mp3"
		//"area-elek -Plaines Elek [TubeRipper.cc].mp3"
	}
}