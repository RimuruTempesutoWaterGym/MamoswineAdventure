#include"door.h"
#include"elemental_mammoswine.h"



//temporary variables
sfSprite* door;
sfVector2f doorSize = { 2006, 126 };
sfIntRect doorTextureRect = { 0, 0,118,126 };
//temporary variables
sfTexture* doorTexture;
sfVector2f doorPos = { 1201, 320 };



void initDoor()

{ 
	door = sfSprite_create();
	doorTexture = sfTexture_createFromFile(TEXTURE_PATH"door/doorSpritesheet.png",NULL);
	sfSprite_setTexture(door, doorTexture, sfTrue); 
	//temporary

	sfSprite_setPosition(door, doorPos);
	//temporary
}

void updateDoor()
{
	 
}

void displayDoor(sfVector2f* _window)
{
	if (state == GAME)
	{
		doorTextureRect.left = 118 * GetMamoswineElementalCount();
		sfSprite_setTextureRect(door, doorTextureRect);
			sfRenderWindow_drawRectangleShape(_window, door, NULL);
		
	}
}