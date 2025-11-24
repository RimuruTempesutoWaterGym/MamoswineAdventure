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
typedef enum {
	Down, DownRight, Left, RightTop, Top, TopLeft, Right, DownLeft
}Direction;
typedef enum {
	MENU, GAME, EDITOR, LEAVE, PAUSE, SETTINGS, TUTORIAL, AUDIO
}State;
State state;
int pressed;
void initTools();
void initAll();
void updateAll(sfRenderWindow* _window);
void displayAll(sfRenderWindow* _window);
void restartClock();
float GetDeltaTime();
int isInside(sfVector2f item, sfFloatRect obstacle);

