#include"door.h"
#include"player.h"
#include"elemental_mammoswine.h"



//temporary variables
sfSprite* door;
sfVector2f doorSize = { 2006, 126 };
sfIntRect doorTextureRect = { 0, 0,118,126 };
//temporary variables
sfTexture* doorTexture;
sfVector2f doorPos = { 1201, 600 };



void initDoor()

{ 
	door = sfSprite_create();
	doorTexture = sfTexture_createFromFile(TEXTURE_PATH"door/doorSpritesheet.png",NULL);
	sfSprite_setTexture(door, doorTexture, sfTrue); 
	//temporary

	sfSprite_setPosition(door, doorPos);
	//temporary
}
sfFloatRect GetCollisionOfDoor()
{
	sfFloatRect doorHitbox = sfSprite_getGlobalBounds(door);
	doorHitbox.top += (doorHitbox.height / 1.5);
	doorHitbox.height /= 3;
	return  doorHitbox;

}
void updateDoor()
{
	sfFloatRect doorHitbox = GetCollisionOfDoor();
		if (GetMamoswineElementalCount() == 15 && sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getCollisionOfPlayer(),doorHitbox))
		{
			SetMamoswineElementalCountToPlusOne();
		}
			doorTextureRect.left = 118 * GetMamoswineElementalCount();
		sfSprite_setTextureRect(door, doorTextureRect);
	
	}

void displayDoor(sfVector2f* _window)
{
	if (state == GAME)
	{

			sfRenderWindow_drawRectangleShape(_window, door, NULL);
		
	}
}
void setDoorPosition(sfVector2f newPos) {
	doorPos = newPos;
	sfSprite_setPosition(door, doorPos);
}