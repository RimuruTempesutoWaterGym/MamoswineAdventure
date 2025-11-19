#include "SFML/Graphics.h"
#include "tools.h"
#include "map.h"
int main()
{

	initAll();

	sfVideoMode mode = { 800,600,32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "Test", sfClose, NULL);
	sfEvent event;

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

		if (state == MENU)
		{
			sfRenderWindow_setMouseCursorVisible(window, sfTrue);
		}
		updateAll(window);
		sfRenderWindow_clear(window, sfBlack);
		displayAll(window);

		sfRenderWindow_display(window);
	}

}