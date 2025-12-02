#include"tools.h"
#include "music.h"


sfMusic* playedMusic;
sfSoundBuffer* attackMamoBuffer;
sfSoundBuffer* boulderPushBuffer;
sfSoundBuffer* treeCutBuffer;
sfSound* attackMamo;
sfSound* boulderPush;
sfSound* treeCut;
float actualVolume;
float maxVolume;
float timerLerp = 0;
int BackSound = 0;
int isMuted;
int hasChanged= 0;
int musicUp = 0;
MusicChoice oldMusic = 0;
MusicChoice actualMusic = 0;


void initMusic()
{
	actualVolume = 10.f;
	maxVolume = 100.0f;
	playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
	setMusic(Menu);
	
	sfMusic_setLoop(playedMusic, sfTrue);
	sfMusic_play(playedMusic);

}

void initSound()
{
	attackMamo = sfSound_create();
	boulderPush = sfSound_create();
	treeCut = sfSound_create();
	attackMamoBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\Alerte Chemin Ouvert.ogg");
	boulderPushBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\bad_end.ogg");
	treeCutBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\Décompte 2.ogg");
	sfSound_setBuffer(attackMamo, attackMamoBuffer);
	sfSound_setBuffer(boulderPush, boulderPushBuffer);
	sfSound_setBuffer(treeCut, treeCutBuffer);
}
void setVolumeMusicIfNotMuted(sfMusic* _music, float _volume)
{

	if (isMuted == 0)
	{
		sfMusic_setVolume(_music, _volume);
	}
	if (isMuted == 1)
	{
		sfMusic_setVolume(_music, 0);
	}
}
void setVolumeSFXIfNotMuted(sfSound* _sfx, float _volume)
{
	if (isMuted == 0)
	{
		sfSound_setVolume(_sfx, _volume);
	}
	if (isMuted == 1)
	{
		_volume = 0.0f;
	}
}
void volumeMusic(float _volume)
{
	maxVolume += _volume;
	actualVolume = maxVolume
	setVolumeMusicIfNotMuted(playedMusic, maxVolume);
	setVolumeSFXIfNotMuted(attackMamo, maxVolume);
	setVolumeSFXIfNotMuted(boulderPush, maxVolume);
	setVolumeSFXIfNotMuted(treeCut, maxVolume);
	
}



sfMusic* getActualMusic()
{
	return playedMusic;
}
void updateMusic()
{
	setMusic(getOldMusic());
}
void setMusic(MusicChoice _music)
{
	
	if (oldMusic != _music || hasChanged == 1)
	{
		if (actualVolume >= 1 && BackSound == 0)
		{
			actualVolume -= LERP_F(0, maxVolume,GetDeltaTime() * 0.3) ;
			setVolumeMusicIfNotMuted(playedMusic, actualVolume);
			
		}
		hasChanged = 1;
		
		if ((actualVolume <= 1) && actualVolume < maxVolume || BackSound == 1)
		{
			BackSound = 1;
			actualVolume += LERP_F(0, maxVolume, GetDeltaTime() * 0.3);

			setVolumeMusicIfNotMuted(playedMusic, actualVolume);
			if (actualVolume > maxVolume)
			{
				actualVolume = maxVolume;
				setVolumeMusicIfNotMuted(playedMusic, actualVolume);
			}
			if (actualMusic != oldMusic)
			{
				switch (_music)
				{
				case Menu:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
					sfMusic_play(playedMusic);
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					actualMusic = Menu;
					break;
				case Overworld:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-CombatcontreNoctunoir.ogg");
					sfMusic_play(playedMusic);
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					actualMusic = Overworld;
					break;
				case Fire:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-Combat contre Noctunoir!.mp3");
					sfMusic_play(playedMusic);
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					break;
					//"area-feu -Combat contre Noctunoir !.mp3"
					//"area-feu -Maison de Monstres ! [TubeRipper.cc].mp3"
				case Water:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					//"area-eau -Grotte Cascade [TubeRipper.cc].mp3"
					//"area-eau -Grotte et Chemin Lisi�re [TubeRipper.cc].mp3"
					//"area-eau -Lake HD [TubeRipper.cc].mp3"
					sfMusic_play(playedMusic);
					break;
				case Grass:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					sfMusic_play(playedMusic);
					break;
					//"area-plante -Grotte Ab�me [TubeRipper.cc].mp3"
				case Elec:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					setVolumeMusicIfNotMuted(playedMusic, actualVolume);
					sfMusic_play(playedMusic);
					break;
					//"area-elek -Grotte Sables Mouvants [TubeRipper.cc].mp3"
					//"area-elek -Mt H�riss� [TubeRipper.cc].mp3"
					//"area-elek -Plaines Elek [TubeRipper.cc].mp3"
				}
			}
		}
		if (actualVolume == maxVolume)
		{
			hasChanged = 0;
			BackSound = 0;
		}
		
	}
	oldMusic = _music;

	
	
}

MusicChoice getOldMusic()
{
	return oldMusic;
}


void playSoundAttack()
{
	sfSound_play(attackMamo);
}

void playSoundBoulder()
{
	sfSound_play(boulderPush);
}

void playSoundTree()
{
	sfSound_play(treeCut);
}

void soundMute()
{
	isMuted = 1;
	setVolumeMusicIfNotMuted(getActualMusic(), 0);
	setVolumeSFXIfNotMuted(attackMamo, 0);
	setVolumeSFXIfNotMuted(boulderPush, 0);
	setVolumeSFXIfNotMuted(treeCut, 0);
}

void soundUnmute()
{
	
	isMuted = 0;
	setVolumeMusicIfNotMuted(getActualMusic(), maxVolume);
	setVolumeSFXIfNotMuted(attackMamo, maxVolume);
	setVolumeSFXIfNotMuted(boulderPush, maxVolume);
	setVolumeSFXIfNotMuted(treeCut, maxVolume);
}
