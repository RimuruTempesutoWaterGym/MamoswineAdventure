#include "menu.h"


// BASES MENU
sfVector2f tailleRectangle = { 300.0f, 80.0f };
sfTexture* rpgbutton;
sfIntRect irectbutton = { 0,0,45,12 };
sfFont* MC;
sfTexture* settingsbutton;
sfIntRect irectSettings = {0, 0, 12, 12};
sfTexture* FondSettings;

// MENU PRINCIPAL:
// GAME
sfRectangleShape* ToucheGame;
sfVector2f PositionGame = { 250.0f,100.0f };
sfText* Game;
sfVector2f PosText1 = { 335.0f, 110.0f };

// EDIT
sfRectangleShape* ToucheEditor;
sfVector2f PositionEdit = { 250.0f,250.0f };
sfText* Edit;
sfVector2f PosText2 = { 320.0f, 260.0f };

// QUITTER
sfRectangleShape* ToucheLeave;
sfVector2f PositionLeave = { 250.0f,400.0f };
sfText* Leave;
sfVector2f PosText3 = { 320.0f, 410.0f };


// SETTINGS
sfRectangleShape* ToucheSettings;
sfVector2f PositionSettings = { 700.0f,510.0f };
sfVector2f tailleSettings = { 70.0f, 70.0f };
//FIN MENU PRINCIPAL

// MENU SETTINGS:
sfRectangleShape* FondMenuSettings;
sfVector2f PositionFondSettings = { 100.0f, 50.0f };
sfVector2f tailleFondMenuSettings = { 600.0f , 500.0f };

// AudioSettings
sfRectangleShape* ToucheAudio;
sfVector2f PositionToucheAudio = { 250.0f,100.0f };
sfText* TextAudio;
sfVector2f PosTextAudio = { 340.0f, 110.0f };

// Affichage des touches
sfRectangleShape* ToucheTutoMapping;
sfVector2f PositionToucheMapping = { 250.0f,250.0f };
sfText* TextMapping;
sfVector2f PosTextMapping = { 300.0f, 260.0f };


// Retourner menu principal
sfRectangleShape* ToucheRetourMenu;
sfVector2f PositionToucheRetourMenu = { 250.0f,400.0f };
sfText* TextRetourMenu;
sfVector2f PosTextRetourMenu = { 340.0f, 410.0f };

// FOND ECRAN PRINCIPAL
sfSprite* fondmenu;
sfVector2f positionFond = { 0.0f,-275.0f };
sfVector2f ScaleFond = { 0.67f,0.67f };
sfTexture* wallpaper;

// AUTRES UTILITES POUR MENU
sfVector2i mousepos;
sfVector2f positionOnScreen = { 0.0f,0.0f };
//FIN MENU SETTINGS

//MENU TUTO MAPPING
sfSprite* ToucheZ;
sfTexture* Z;
sfVector2f positionZ = { 160.0f, 160.0f };

sfSprite* ToucheQ;
sfTexture* Q;
sfVector2f positionQ = { 110.0f, 220.0f };

sfSprite* ToucheS;
sfTexture* S;
sfVector2f positionS = { 160.0f, 220.0f };

sfSprite* ToucheD;
sfTexture* D;
sfVector2f positionD = { 210.0f, 220.0f };

sfSprite* ToucheF;
sfTexture* F;
sfVector2f positionF = { 110.0f, 310.0f };

sfSprite* ToucheE;
sfTexture* E;
sfVector2f positionE = { 110.0f, 390.0f };

float keytimer = 0.0f;

void initmenu()
{
	wallpaper = sfTexture_createFromFile("..\\Ressources\\Textures\\wallpaper.jpg", NULL);
	rpgbutton = sfTexture_createFromFile("..\\Ressources\\Textures\\Touche.png", NULL);
	settingsbutton = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheSettings.png", NULL);
	FondSettings = sfTexture_createFromFile("..\\Ressources\\Textures\\Fond.png", NULL);
	

	fondmenu = sfSprite_create();
	sfSprite_setTexture(fondmenu, wallpaper, sfTrue);
	sfSprite_setPosition(fondmenu, positionFond);
	sfSprite_setScale(fondmenu, ScaleFond);

	// MENU PRINCIPAL:
	// Touche lancement du jeu
	ToucheGame = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheGame, tailleRectangle);
	sfRectangleShape_setPosition(ToucheGame, PositionGame);
	sfRectangleShape_setTexture(ToucheGame, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheGame, irectbutton);
	// Texte touche lancement du jeu
	Game = sfText_create();
	sfText_setString(Game, "Jouer");
	sfText_setPosition(Game, PosText1);
	sfText_setColor(Game, sfWhite);
	sfText_setCharacterSize(Game, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Game, MC);


	// Touche mode editeur
	ToucheEditor = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheEditor, tailleRectangle);
	sfRectangleShape_setPosition(ToucheEditor, PositionEdit);
	sfRectangleShape_setTexture(ToucheEditor, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheEditor, irectbutton);
	// Texte touche mode editeur
	Edit = sfText_create();
	sfText_setString(Edit, "Editeur");
	sfText_setPosition(Edit, PosText2);
	sfText_setColor(Edit, sfWhite);
	sfText_setCharacterSize(Edit, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Edit, MC);


	// Touche pour quitter le jeu
	ToucheLeave = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheLeave, tailleRectangle);
	sfRectangleShape_setPosition(ToucheLeave, PositionLeave);
	sfRectangleShape_setTexture(ToucheLeave, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheLeave, irectbutton);
	// Texte touche quitter le jeu
	Leave = sfText_create();
	sfText_setString(Leave, "Quitter");
	sfText_setPosition(Leave, PosText3);
	sfText_setColor(Leave, sfWhite);
	sfText_setCharacterSize(Leave, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Leave, MC);

	// Touche settings

	ToucheSettings = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheSettings, tailleSettings);
	sfRectangleShape_setPosition(ToucheSettings, PositionSettings);
	sfRectangleShape_setTexture(ToucheSettings, settingsbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheSettings, irectSettings);
	//FIN MENU PRINCIPAL

	// MENU SETTINGS:
	FondMenuSettings = sfRectangleShape_create();
	sfRectangleShape_setPosition(FondMenuSettings, PositionFondSettings);
	sfRectangleShape_setSize(FondMenuSettings, tailleFondMenuSettings);
	sfRectangleShape_setTexture(FondMenuSettings, FondSettings, sfTrue);

	//Touche Audio
	ToucheAudio = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheAudio, tailleRectangle);
	sfRectangleShape_setPosition(ToucheAudio, PositionToucheAudio);
	sfRectangleShape_setTexture(ToucheAudio, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheAudio, irectbutton);

	TextAudio = sfText_create();
	sfText_setString(TextAudio, "Audio");
	sfText_setPosition(TextAudio, PosTextAudio);
	sfText_setColor(TextAudio, sfWhite);
	sfText_setCharacterSize(TextAudio, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextAudio, MC);

	//Touche Tuto Mapping
	ToucheTutoMapping = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheTutoMapping, tailleRectangle);
	sfRectangleShape_setPosition(ToucheTutoMapping, PositionToucheMapping);
	sfRectangleShape_setTexture(ToucheTutoMapping, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheTutoMapping, irectbutton);

	TextMapping = sfText_create();
	sfText_setString(TextMapping, "Touches");
	sfText_setPosition(TextMapping, PosTextMapping);
	sfText_setColor(TextMapping, sfWhite);
	sfText_setCharacterSize(TextMapping, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextMapping, MC);

	//Touche Retour Menu
	ToucheRetourMenu = sfRectangleShape_create();
	sfRectangleShape_setSize(ToucheRetourMenu, tailleRectangle);
	sfRectangleShape_setPosition(ToucheRetourMenu, PositionToucheRetourMenu);
	sfRectangleShape_setTexture(ToucheRetourMenu, rpgbutton, sfTrue);
	sfRectangleShape_setTextureRect(ToucheRetourMenu, irectbutton);

	TextRetourMenu = sfText_create();
	sfText_setString(TextRetourMenu, "Menu");
	sfText_setPosition(TextRetourMenu, PosTextRetourMenu);
	sfText_setColor(TextRetourMenu, sfWhite);
	sfText_setCharacterSize(TextRetourMenu, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextRetourMenu, MC);

	//MENU Tuto du mapping
	ToucheZ = sfSprite_create();
	Z = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheZ.png", NULL);
	sfSprite_setPosition(ToucheZ, positionZ);
	sfSprite_setTexture(ToucheZ, Z, sfTrue);

	ToucheQ = sfSprite_create();
	Q = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheQ.png", NULL);
	sfSprite_setPosition(ToucheQ, positionQ);
	sfSprite_setTexture(ToucheQ, Q, sfTrue);

	ToucheS = sfSprite_create();
	S = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheS.png", NULL);
	sfSprite_setPosition(ToucheS, positionS);
	sfSprite_setTexture(ToucheS, S, sfTrue);

	ToucheD = sfSprite_create();
	D = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheD.png", NULL);
	sfSprite_setPosition(ToucheD, positionD);
	sfSprite_setTexture(ToucheD, D, sfTrue);

	ToucheF = sfSprite_create();
	F = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheF.png", NULL);
	sfSprite_setPosition(ToucheF, positionF);
	sfSprite_setTexture(ToucheF, F, sfTrue);

	ToucheE = sfSprite_create();
	E = sfTexture_createFromFile("..\\Ressources\\Textures\\ToucheE.png", NULL);
	sfSprite_setPosition(ToucheE, positionE);
	sfSprite_setTexture(ToucheE, E, sfTrue);

}

void displaymenu(sfRenderWindow* _window)
{
	if (state == MENU)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheGame, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheEditor, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheLeave, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheSettings, NULL);
		sfRenderWindow_drawText(_window, Game, NULL);
		sfRenderWindow_drawText(_window, Edit, NULL);
		sfRenderWindow_drawText(_window, Leave, NULL);
		
	}
	if (state == SETTINGS)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheAudio, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheTutoMapping, NULL);
		sfRenderWindow_drawRectangleShape(_window, ToucheRetourMenu, NULL);
		sfRenderWindow_drawText(_window, TextAudio, NULL);
		sfRenderWindow_drawText(_window, TextMapping, NULL);
		sfRenderWindow_drawText(_window, TextRetourMenu, NULL);
	}
	if (state == AUDIO)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, FondMenuSettings, NULL);
	}
	if (state == TUTORIAL)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, FondMenuSettings, NULL);
		sfRenderWindow_drawSprite(_window, ToucheZ, NULL);
		sfRenderWindow_drawSprite(_window, ToucheS, NULL);
		sfRenderWindow_drawSprite(_window, ToucheD, NULL);
		sfRenderWindow_drawSprite(_window, ToucheQ, NULL);
		sfRenderWindow_drawSprite(_window, ToucheE, NULL);
		sfRenderWindow_drawSprite(_window, ToucheF, NULL);
	}
}

void updatemenu(sfRenderWindow* _window)
{
	keytimer += GetDeltaTime();
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
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ToucheGame);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = GAME;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(ToucheEditor);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = EDITOR;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(ToucheLeave);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = LEAVE;
			if (state == LEAVE)
			{
				sfRenderWindow_close(_window);
			}
			keytimer = 0.0f;
			
		}
		sfFloatRect Rectangle4 = sfRectangleShape_getGlobalBounds(ToucheSettings);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle4.left && mousepos.x < (Rectangle4.width + Rectangle4.left) && mousepos.y > Rectangle4.top && mousepos.y < (Rectangle4.top + Rectangle4.height))
		{
			state = SETTINGS;
			keytimer = 0.0f;
		}

	
	}
	if (state == SETTINGS)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ToucheAudio);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = AUDIO;
			keytimer = 0.0f;
			
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(ToucheTutoMapping);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = TUTORIAL;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(ToucheRetourMenu);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = MENU;
			keytimer = 0.0f;
		}
	}
	mousepos = sfMouse_getPosition(_window);
	positionOnScreen.x = (float)mousepos.x;
	positionOnScreen.y = (float)mousepos.y;

}


