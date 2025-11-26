#include "music.h"


sfMusic* playedMusic;



void initMusic()
{
	if(state == MENU)
	{ 
		music = Menu;
		setMusic();
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
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
	case Overworld:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	case Fire:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		//"area-feu -Combat contre Noctunoir !.mp3"
		//"area-feu -Maison de Monstres ! [TubeRipper.cc].mp3"
	case Water:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		//"area-eau -Grotte Cascade [TubeRipper.cc].mp3"
		//"area-eau -Grotte et Chemin Lisière [TubeRipper.cc].mp3"
		//"area-eau -Lake HD [TubeRipper.cc].mp3"
	case Grass:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		//"area-plante -Grotte Abîme [TubeRipper.cc].mp3"
	case Elec:
		playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
		//"area-elek -Grotte Sables Mouvants [TubeRipper.cc].mp3"
		//"area-elek -Mt Hérissé [TubeRipper.cc].mp3"
		//"area-elek -Plaines Elek [TubeRipper.cc].mp3"
	}
}