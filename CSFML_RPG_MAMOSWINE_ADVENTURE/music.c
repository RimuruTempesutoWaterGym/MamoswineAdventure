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
	attackMamoBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\attack.mp3");
	boulderPushBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\boulderPush.mp3");
	treeCutBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\treeCut.mp3");
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
	actualVolume = maxVolume;
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

    if (oldMusic != _music && hasChanged == 0)
    {
        oldMusic = _music;
        hasChanged = 1;     
        BackSound = 0;
    }


    if (hasChanged == 1 && BackSound == 0)
    {
        if (actualVolume >= 1)
        {
            actualVolume -= LERP_F(0, maxVolume, GetDeltaTime() * 0.3);
            setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        }

     
        if (actualVolume < 1)
        {
            if (actualMusic != oldMusic)
            {
                switch (oldMusic)  
                {
                case Menu:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve [TubeRipper.cc].mp3");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Menu;
                    break;

                case Overworld:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-plante -Grotte Abime [TubeRipper.cc].mp3");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Overworld;
                    break;

                case Fire:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-feu-CombatcontreNoctunoir.ogg");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Fire;
                    break;

                case Water:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Water;
                    break;

                case Grass:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Grass;
                    break;

                case Elec:
                    sfMusic_destroy(playedMusic);
                    playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Blanche Noire Musique - Port Yoneuve [TubeRipper.cc].mp3");
                    sfMusic_setLoop(playedMusic, sfTrue);
                    sfMusic_play(playedMusic);
                    setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                    actualMusic = Elec;
                    break;
                }
            }
            BackSound = 1;  
        }
    }


    if (hasChanged == 1 && BackSound == 1)
    {
        if (actualVolume < maxVolume)
        {
            actualVolume += LERP_F(0, maxVolume, GetDeltaTime() * 0.3);
            setVolumeMusicIfNotMuted(playedMusic, actualVolume);

            if (actualVolume >= maxVolume)
            {
                actualVolume = maxVolume;
                setVolumeMusicIfNotMuted(playedMusic, actualVolume);
                hasChanged = 0; 
                BackSound = 0;
            }
        }
    }
}

MusicChoice getOldMusic()
{
	return oldMusic;
}


void playSoundAttack()
{
	if (!sfSound_getStatus(attackMamo))
	{
		sfSound_play(attackMamo);
	}
}

void playSoundBoulder()
{
	if (!sfSound_getStatus(boulderPush))
	{
		sfSound_play(boulderPush);
	}
}

void playSoundTree()
{
	if (!sfSound_getStatus(treeCut))
	{
		sfSound_play(treeCut);
	}
}

void musicMute()
{
	isMuted = 1;
	setVolumeMusicIfNotMuted(getActualMusic(), 0);
	setVolumeSFXIfNotMuted(attackMamo, 0);
	setVolumeSFXIfNotMuted(boulderPush, 0);
	setVolumeSFXIfNotMuted(treeCut, 0);
}

void musicUnmute()
{
	
	isMuted = 0;
	setVolumeMusicIfNotMuted(getActualMusic(), maxVolume);
	setVolumeSFXIfNotMuted(attackMamo, maxVolume);
	setVolumeSFXIfNotMuted(boulderPush, maxVolume);
	setVolumeSFXIfNotMuted(treeCut, maxVolume);
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