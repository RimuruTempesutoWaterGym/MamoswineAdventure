#include "menu.h"


// BASES MENU
sfVector2f tailleRectangle = { 300.0f, 80.0f };
sfTexture* rpgbutton;
sfIntRect irectbutton = { 0,0,45,12 };
sfFont* MC;
sfTexture* settingsbutton;
sfIntRect irectSettings = {0, 0, 12, 12};
sfTexture* FondSettings;
sfTexture* casevide;
sfTexture* casecoche;

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

// Revenir au menu settings

sfRectangleShape* BoutonClose;
sfTexture* Close;
sfVector2f positionClose = { 670.0f,50.0f };
sfVector2f tailleboutonclose = { 12.0f,12.0f };
sfIntRect irectclose = { 0,0,12,12 };
sfVector2f scaleclose = { 2.5f,2.5f };

//Touches mode Jeu

// Texte Mode jeu
sfText* Jeu;
sfVector2f postextjeu = { 140.0f,100.0f };
sfText* deplacement;
sfVector2f posdeplacement = { 260.0f , 220.0f };

sfText* Frapper;
sfVector2f postextfrapper = { 200.0f,320.0f };

sfText* Interagir;
sfVector2f postextinteract = { 200.0f,400.0f };


// Sprites touches mode jeu
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

//Touches mode Editeur

//Texte mode Editeur
sfText* editor;
sfVector2f postexteditor = { 430.0f,100.0f };

sfText* deplacement2;
sfVector2f posdeplacement2 = { 550.0f , 220.0f };

sfText* SelectTile;
sfVector2f postextselecttile = { 530.0f,330.0f };

sfText* DrawTile;
sfVector2f postextdrawtile = { 530.0f, 410.0f };

// Sprites mode Editeur
sfSprite* ToucheUp;
sfTexture* up;
sfVector2f positionUp = { 450.0f, 160.0f };

sfSprite* ToucheDown;
sfTexture* down;
sfVector2f positionDown = { 450.0f, 220.0f };

sfSprite* ToucheLeft;
sfTexture* left;
sfVector2f positionLeft = { 400.0f, 220.0f };

sfSprite* ToucheRight;
sfTexture* right;
sfVector2f positionRight = { 500.0f, 220.0f };

sfSprite* ToucheLeftClic;
sfTexture* LeftClic;
sfVector2f positionLeftClic = { 400.0f, 310.0f };

sfSprite* ToucheRightClic;
sfTexture* RightClic;
sfVector2f positionRightClic = { 400.0f, 390.0f };
// FIN MENU TUTO

// MENU AUDIO

// Rendre le son muet
sfRectangleShape* CaseMute;
sfVector2f positioncasemute = { 490.0f,200.0f };
sfVector2f taillecasemute = { 12.0f,12.0f };
sfIntRect irectcasemute = { 0,0,12,12 };
sfVector2f scalecasemute = { 4.0f,4.0f };
sfRectangleShape* CaseDemute;

sfText* SoundMuted;
sfVector2f postextsoundmuted = { 275.0f, 200.0f };

// Barre son
sfRectangleShape* Barreson;
sfVector2f positionbarreson = { 250.0f, 370.0f };
sfVector2f taillebarreson = { 31.0f,6.0f };
sfIntRect irectbarreson = { 0,0,31,6 };
sfVector2f scalebarreson = { 10.0f,10.0f };
sfTexture* barre2son;
// Boutons de volume
sfRectangleShape* BoutonPlus;
sfVector2f positionboutonplus = { 565.0f, 370.0f };
sfVector2f tailleboutonplus = { 8.0f,8.0f };
sfIntRect irectboutonplus = { 0,0,8,8 };
sfVector2f scaleboutonplus = { 8.0f,8.0f };
sfTexture* TouchePlus;

sfRectangleShape* BoutonMoins;
sfVector2f positionboutonmoins = { 180.0f, 370.0f };
sfVector2f tailleboutonmoins = { 8.0f,8.0f };
sfIntRect irectboutonmoins = { 0,0,8,8 };
sfVector2f scaleboutonmoins = { 8.0f,8.0f };
sfTexture* ToucheMoins;

sfText* ChangeSound;
sfVector2f postextchangesound = { 275.0f, 330.0f };

float keytimer = 0.0f;

void initmenu()
{
	wallpaper = sfTexture_createFromFile(TEXTURE_PATH"wallpaper.jpg", NULL);
	rpgbutton = sfTexture_createFromFile(TEXTURE_PATH"Touche.png", NULL);
	settingsbutton = sfTexture_createFromFile(TEXTURE_PATH"ToucheSettings.png", NULL);
	FondSettings = sfTexture_createFromFile(TEXTURE_PATH"Fond.png", NULL);
	Close = sfTexture_createFromFile(TEXTURE_PATH"Close.png", NULL);
	casevide = sfTexture_createFromFile(TEXTURE_PATH"casevide.png", NULL);
	casecoche = sfTexture_createFromFile(TEXTURE_PATH"casecoche.png", NULL);
	barre2son = sfTexture_createFromFile(TEXTURE_PATH"barreson.png", NULL);
	TouchePlus = sfTexture_createFromFile(TEXTURE_PATH"ToucheLoud.png", NULL);
	ToucheMoins = sfTexture_createFromFile(TEXTURE_PATH"ToucheLow.png", NULL);

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

	// Texte tuto Jeu
	Jeu = sfText_create();
	sfText_setString(Jeu, "En jeu");
	sfText_setPosition(Jeu, postextjeu);
	sfText_setColor(Jeu, sfWhite);
	sfText_setCharacterSize(Jeu, 25);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Jeu, MC);

	deplacement = sfText_create();
	sfText_setString(deplacement, "Deplacements");
	sfText_setPosition(deplacement, posdeplacement);
	sfText_setColor(deplacement, sfWhite);
	sfText_setCharacterSize(deplacement, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(deplacement, MC);

	Frapper = sfText_create();
	sfText_setString(Frapper, "Frapper");
	sfText_setPosition(Frapper, postextfrapper);
	sfText_setColor(Frapper, sfWhite);
	sfText_setCharacterSize(Frapper, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Frapper, MC);

	Interagir = sfText_create();
	sfText_setString(Interagir, "Interagir");
	sfText_setPosition(Interagir, postextinteract);
	sfText_setColor(Interagir, sfWhite);
	sfText_setCharacterSize(Interagir, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Interagir, MC);

	// Texte Tuto edit
	editor = sfText_create();
	sfText_setString(editor, "Mode editeur");
	sfText_setPosition(editor, postexteditor);
	sfText_setColor(editor, sfWhite);
	sfText_setCharacterSize(editor, 25);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(editor, MC);

	deplacement2 = sfText_create();
	sfText_setString(deplacement2, "Deplacements");
	sfText_setPosition(deplacement2, posdeplacement2);
	sfText_setColor(deplacement2, sfWhite);
	sfText_setCharacterSize(deplacement2, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(deplacement2, MC);

	SelectTile = sfText_create();
	sfText_setString(SelectTile, "Selectionner");
	sfText_setPosition(SelectTile, postextselecttile);
	sfText_setColor(SelectTile, sfWhite);
	sfText_setCharacterSize(SelectTile, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(SelectTile, MC);

	DrawTile = sfText_create();
	sfText_setString(DrawTile, "Poser Tile");
	sfText_setPosition(DrawTile, postextdrawtile);
	sfText_setCharacterSize(DrawTile, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(DrawTile, MC);

	// Affichage Sprites tuto

	BoutonClose = sfRectangleShape_create();
	sfRectangleShape_setPosition(BoutonClose, positionClose);
	sfRectangleShape_setSize(BoutonClose, tailleboutonclose);
	sfRectangleShape_setTexture(BoutonClose, Close, sfTrue);
	sfRectangleShape_setTextureRect(BoutonClose, irectclose);
	sfRectangleShape_setScale(BoutonClose, scaleclose);
	

	// Affichage Sprites mode jeu
	ToucheZ = sfSprite_create();
	Z = sfTexture_createFromFile(TEXTURE_PATH"ToucheZ.png", NULL);
	sfSprite_setPosition(ToucheZ, positionZ);
	sfSprite_setTexture(ToucheZ, Z, sfTrue);
	sfSprite_setScale(ToucheZ, (sfVector2f) { 4.0f, 4.0f});

	ToucheQ = sfSprite_create();
	Q = sfTexture_createFromFile(TEXTURE_PATH"ToucheQ.png", NULL);
	sfSprite_setPosition(ToucheQ, positionQ);
	sfSprite_setTexture(ToucheQ, Q, sfTrue);
	sfSprite_setScale(ToucheQ, (sfVector2f) { 4.0f, 4.0f});

	ToucheS = sfSprite_create();
	S = sfTexture_createFromFile(TEXTURE_PATH"ToucheS.png", NULL);
	sfSprite_setPosition(ToucheS, positionS);
	sfSprite_setTexture(ToucheS, S, sfTrue);
	sfSprite_setScale(ToucheS, (sfVector2f) { 4.0f, 4.0f});

	ToucheD = sfSprite_create();
	D = sfTexture_createFromFile(TEXTURE_PATH"ToucheD.png", NULL);
	sfSprite_setPosition(ToucheD, positionD);
	sfSprite_setTexture(ToucheD, D, sfTrue);
	sfSprite_setScale(ToucheD, (sfVector2f) { 4.0f, 4.0f});

	ToucheF = sfSprite_create();
	F = sfTexture_createFromFile(TEXTURE_PATH"ToucheF.png", NULL);
	sfSprite_setPosition(ToucheF, positionF);
	sfSprite_setTexture(ToucheF, F, sfTrue);
	sfSprite_setScale(ToucheF, (sfVector2f) { 4.0f, 4.0f});

	ToucheE = sfSprite_create();
	E = sfTexture_createFromFile(TEXTURE_PATH"ToucheE.png", NULL);
	sfSprite_setPosition(ToucheE, positionE);
	sfSprite_setTexture(ToucheE, E, sfTrue);
	sfSprite_setScale(ToucheE, (sfVector2f) { 4.0f, 4.0f });

	
	// Affichage sprites mode editeur
	ToucheUp = sfSprite_create();
	up = sfTexture_createFromFile(TEXTURE_PATH"ToucheUp.png", NULL);
	sfSprite_setPosition(ToucheUp, positionUp);
	sfSprite_setTexture(ToucheUp, up, sfTrue);
	sfSprite_setScale(ToucheUp, (sfVector2f) { 4.0f, 4.0f });

	ToucheDown = sfSprite_create();
	down = sfTexture_createFromFile(TEXTURE_PATH"ToucheDown.png", NULL);
	sfSprite_setPosition(ToucheDown, positionDown);
	sfSprite_setTexture(ToucheDown, down, sfTrue);
	sfSprite_setScale(ToucheDown, (sfVector2f) { 4.0f, 4.0f });

	ToucheLeft = sfSprite_create();
	left = sfTexture_createFromFile(TEXTURE_PATH"ToucheLeft.png", NULL);
	sfSprite_setPosition(ToucheLeft, positionLeft);
	sfSprite_setTexture(ToucheLeft, left, sfTrue);
	sfSprite_setScale(ToucheLeft, (sfVector2f) { 4.0f, 4.0f });

	ToucheRight = sfSprite_create();
	right = sfTexture_createFromFile(TEXTURE_PATH"ToucheRight.png", NULL);
	sfSprite_setPosition(ToucheRight, positionRight);
	sfSprite_setTexture(ToucheRight, right, sfTrue);
	sfSprite_setScale(ToucheRight, (sfVector2f) { 4.0f, 4.0f });

	ToucheRightClic = sfSprite_create();
	RightClic = sfTexture_createFromFile(TEXTURE_PATH"ClicDroit.png", NULL);
	sfSprite_setPosition(ToucheRightClic, positionRightClic);
	sfSprite_setTexture(ToucheRightClic, RightClic, sfTrue);
	sfSprite_setScale(ToucheRightClic, (sfVector2f) { 4.0f, 4.0f });

	ToucheLeftClic = sfSprite_create();
	LeftClic = sfTexture_createFromFile(TEXTURE_PATH"ClicGauche.png", NULL);
	sfSprite_setPosition(ToucheLeftClic, positionLeftClic);
	sfSprite_setTexture(ToucheLeftClic, LeftClic, sfTrue);
	sfSprite_setScale(ToucheLeftClic, (sfVector2f) { 4.0f, 4.0f });
	//FIN MENU TUTO

	// MENU AUDIO
	//Application du bouton close utilisé dans tuto 
	
	// Touche pour mute le son général
	coche = VALIDE;
	CaseMute = sfRectangleShape_create();
	sfRectangleShape_setSize(CaseMute, taillecasemute);
	sfRectangleShape_setPosition(CaseMute, positioncasemute);
	sfRectangleShape_setTextureRect(CaseMute, irectcasemute);
	sfRectangleShape_setScale(CaseMute, scalecasemute);
	sfRectangleShape_setTexture(CaseMute, casevide, sfTrue);

	CaseDemute = sfRectangleShape_create();
	sfRectangleShape_setSize(CaseDemute, taillecasemute);
	sfRectangleShape_setPosition(CaseDemute, positioncasemute);
	sfRectangleShape_setTextureRect(CaseDemute, irectcasemute);
	sfRectangleShape_setScale(CaseDemute, scalecasemute);
	sfRectangleShape_setTexture(CaseDemute, casecoche, sfTrue);

	SoundMuted = sfText_create();
	sfText_setString(SoundMuted, "Activer le son:");
	sfText_setPosition(SoundMuted, postextsoundmuted);
	sfText_setColor(SoundMuted, sfWhite);
	sfText_setCharacterSize(SoundMuted, 30);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(SoundMuted, MC);
	
	// Barre pour monter le son ou le descendre
	Barreson = sfRectangleShape_create();
	sfRectangleShape_setPosition(Barreson, positionbarreson);
	sfRectangleShape_setSize(Barreson, taillebarreson);
	sfRectangleShape_setTexture(Barreson, barre2son, sfTrue);
	sfRectangleShape_setTextureRect(Barreson, irectbarreson);
	sfRectangleShape_setScale(Barreson, scalebarreson);

	ChangeSound = sfText_create();
	sfText_setString(ChangeSound, "Modifier le volume:");
	sfText_setPosition(ChangeSound, postextchangesound);
	sfText_setColor(ChangeSound, sfWhite);
	sfText_setCharacterSize(ChangeSound, 30);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(ChangeSound, MC);

	// Boutons pour monter ou descendre le son
	BoutonPlus = sfRectangleShape_create();
	sfRectangleShape_setPosition(BoutonPlus, positionboutonplus);
	sfRectangleShape_setSize(BoutonPlus, tailleboutonplus);
	sfRectangleShape_setTexture(BoutonPlus, TouchePlus, sfTrue);
	sfRectangleShape_setTextureRect(BoutonPlus, irectboutonplus);
	sfRectangleShape_setScale(BoutonPlus, scaleboutonplus);

	BoutonMoins = sfRectangleShape_create();
	sfRectangleShape_setPosition(BoutonMoins, positionboutonmoins);
	sfRectangleShape_setSize(BoutonMoins, tailleboutonmoins);
	sfRectangleShape_setTexture(BoutonMoins, ToucheMoins, sfTrue);
	sfRectangleShape_setTextureRect(BoutonMoins, irectboutonmoins);
	sfRectangleShape_setScale(BoutonMoins, scaleboutonmoins);
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
		sfRenderWindow_drawSprite(_window, BoutonClose, NULL);
		if (coche == NEUTRE)
		{
			sfRenderWindow_drawRectangleShape(_window, CaseMute, NULL);
		}
		if (coche == VALIDE)
		{
			sfRenderWindow_drawRectangleShape(_window, CaseDemute, NULL);
		}
		sfRenderWindow_drawRectangleShape(_window, Barreson, NULL);
		sfRenderWindow_drawText(_window, SoundMuted, NULL);
		sfRenderWindow_drawText(_window, ChangeSound, NULL);
		sfRenderWindow_drawRectangleShape(_window, BoutonPlus, NULL);
		sfRenderWindow_drawRectangleShape(_window, BoutonMoins, NULL);
	}
	if (state == TUTORIAL)
	{
		sfRenderWindow_drawSprite(_window, fondmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, FondMenuSettings, NULL);
		sfRenderWindow_drawSprite(_window, BoutonClose, NULL);
		sfRenderWindow_drawSprite(_window, ToucheZ, NULL);
		sfRenderWindow_drawSprite(_window, ToucheS, NULL);
		sfRenderWindow_drawSprite(_window, ToucheD, NULL);
		sfRenderWindow_drawSprite(_window, ToucheQ, NULL);
		sfRenderWindow_drawSprite(_window, ToucheE, NULL);
		sfRenderWindow_drawSprite(_window, ToucheF, NULL);
		sfRenderWindow_drawSprite(_window, ToucheUp, NULL);
		sfRenderWindow_drawSprite(_window, ToucheDown, NULL);
		sfRenderWindow_drawSprite(_window, ToucheLeft, NULL);
		sfRenderWindow_drawSprite(_window, ToucheRight, NULL);
		sfRenderWindow_drawSprite(_window, ToucheRightClic, NULL);
		sfRenderWindow_drawSprite(_window, ToucheLeftClic, NULL);
		sfRenderWindow_drawText(_window, Jeu, NULL);
		sfRenderWindow_drawText(_window, editor, NULL);
		sfRenderWindow_drawText(_window, deplacement, NULL);
		sfRenderWindow_drawText(_window, deplacement2, NULL);
		sfRenderWindow_drawText(_window, Frapper, NULL);
		sfRenderWindow_drawText(_window, Interagir, NULL);
		sfRenderWindow_drawText(_window, SelectTile, NULL);
		sfRenderWindow_drawText(_window, DrawTile, NULL);
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
	if (state == TUTORIAL)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(BoutonClose);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = SETTINGS;
			keytimer = 0.0f;

		}
	}
	if (state == AUDIO)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(BoutonClose);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = SETTINGS;
			keytimer = 0.0f;

		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(CaseMute);
		if (sfMouse_isButtonPressed(sfMouseLeft)&& coche == VALIDE && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			coche = NEUTRE;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(CaseDemute);
		if (sfMouse_isButtonPressed(sfMouseLeft) && coche == NEUTRE && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			coche = VALIDE;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle4 = sfRectangleShape_getGlobalBounds(BoutonPlus);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle4.left && mousepos.x < (Rectangle4.width + Rectangle4.left) && mousepos.y > Rectangle4.top && mousepos.y < (Rectangle4.top + Rectangle4.height))
		{
			
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle5 = sfRectangleShape_getGlobalBounds(BoutonMoins);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle5.left && mousepos.x < (Rectangle5.width + Rectangle5.left) && mousepos.y > Rectangle5.top && mousepos.y < (Rectangle5.top + Rectangle5.height))
		{
			
			keytimer = 0.0f;
		}
	}
	mousepos = sfMouse_getPosition(_window);
	positionOnScreen.x = (float)mousepos.x;
	positionOnScreen.y = (float)mousepos.y;

}


