#include"door.h"
#include"player.h"
#include"elemental_mammoswine.h"



//creation du sprite de la porte
sfSprite* door;
sfVector2f doorSize = { 2006, 126 };
sfIntRect doorTextureRect = { 0, 0,118,126 };
sfTexture* doorTexture;
sfVector2f doorPos = { 1201, 600 };


//initialisation des variables du fichier door
void initDoor()

{ 
	//initialisation du sprite de la porte
	door = sfSprite_create();
	doorTexture = sfTexture_createFromFile(TEXTURE_PATH"door/doorSpritesheet.png",NULL);
	sfSprite_setTexture(door, doorTexture, sfTrue); 
	sfSprite_setPosition(door, doorPos);
}
// récupère la boite de collision de la porte
sfFloatRect GetCollisionOfDoor()
{
	//calcule la boite de collision de la porte
	sfFloatRect doorHitbox = sfSprite_getGlobalBounds(door);
	doorHitbox.top += (doorHitbox.height / 1.5);
	doorHitbox.height /= 3;
	return  doorHitbox;

}
//met a jour constament l'interrieur de la fonction
void updateDoor()
{
	//vérifie si le joueur est a la portée de la porte et qu'il a toutes les ames de mammochons, pour ouvrir la porte quand il appuie sur E
	sfFloatRect doorHitbox = GetCollisionOfDoor();
		if (GetMamoswineElementalCount() == 15 && sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getCollisionOfPlayer(),doorHitbox))
		{
			SetMamoswineElementalCountToPlusOne();
		}
			doorTextureRect.left = 118 * GetMamoswineElementalCount();
		sfSprite_setTextureRect(door, doorTextureRect);
	
}
//calcule la boite de collision de la porte ouverte
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
//affiche le sprite de la porte
void displayDoor(sfVector2f* _window)
{
	if (state == GAME || state == EDITOR)
	{

			sfRenderWindow_drawRectangleShape(_window, door, NULL);
		
	}
}
//initialise la position de la porte
void setDoorPosition(sfVector2f newPos) {
	doorPos = newPos;
	sfSprite_setPosition(door, doorPos);
}