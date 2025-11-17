#include "SFML/Graphics.h"
#include "tools.h"
#include "map.h"
int main()
{

	initTools();
	initmap();
	sfVideoMode mode = { MAP_WIDTH * TILE_WIDTH ,MAP_HEIGHT * TILE_HEIGHT,32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "Test", sfResize | sfClose, NULL);
	sfEvent event;
	state = EDITOR;
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
		
		sfRenderWindow_clear(window, sfBlack);
		displayMap(window);
		updateMap(window);
		sfRenderWindow_display(window);
	}

}