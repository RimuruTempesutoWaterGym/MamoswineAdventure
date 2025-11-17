#include "SFML/Graphics.h"
#include "tools.h"
#include "map.h"
int main()
{

	initTools();
	initmap();
	sfVideoMode mode = { 800,600,32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "Test", sfResize | sfClose, NULL);
	sfEvent event;
	initmenu();
	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
			if (event.type == sfEvtMouseButtonPressed)
			{
				pressed = 1;
			}
			else if (event.type == sfEvtMouseButtonReleased)
			{
				pressed = 0;
			}
		}
		updatemenu(window);
		sfRenderWindow_clear(window, sfBlack);
		displayMap(window);
	
		updateMap(window);
		displaymenu(window);
		sfRenderWindow_display(window);
	}

}