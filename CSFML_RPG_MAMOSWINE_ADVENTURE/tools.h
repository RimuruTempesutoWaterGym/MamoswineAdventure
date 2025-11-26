#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "SFML/audio.h"
#include "view.h"
#define MAP_HEIGHT 100
#define MAP_WIDTH 100
#define TILE_WIDTH 24
#define TILE_HEIGHT 24
#define TEXTURE_PATH "../ressources/Textures/"
#define MUSIC_PATH "../ressources/Musics/"
#define MAX(a,b) (a >= b ? a : b)
#define MIN(a,b) (a <= b ? a : b)
#define CLAMP(a,b,value) (MAX(MIN(b,value), a))
#define SATURATE(value) (CLAMP(0,1,value))
#define LERP_F(a,b,t) ((b-a) * SATURATE(t) + a)

typedef enum {
	Down, DownRight, Left, RightTop, Top, TopLeft, Right, DownLeft
}Direction;
typedef enum {
	MENU, GAME, EDITOR, LEAVE, PAUSE, SETTINGS, SETTINGSMENU, TUTORIAL, AUDIO
}State;
State state;
int pressed;
void initTools();
void initAll();
void updateAll(sfRenderWindow* _window);
void displayAll(sfRenderWindow* _window);
void restartClock();
float GetDeltaTime();
int isInsideMouse(sfVector2f item, sfFloatRect obstacle);
int isInsideMousei(sfVector2i item, sfFloatRect obstacle);

