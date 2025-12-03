#include"door.h"
#include"player.h"
#include"elemental_mammoswine.h"



sfSprite* door;
sfVector2f doorSize = { 2006, 126 };
sfIntRect doorTextureRect = { 0, 0,118,126 };
sfTexture* doorTexture;
sfVector2f doorPos = { 1201, 600 };



void initDoor()
{ 
	door = sfSprite_create();
	doorTexture = sfTexture_createFromFile(TEXTURE_PATH"door/doorSpritesheet.png",NULL);
	sfSprite_setTexture(door, doorTexture, sfTrue); 

	sfSprite_setPosition(door, doorPos);
}
sfFloatRect GetCollisionOfDoor()
{
	sfFloatRect doorHitbox = sfSprite_getGlobalBounds(door);
	doorHitbox.top += (doorHitbox.height / 1.5);
	doorHitbox.height /= 3;
	return  doorHitbox;

}
//update the elemental mamoswine count and the sprite to draw
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
//hit box when the door is open
int isInsideOpenDoor(sfVector2i item, sfFloatRect obstacle)
{
	
	if (item.x > obstacle.left &&
		item.x < (46 + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height)
		|| item.x < obstacle.left + obstacle.width &&
		item.x > (obstacle.width + obstacle.left - 46) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height)
		)

	{
		
		return 1;
	}

	return 0;
}

void displayDoor(sfVector2f* _window)
{
	if (state == GAME || state == EDITOR)
	{

			sfRenderWindow_drawRectangleShape(_window, door, NULL);
		
	}
}
void setDoorPosition(sfVector2f newPos) {
	doorPos = newPos;
	sfSprite_setPosition(door, doorPos);
}