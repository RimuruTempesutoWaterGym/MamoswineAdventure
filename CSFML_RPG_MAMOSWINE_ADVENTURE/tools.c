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
int isInside(sfVector2f item, sfFloatRect obstacle)
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


void initAll()
{
	initTools();
	initmap();
	initView();
	initplayer();
	initNPC();
	initTextBox();
	initmenu();
}

void updateAll(sfRenderWindow* _window)
{
	updatemenu(_window);
	updateViewEditor(_window);
	updatePlayer(_window);
	updateTextBox();
	updateMap(_window);
}
void displayAll(sfRenderWindow* _window)
{
	displayMap(_window);
	displayTextBox(_window);
	displayView(_window);
	displayPlayer(_window);
	//displayNPC(_window);
	displaymenu(_window);
}