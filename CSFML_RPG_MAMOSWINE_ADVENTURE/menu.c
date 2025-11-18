#include "menu.h"


sfRectangleShape* RectangleGame;
sfRectangleShape* RectangleEditor;
sfRectangleShape* RectangleLeave;
sfVector2f tailleRectangle = { 300.0f, 80.0f };
sfVector2f PositionRectangle = { 250.0f,100.0f };
sfVector2f PositionRectangleEdit = { 250.0f,250.0f };
sfVector2f PositionRectangleLeave = { 250.0f,400.0f };
sfVector2f positionOnScreen = { 0.0f,0.0f };
sfVector2f positionFond = { 00.0f,-2750.0f };
sfVector2i mousepos;
sfVector2f PosText1 = { 335.0f, 110.0f };
sfVector2f PosText2 = { 320.0f, 260.0f };
sfVector2f PosText3 = { 320.0f, 410.0f };
sfText* Game;
sfText* Edit;
sfText* Leave;
sfFont* MC;
sfSprite* fondmenu;
sfTexture* wallpaper;
sfTexture* rpgbutton;
sfIntRect irectbutton = { 0,0,178,60 };
sfVector2f ScaleFond = { 0.67f,0.67f };

void initmenu()
{
	fondmenu = sfSprite_create();
	wallpaper = sfTexture_createFromFile("..\\Ressources\\Textures\\wallpaper.jpg", NULL);
	sfSprite_setTexture(fondmenu, wallpaper, sfTrue);
	sfSprite_setPosition(fondmenu, positionFond);
	sfSprite_setScale(fondmenu, ScaleFond);

	// Touche lancement du jeu
	RectangleGame = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleGame, tailleRectangle);
	sfRectangleShape_setPosition(RectangleGame, PositionRectangle);
	rpgbutton = sfTexture_createFromFile("..\\Ressources\\Textures\\bouton.png", NULL);
	sfRectangleShape_setTexture(RectangleGame, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(RectangleGame, irectbutton);


	// Touche mode editeur
	RectangleEditor = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleEditor, tailleRectangle);
	sfRectangleShape_setPosition(RectangleEditor, PositionRectangleEdit);
	sfRectangleShape_setTexture(RectangleEditor, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(RectangleEditor, irectbutton);

	// Touche pour quitter le jeu
	RectangleLeave = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleLeave, tailleRectangle);
	sfRectangleShape_setPosition(RectangleLeave, PositionRectangleLeave);
	sfRectangleShape_setTexture(RectangleLeave, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(RectangleLeave, irectbutton);


	// Texte touche lancement du jeu
	Game = sfText_create();
	sfText_setString(Game, "Jouer");
	sfText_setPosition(Game, PosText1);
	sfText_setColor(Game, sfWhite);
	sfText_setCharacterSize(Game, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Game, MC);

	// Texte touche mode editeur
	Edit = sfText_create();
	sfText_setString(Edit, "Editeur");
	sfText_setPosition(Edit, PosText2);
	sfText_setColor(Edit, sfWhite);
	sfText_setCharacterSize(Edit, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Edit, MC);

	// Texte touche quitter le jeu
	Leave = sfText_create();
	sfText_setString(Leave, "Quitter");
	sfText_setPosition(Leave, PosText3);
	sfText_setColor(Leave, sfWhite);
	sfText_setCharacterSize(Leave, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Leave, MC);




}



void displaymenu(sfRenderWindow* _window)
{
	if (state == MENU)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleGame, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleEditor, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleLeave, NULL);
		sfRenderWindow_drawText(_window, Game, NULL);
		sfRenderWindow_drawText(_window, Edit, NULL);
		sfRenderWindow_drawText(_window, Leave, NULL);
	}
}

void updatemenu(sfRenderWindow* _window)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
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


