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
		printf("2");
return 0;
}
int isInsidePlayer(sfFloatRect player, sfFloatRect obstacle)
{
	if (player.left > obstacle.left &&
		player.left < (obstacle.width + obstacle.left) &&
		player.top > obstacle.top &&
		player.top < (obstacle.top + obstacle.height) ||
		player.left + player.width > obstacle.left &&
		player.left+player.width < (obstacle.width + obstacle.left) &&
		player.top + player.height > obstacle.top &&
		player.top + player.height < (obstacle.top + obstacle.height) ||
		player.left  > obstacle.left &&
		player.left < (obstacle.width + obstacle.left) &&
		player.top + player.height > obstacle.top &&
		player.top + player.height < (obstacle.top + obstacle.height)
		||
		player.left + player.width > obstacle.left &&
		player.left + player.width< (obstacle.width + obstacle.left) &&
		player.top  > obstacle.top &&
		player.top  < (obstacle.top + obstacle.height)
		)
	{
		return 1;

	}
	return 0;
}


void initAll()
{
	initTools();

	initDoor();

	initMusic();

	initmap();

	initView();

	initplayer();

	initNPC();

	initTextBox();
	
	initmenu();
	
	initElementalMammoswine();
}

void updateAll(sfRenderWindow* _window)
{

	updatemenu(_window);
	updateViewEditor(_window);
	updatePlayer(_window);
	updateTextBox();
	updateMap(_window);
	updateElementalMammoswine();
	updateDoor();
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
		displayElementalMammoswine(_window);
		displayNPC(_window);
		displayViewEditUi(_window);
		displayViewTileSelection(_window);	
		break;
	case GAME:
		displayViewPlayer(_window);
		displayMap(_window);
		displayPlayer(_window);
		displayDoor(_window);
		displayElementalMammoswine(_window);
		displayNPC(_window);
		break;
	default:
		displayViewDefault(_window);
		displaymenu(_window);
		break;
	}

	//displayTextBox(_window);
}