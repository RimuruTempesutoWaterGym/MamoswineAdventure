#include "tools.h"
sfTime sftime;
sfClock* sfclock;



void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

void restartClock()
{
	sftime = sfClock_restart(sfclock);
}

float GetDeltaTime()
{
	return sfTime_asSeconds(sftime);
}
int isInsideMouse(sfVector2f item, sfFloatRect obstacle)
{
	if (item.x > obstacle.left &&
		item.x < (obstacle.width + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height))
	{
	
		return 1;

	}
	return 0;
}
	int isInsideMousei(sfVector2i item, sfFloatRect obstacle)
	{

		if (item.x > obstacle.left &&
			item.x < (obstacle.width + obstacle.left) &&
			item.y > obstacle.top &&
			item.y < (obstacle.top + obstacle.height))
		{
			
			return 1;

		}

return 0;
}
int isInsidePlayer(sfFloatRect player, sfFloatRect obstacle)
{

		if (player.left > obstacle.left &&
			player.left < (obstacle.width + obstacle.left) &&
			player.top > obstacle.top &&
			player.top < (obstacle.top + obstacle.height) ||
			player.left + player.width > obstacle.left &&
			player.left + player.width < (obstacle.width + obstacle.left) &&
			player.top + player.height > obstacle.top &&
			player.top + player.height < (obstacle.top + obstacle.height) ||
			player.left  > obstacle.left &&
			player.left < (obstacle.width + obstacle.left) &&
			player.top + player.height > obstacle.top &&
			player.top + player.height < (obstacle.top + obstacle.height) ||
			player.left + player.width > obstacle.left &&
			player.left + player.width< (obstacle.width + obstacle.left) &&
			player.top  > obstacle.top &&
			player.top < (obstacle.top + obstacle.height)
			)
		{
			return 1;

		}


	return 0;
}


void initAll()
{
	initTools();

	

	initMusic();

	initSound();

	initView();

	initplayer();

	initNPC();
	initDoor();
	initTextBox();
	
	initmenu();
	
	initElementalMamoswine();
	initmap();
	updateSpritePositionsFromData();
}

void updateAll(sfRenderWindow* _window)
{

	updatemenu(_window);
	updateViewEditor(_window);
	updatePlayer(_window);
	updateTextBox();
	updateMap(_window);
	updateTextBox();
	updateDoor();
	updateMusic();
}
void displayAll(sfRenderWindow* _window)
{
	switch (state)
	{
	case EDITOR:
		displayViewEdit(_window);
		displayMap(_window);
		updateMap(_window);
		displayPlayer(_window);
		displayDoor(_window);
		displayElementalMamoswine(_window);
		displayNPC(_window);
		displayViewEditUi(_window);
		displayViewTileSelection(_window);	
		break;
	case GAME:
		displayViewPlayer(_window);
		displayMap(_window);
		displayNPC(_window);
		displayElementalMamoswine(_window);		displayMamoDialga(_window);

		if (isPlayerOverDoor())
		{
			displayPlayer(_window);
			displayDoor(_window);
		}
		else
		{
			displayDoor(_window);
			displayPlayer(_window);
		}

		displayMinimap(_window);
		displayHUD(_window);
		displayTextBox(_window);

		break;
	default:
		displayViewDefault(_window);
		displaymenu(_window);
		break;
	}

	//displayTextBox(_window);
}