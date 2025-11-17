#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "SFML/audio.h"

#define MAP_HEIGHT 14
#define MAP_WIDTH 16
#define TILE_WIDTH 24
#define TILE_HEIGHT 24
#define TEXTURE_PATH "../ressources/Textures/"
typedef enum {
	Down, DownRight, Left, RightTop, Top, TopLeft, Right, DownLeft
}Direction;
typedef enum {
	MENU, GAME, EDITOR
}State;
State state;
int pressed;
void initTools();
void restartClock();
float GetDeltaTime();

