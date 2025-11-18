#include "SFML/Graphics.h"
#include "tools.h"
#include "map.h"
int main()
{

	initTools();
	initmap();
	initView();
	initplayer();
	initNPC();
	initTextBox();
	sfVideoMode mode = { 800,600,32 };
	sfRenderWindow* window = sfRenderWindow_create(mode, "Test", sfClose, NULL);
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

		if (state == MENU)
		{
			sfRenderWindow_setMouseCursorVisible(window, sfTrue);
		}
		updatemenu(window);
		updateViewEditor(window);
		updatePlayer(window);
		updateTextBox();
		updateMap(window);
		sfRenderWindow_clear(window, sfBlack);
		displayMap(window);

		
		displayTextBox(window);
		displayView(window);
		displayPlayer(window);
		displayNPC(window);
		displaymenu(window);

		sfRenderWindow_display(window);
	}

}