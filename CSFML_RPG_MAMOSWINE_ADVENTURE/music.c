#include"tools.h"
#include "music.h"

// Gestion de la musique
sfMusic* playedMusic;
MusicChoice oldMusic = 0;
MusicChoice actualMusic = 0;

// Gestion des SFX
sfSoundBuffer* attackMamoBuffer;
sfSoundBuffer* boulderPushBuffer;
sfSoundBuffer* treeCutBuffer;
sfSound* attackMamo;
sfSound* boulderPush;
sfSound* treeCut;

// gestion niveau de volume
float actualVolume;
float maxVolume;


float timerLerp = 0;
int BackSound = 0;

// Preparation pour les fonctions pour couper le son
int isMutedSfx;
int isMutedMusic;


int hasChanged = 0;
int musicUp = 0;

// initialisation de la musique par celle du MENU
void initMusic()
{
    actualVolume = 10.f;
    maxVolume = 100.0f;
    playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve.mp3");
    setMusic(MUSIC_Menu);

    sfMusic_setLoop(playedMusic, sfTrue);
    sfMusic_play(playedMusic);

}
// initialisation des SFX
void initSound()
{
    attackMamo = sfSound_create();
    attackMamoBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\attack.mp3");
    sfSound_setBuffer(attackMamo, attackMamoBuffer);

    boulderPush = sfSound_create();
    boulderPushBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\boulderPush.mp3");
    sfSound_setBuffer(boulderPush, boulderPushBuffer);

    treeCut = sfSound_create();
    treeCutBuffer = sfSoundBuffer_createFromFile("..\\Ressources\\SoundsFX\\treeCut.mp3");
    sfSound_setBuffer(treeCut, treeCutBuffer);
}

// fonction de gestion de la musique si mute ou non dans les options
void setVolumeMusicIfNotMuted(sfMusic* _music, float _volume)
{

    if (isMutedMusic == 0)
    {
        sfMusic_setVolume(_music, _volume);
    }
    if (isMutedMusic == 1)
    {
        sfMusic_setVolume(_music, 0);
    }
}

// fonction de gestion de SFX si mute ou non dans les options
void setVolumeSFXIfNotMuted(sfSound* _sfx, float _volume)
{
    if (isMutedMusic == 0)
    {
        sfSound_setVolume(_sfx, _volume);
    }
    if (isMutedMusic == 1)
    {
        _volume = 0.0f;
    }
}

// fonction de gestion du volume de son dans les options
void volumeMusic(float _volume)
{
    maxVolume += _volume;
    actualVolume = maxVolume;
    setVolumeMusicIfNotMuted(playedMusic, maxVolume);
    setVolumeSFXIfNotMuted(attackMamo, maxVolume);
    setVolumeSFXIfNotMuted(boulderPush, maxVolume);
    setVolumeSFXIfNotMuted(treeCut, maxVolume);

}

// fonction permettant de récupérer la musique actuelle en tant que valeur
sfMusic* getActualMusic()
{
    return playedMusic;
}

// fonctions permettant de faciliter le changement de musique
void updateMusic()
{
    setMusic(getOldMusic());
}

void setHasChangedTo1()
{
    hasChanged = 1;

    BackSound = 0;
}
// ------------------------------------------------------

// fonction permettant de changer la musique
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
                ChangeMusic(oldMusic);
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

// fonction de gestion du choix de musique en fonction de l'état de la tile et / ou state
MusicChoice getOldMusic()
{
    return oldMusic;
}

// fonction de changement de musique en fonction de leur état (MusicChoice), exemple (musique de menu, marchant sur les tiles ou en combat)
void ChangeMusic(MusicChoice _music)
{
    switch (_music)
    {
    case MUSIC_Menu:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"ecran-titre-Port Yoneuve.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Menu;
        break;

    case MUSIC_Overworld:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-eau -Grotte et Chemin Lisiere.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Overworld;
        break;

    case MUSIC_Fire:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Platinum OST Hard Mountain HD.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Fire;
        break;

    case MUSIC_Water:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"LAC SINNOH Musique Pokemon Diamant, Perle & Platine.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Water;
        break;

    case MUSIC_Grass:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-elek -Plaines Elek.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Grass;
        break;

    case MUSIC_Elec:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"area-elek -Mt Herisse.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Elec;
        break;
    case MUSIC_Void:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Distortion World Pokemon Platinum Music Extended HD.mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_Void;
        break;
    case MUSIC_BattleFire:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Omega Ruby & Alpha Sapphire - Ho-oh Battle Music (HQ).mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_BattleFire;
        break;

    case MUSIC_BattleWater:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Omega Ruby Alpha Sapphire - Uxie Mesprit Azelf Battle Music (HQ).mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_BattleWater;
        break;

    case MUSIC_BattleGrass:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Sun & Moon - Guardian Deities Battle Music (HQ).mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_BattleGrass;
        break;

    case MUSIC_BattleElec:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Sun & Moon - Solgaleo & Lunala Battle Music (HQ).mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_BattleElec;
        break;
    case MUSIC_BattleVoid:
        sfMusic_destroy(playedMusic);
        playedMusic = sfMusic_createFromFile(MUSIC_PATH"Pokemon Legends_ Arceus - Palkia Dialga Battle Music (HQ).mp3");
        sfMusic_setLoop(playedMusic, sfTrue);
        sfMusic_play(playedMusic);
        setVolumeMusicIfNotMuted(playedMusic, actualVolume);
        actualMusic = MUSIC_BattleVoid;
        break;
    }
}

// SFX d'attaque du player
void playSoundAttack()
{
    if (!sfSound_getStatus(attackMamo))
    {
        sfSound_play(attackMamo);
    }
}

// SFX de la boule poussée 
void playSoundBoulder()
{
    if (!sfSound_getStatus(boulderPush))
    {
        sfSound_play(boulderPush);
    }
}

// SFX de l'arbre coupé
void playSoundTree()
{
    if (!sfSound_getStatus(treeCut))
    {
        sfSound_play(treeCut);
    }
}

// fonction pour mute la musique
void musicMute()
{
    isMutedMusic = 1;
    setVolumeMusicIfNotMuted(getActualMusic(), 0);

}

// fonction pour demute la musique
void musicUnmute()
{

    isMutedMusic = 0;
    setVolumeMusicIfNotMuted(getActualMusic(), maxVolume);

}

// fonction pour demute les SFX
void soundUnmute()
{
    isMutedSfx = 0;
    setVolumeSFXIfNotMuted(attackMamo, maxVolume);
    setVolumeSFXIfNotMuted(boulderPush, maxVolume);
    setVolumeSFXIfNotMuted(treeCut, maxVolume);
}

// fonction pour demute les SFX
void soundMute()
{
    isMutedSfx = 1;
    setVolumeSFXIfNotMuted(attackMamo, 0);
    setVolumeSFXIfNotMuted(boulderPush, 0);
    setVolumeSFXIfNotMuted(treeCut, 0);
}