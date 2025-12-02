#include "music.h"


sfMusic* playedMusic;
sfSoundBuffer* attackMamoBuffer;
sfSoundBuffer* boulderPushBuffer;
sfSoundBuffer* treeCutBuffer;
sfSound* attackMamo;
sfSound* boulderPush;
sfSound* treeCut;
float actualVolume = 100;
float timerLerp = 0;
int getBackSound = 0;
int hasChanged= 0;
int musicUp = 0;



void initMusic()
{
	music = 0;
	if(state == MENU)
	{ 
	playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-CombatcontreNoctunoir.ogg");
		setMusic(Menu);
	}
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

void volumeMusic(float _volume)
{
	actualVolume += _volume;
	sfMusic_setVolume(playedMusic, actualVolume);
	sfSound_setVolume(attackMamo, actualVolume);
	sfSound_setVolume(boulderPush, actualVolume);
	sfSound_setVolume(treeCut, actualVolume);
}


void changeMusic()
{

}
sfMusic* getActualMusic()
{
	return playedMusic;
}
void updateMusic()
{
	setMusic(0);
}
void setMusic(Music _music)
{
	if (music != _music || hasChanged == 1)
	{
		if (getBackSound == 0  && actualVolume >= 10)
		{
			actualVolume -= LERP_F(0, actualVolume,GetDeltaTime()) ;
			sfMusic_setVolume(playedMusic, actualVolume);
			printf("%f|||", sfMusic_getVolume(playedMusic));
		}
		hasChanged = 1;
		if ((sfMusic_getVolume(playedMusic) <= 10 || getBackSound == 1) &&actualVolume < 100)
		{

			actualVolume += LERP_F(actualVolume, 1, GetDeltaTime()*50);
			sfMusic_setVolume(playedMusic, actualVolume);
			if (sfMusic_getVolume(playedMusic) > 100)
			{
				actualVolume = 100;
				sfMusic_setVolume(playedMusic, actualVolume);
			}
			sfMusic_play(playedMusic);
			printf("%flll", sfMusic_getVolume(playedMusic));
			getBackSound = 1;

				switch (_music)
				{
				case Menu:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
					sfMusic_play(playedMusic);

					break;
				case Overworld:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-CombatcontreNoctunoir.ogg");
					sfMusic_play(playedMusic);
					break;
				case Fire:
					sfMusic_destroy(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-Combat contre Noctunoir!.mp3");
					sfMusic_setVolume(playedMusic, LERP_F(0, actualVolume, 1));
					sfMusic_play(playedMusic);
					break;
					//"area-feu -Combat contre Noctunoir !.mp3"
					//"area-feu -Maison de Monstres ! [TubeRipper.cc].mp3"
				case Water:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					sfMusic_setVolume(playedMusic, LERP_F(0, actualVolume, 1));
					//"area-eau -Grotte Cascade [TubeRipper.cc].mp3"
					//"area-eau -Grotte et Chemin Lisi�re [TubeRipper.cc].mp3"
					//"area-eau -Lake HD [TubeRipper.cc].mp3"
					sfMusic_play(playedMusic);
					break;
				case Grass:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					sfMusic_setVolume(playedMusic, LERP_F(0, actualVolume, 1));
					sfMusic_play(playedMusic);
					break;
					//"area-plante -Grotte Ab�me [TubeRipper.cc].mp3"
				case Elec:
					sfMusic_play(playedMusic);
					playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
					sfMusic_setVolume(playedMusic, LERP_F(0, actualVolume, 1));
					sfMusic_play(playedMusic);
					break;
					//"area-elek -Grotte Sables Mouvants [TubeRipper.cc].mp3"
					//"area-elek -Mt H�riss� [TubeRipper.cc].mp3"
					//"area-elek -Plaines Elek [TubeRipper.cc].mp3"
				}
			
		}
		if (sfMusic_getVolume == 100)
		{
			hasChanged = 0;
			getBackSound = 0;
		}
	
	}
	
	music = _music;

	
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
	sfSound_setVolume(attackMamo, 0);
	sfSound_setVolume(boulderPush, 0);
	sfSound_setVolume(treeCut, 0);
}

void soundUnmute()
{
	sfSound_setVolume(attackMamo, actualVolume);
	sfSound_setVolume(boulderPush, actualVolume);
	sfSound_setVolume(treeCut, actualVolume);
}
