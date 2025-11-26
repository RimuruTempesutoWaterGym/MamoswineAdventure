#include "music.h"
sfMusic* music;
void initMusic()
{
	if(state == MENU)
	{ 
	music = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
	}
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
}

void volumeMusic(float _volume)
{
	sfMusic_setVolume(music, _volume);
}

void setMusic(char _music)
{
	_music = MUSIC_PATH + _music;
	music = sfMusic_createFromFile(_music);
}
