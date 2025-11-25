#include"door.h"



//temporary variables
sfRectangleShape* door;
sfVector2f doorSize = { 50, 50 };
//temporary variables

sfVector2f doorPos = { 1201, 320 };



void initDoor()
{
	//temporary
	door = sfRectangleShape_create();
	sfRectangleShape_setSize(door, doorSize);
	sfRectangleShape_setPosition(door, doorPos);
	sfRectangleShape_setFillColor(door, sfWhite);
	//temporary
}

void updateDoor()
{
	 
}

void displayDoor(sfVector2f* _window, sfVector2f playerPos)
{
	if (displayElementalMammoswine(_window, playerPos))
	{
		sfRenderWindow_drawRectangleShape(_window, door, NULL);
	}
}