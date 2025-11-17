#include "menu.h"


sfRectangleShape* RectangleGame;
sfRectangleShape* RectangleEditor;
sfRectangleShape* RectangleLeave;
sfVector2f tailleRectangle = { 300.0f, 80.0f };
sfVector2f PositionRectangle = { 250.0f,100.0f };
sfVector2f PositionRectangleEdit = { 250.0f,250.0f };
sfVector2f PositionRectangleLeave = { 250.0f,400.0f };
sfVector2f positionOnScreen = { 0.0f,0.0f };
sfVector2i mousepos;
sfVector2f PosText1 = { 330.0f, 110.0f };
sfText* Game;
sfFont* MC;

void initmenu()
{
	// game
	RectangleGame = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleGame, tailleRectangle);
	sfRectangleShape_setFillColor(RectangleGame, sfRed);
	sfRectangleShape_setPosition(RectangleGame, PositionRectangle);
	// edit
	RectangleEditor = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleEditor, tailleRectangle);
	sfRectangleShape_setFillColor(RectangleEditor, sfRed);
	sfRectangleShape_setPosition(RectangleEditor, PositionRectangleEdit);
	// Quitter
	RectangleLeave = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleLeave, tailleRectangle);
	sfRectangleShape_setFillColor(RectangleLeave, sfRed);
	sfRectangleShape_setPosition(RectangleLeave, PositionRectangleLeave);


	Game = sfText_create();
	sfText_setString(Game, "GAME");
	sfText_setPosition(Game, PosText1);
	sfText_setColor(Game, sfWhite);
	sfText_setCharacterSize(Game, 50);
	MC = sfFont_createFromFile("..\\Ressource\\Font\\Minecraft.ttf");
	sfText_setFont(Game, MC);


}



void displaymenu(sfRenderWindow* _window)
{
	if (state == MENU)
	{
		sfRenderWindow_drawRectangleShape(_window, RectangleGame, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleEditor, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleLeave, NULL);
		sfRenderWindow_drawText(_window, Game, NULL);
	}
}

void updatemenu(sfRenderWindow* _window)
{
	if (sfKeyboard_isKeyPressed(sfKeyM))
	{
		state = MENU;
	}
	if (sfKeyboard_isKeyPressed(sfKeyL))
	{
		state = GAME;
	}
	if (sfKeyboard_isKeyPressed(sfKeyK))
	{
		state = EDITOR;
	}
	if (state == MENU)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(RectangleGame);
		if (sfMouse_isButtonPressed(sfMouseLeft) && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = GAME;
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(RectangleEditor);
		if (sfMouse_isButtonPressed(sfMouseLeft) && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = EDITOR;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(RectangleLeave);
		if (sfMouse_isButtonPressed(sfMouseLeft) && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = LEAVE;
			if (state == LEAVE)
			{
				sfRenderWindow_close(_window);
			}
		}
	}
	mousepos = sfMouse_getPosition(_window);
	positionOnScreen.x = (float)mousepos.x;
	positionOnScreen.y = (float)mousepos.y;
}


