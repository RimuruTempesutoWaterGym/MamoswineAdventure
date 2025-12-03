#include "menu.h"
#include "music.h"
#include "map.h"

// BASES MENU
sfVector2f SizeRectangle = { 300.0f, 80.0f };
sfTexture* rpgbutton;
sfIntRect irectbutton = { 0,0,45,12 };
sfFont* MC;
sfTexture* settingsbutton;
sfIntRect irectSettings = {0, 0, 12, 12};
sfTexture* BackgroundSettings;
sfTexture* casevide;
sfTexture* casecoche;
sfTexture* backgroundsoundbarre;
float volumelerp = 0.1f;

// MENU PRINCIPAL:
// GAME
sfRectangleShape* ButtonGame;
sfVector2f PositionGame = { 250.0f,100.0f };
sfText* Game;
sfVector2f PosText1 = { 335.0f, 110.0f };

// EDIT
sfRectangleShape* ButtonEditor;
sfVector2f PositionEdit = { 250.0f,250.0f };
sfText* Edit;
sfVector2f PosText2 = { 320.0f, 260.0f };

// QUITTER
sfRectangleShape* ButtonLeave;
sfVector2f PositionLeave = { 250.0f,400.0f };
sfText* Leave;
sfVector2f PosText3 = { 320.0f, 410.0f };


// SETTINGS
sfRectangleShape* ButtonSettings;
sfVector2f PosSettings = { 700.0f,510.0f };
sfVector2f SizeSettings = { 70.0f, 70.0f };
//FIN MENU PRINCIPAL

// MENU SETTINGS:
sfRectangleShape* BackgroundSettingsMenu;
sfVector2f PosBackgroundSettings = { 100.0f, 50.0f };
sfVector2f SizeBackgroundSettingsMenu = { 600.0f , 500.0f };

// AudioSettings
sfRectangleShape* ButtonAudio;
sfVector2f PositionButtonAudio = { 250.0f,100.0f };
sfText* TextAudio;
sfVector2f PosTextAudio = { 340.0f, 110.0f };

// Affichage des touches
sfRectangleShape* ButtonTutoMapping;
sfVector2f PositionButtonMapping = { 250.0f,250.0f };
sfText* TextMapping;
sfVector2f PosTextMapping = { 300.0f, 260.0f };


// Retourner menu principal
sfRectangleShape* ButtonRetourMenu;
sfVector2f PositionButtonRetourMenu = { 250.0f,400.0f };
sfText* TextRetourMenu;
sfVector2f PosTextRetourMenu = { 340.0f, 410.0f };

// FOND ECRAN PRINCIPAL
sfSprite* Backgroundmenu;
sfVector2f positionBackground = { 0.0f,-275.0f };
sfVector2f ScaleBackground = { 0.67f,0.67f };
sfTexture* wallpaper;

// AUTRES UTILITES POUR MENU
sfVector2i mousepos;
sfVector2f positionOnScreen = { 0.0f,0.0f };
//FIN MENU SETTINGS

//MENU TUTO MAPPING

// Revenir au menu settings

sfRectangleShape* ButtonClose;
sfTexture* Close;
sfVector2f positionClose = { 670.0f,50.0f };
sfVector2f SizeButtonclose = { 12.0f,12.0f };
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
sfSprite* ButtonZ;
sfTexture* Z;
sfVector2f positionZ = { 160.0f, 160.0f };

sfSprite* ButtonQ;
sfTexture* Q;
sfVector2f positionQ = { 110.0f, 220.0f };

sfSprite* ButtonS;
sfTexture* S;
sfVector2f positionS = { 160.0f, 220.0f };

sfSprite* ButtonD;
sfTexture* D;
sfVector2f positionD = { 210.0f, 220.0f };

sfSprite* ButtonF;
sfTexture* F;
sfVector2f positionF = { 110.0f, 310.0f };

sfSprite* ButtonE;
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
sfSprite* ButtonUp;
sfTexture* up;
sfVector2f positionUp = { 450.0f, 160.0f };

sfSprite* ButtonDown;
sfTexture* down;
sfVector2f positionDown = { 450.0f, 220.0f };

sfSprite* ButtonLeft;
sfTexture* left;
sfVector2f positionLeft = { 400.0f, 220.0f };

sfSprite* ButtonRight;
sfTexture* right;
sfVector2f positionRight = { 500.0f, 220.0f };

sfSprite* ButtonLeftClic;
sfTexture* LeftClic;
sfVector2f positionLeftClic = { 400.0f, 310.0f };

sfSprite* ButtonRightClic;
sfTexture* RightClic;
sfVector2f positionRightClic = { 400.0f, 390.0f };
// FIN MENU TUTO

// MENU AUDIO

// Rendre le son muet
sfRectangleShape* CaseMute;
sfVector2f positioncasemute = { 490.0f,170.0f };
sfVector2f Sizecasemute = { 12.0f,12.0f };
sfIntRect irectcasemute = { 0,0,12,12 };
sfVector2f scalecasemute = { 4.0f,4.0f };
sfRectangleShape* CaseDemute;

sfText* SoundMuted;
sfVector2f postextsoundmuted = { 275.0f, 170.0f };

// Rendre SFX muet
sfRectangleShape* CaseMute2;
sfVector2f positioncasemute2 = { 490.0f,260.0f };
sfRectangleShape* CaseDemute2;

sfText* SFXMuted;
sfVector2f postextsfxmuted = { 255.0f, 260.0f };

// Barre son
sfRectangleShape* soundbarre;
sfVector2f positionsoundbarre = { 250.0f, 390.0f };
sfVector2f Sizesoundbarre = { 31.0f,6.0f };
sfIntRect irectsoundbarre = { 0,0,31,6 };
sfVector2f scalesoundbarre = { 10.0f,10.0f };
sfTexture* texsoundbarre;

sfRectangleShape* SoundLevel;
sfVector2f positionsound = { 550.0f, 440.0f };
sfVector2f Sizesound = { 0.0f, 4.0f };
sfIntRect irectSoundLevel = { 0,0,30,5 };
sfVector2f scaleSoundLevel = { 10.0f, 10.0f };
// Boutons de volume
sfRectangleShape* ButtonPlus;
sfVector2f positionButtonplus = { 565.0f, 390.0f };
sfVector2f SizeButtonplus = { 8.0f,8.0f };
sfIntRect irectButtonplus = { 0,0,8,8 };
sfVector2f scaleButtonplus = { 8.0f,8.0f };
sfTexture* TexButtonPlus;

sfRectangleShape* ButtonMoins;
sfVector2f positionButtonmoins = { 180.0f, 390.0f };
sfVector2f SizeButtonmoins = { 8.0f,8.0f };
sfIntRect irectButtonmoins = { 0,0,8,8 };
sfVector2f scaleButtonmoins = { 8.0f,8.0f };
sfTexture* TexButtonMoins;

sfText* ChangeSound;
sfVector2f postextchangesound = { 275.0f, 350.0f };
//FIN MENU AUDIO

// MENU PAUSE IN GAME
sfRectangleShape* OverlayMenuPause;
sfRectangleShape* RetourJeuPause;
sfVector2f posretourjeu = { 250.0f,100.0f };
sfText* RetourJeu;
sfVector2f postextretourjeu = { 330.0f, 120.0f };
sfRectangleShape* OptionsPause;
sfVector2f posoptions = { 250.0f , 200.0f };
sfText* Options;
sfVector2f postextoptions = { 340.0f, 220.0f };
sfRectangleShape* SauvegarderPause;
sfVector2f possauvegarder = { 250.0f, 300.0f };
sfText* Sauvegarder;
sfVector2f postextsauvegarder = { 290.0f, 320.0f };
sfRectangleShape* RetourMenuPrincipalPause;
sfVector2f posmenuprincipal = { 250.0f, 400.0f };
sfText* MenuPrincipal;
sfVector2f postextmenuprincipal = { 280.0f, 420.0f };
sfRectangleShape* RetourPause;
sfVector2f posretour = { 250.0f,400.0f };
sfText* Retour;
sfVector2f postextretour = { 320.0f, 410.0f };


float keytimer = 0.0f;

void initmenu()
{
	// liste des textures utilis�es
	wallpaper = sfTexture_createFromFile(TEXTURE_PATH"wallpaper.jpg", NULL);
	rpgbutton = sfTexture_createFromFile(TEXTURE_PATH"Touche.png", NULL);
	settingsbutton = sfTexture_createFromFile(TEXTURE_PATH"ToucheSettings.png", NULL);
	BackgroundSettings = sfTexture_createFromFile(TEXTURE_PATH"Fond.png", NULL);
	Close = sfTexture_createFromFile(TEXTURE_PATH"Close.png", NULL);
	casevide = sfTexture_createFromFile(TEXTURE_PATH"casevide.png", NULL);
	casecoche = sfTexture_createFromFile(TEXTURE_PATH"casecoche.png", NULL);
	texsoundbarre = sfTexture_createFromFile(TEXTURE_PATH"barreson.png", NULL);
	TexButtonPlus = sfTexture_createFromFile(TEXTURE_PATH"ToucheLoud.png", NULL);
	TexButtonMoins = sfTexture_createFromFile(TEXTURE_PATH"ToucheLow.png", NULL);
	backgroundsoundbarre = sfTexture_createFromFile(TEXTURE_PATH"fondbarreson.png", NULL);

	// Fond du menu principal
	Backgroundmenu = sfSprite_create();
	sfSprite_setTexture(Backgroundmenu, wallpaper, sfTrue);
	sfSprite_setPosition(Backgroundmenu, positionBackground);
	sfSprite_setScale(Backgroundmenu, ScaleBackground);

	// MENU PRINCIPAL:
	// Touche lancement du jeu
	ButtonGame = creationbutton(ButtonGame, SizeRectangle, PositionGame, irectbutton, rpgbutton);
	// Texte touche lancement du jeu
	Game = creationtexte(Game, "Jouer", PosText1, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Game, MC);


	// Touche mode editeur
	ButtonEditor = creationbutton(ButtonEditor, SizeRectangle, PositionEdit, irectbutton, rpgbutton);
	// Texte touche mode editeur
	Edit = creationtexte(Edit, "Editeur", PosText2, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Edit, MC);


	// Touche pour quitter le jeu
	ButtonLeave = creationbutton(ButtonLeave, SizeRectangle, PositionLeave, irectbutton, rpgbutton);
	// Texte touche quitter le jeu
	Leave = creationtexte(Leave, "Quitter", PosText3, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Leave, MC);

	// Touche settings

	ButtonSettings = creationbutton(ButtonSettings, SizeSettings, PosSettings, irectSettings, settingsbutton);
	//FIN MENU PRINCIPAL

	// MENU SETTINGS:
	BackgroundSettingsMenu = sfRectangleShape_create();
	sfRectangleShape_setPosition(BackgroundSettingsMenu, PosBackgroundSettings);
	sfRectangleShape_setSize(BackgroundSettingsMenu, SizeBackgroundSettingsMenu);
	sfRectangleShape_setTexture(BackgroundSettingsMenu, BackgroundSettings, sfTrue);

	//Touche Audio
	ButtonAudio = creationbutton(ButtonAudio, SizeRectangle, PositionButtonAudio, irectbutton, rpgbutton);

	TextAudio = creationtexte(TextAudio, "Audio", PosTextAudio, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextAudio, MC);

	//Touche Tuto Mapping
	ButtonTutoMapping = creationbutton(ButtonTutoMapping, SizeRectangle, PositionButtonMapping, irectbutton, rpgbutton);

	TextMapping = creationtexte(TextMapping, "Touches", PosTextMapping, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextMapping, MC);

	//Touche Retour Menu
	ButtonRetourMenu = creationbutton(ButtonRetourMenu, SizeRectangle, PositionButtonRetourMenu, irectbutton, rpgbutton);

	TextRetourMenu = creationtexte(TextRetourMenu, "Menu", PosTextRetourMenu, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(TextRetourMenu, MC);

	//MENU Tuto du mapping

	// Texte tuto Jeu
	Jeu = creationtexte(Jeu, "En jeu", postextjeu, sfWhite, 25);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Jeu, MC);

	deplacement = creationtexte(deplacement, "Deplacements", posdeplacement, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(deplacement, MC);

	Frapper = creationtexte(Frapper, "Frapper", postextfrapper, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Frapper, MC);

	Interagir = creationtexte(Interagir, "Interagir", postextinteract, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Interagir, MC);

	// Texte Tuto edit
	editor = creationtexte(editor, "Mode editeur", postexteditor, sfWhite, 25);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(editor, MC);

	deplacement2 = creationtexte(deplacement2, "Deplacements", posdeplacement2, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(deplacement2, MC);

	SelectTile = creationtexte(SelectTile, "Selectionner", postextselecttile, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(SelectTile, MC);

	DrawTile = creationtexte(DrawTile, "Poser Tile", postextdrawtile, sfWhite, 20);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(DrawTile, MC);

	// Affichage Sprites tuto

	ButtonClose = creationbutton(ButtonClose, SizeButtonclose, positionClose, irectclose, Close);
	sfRectangleShape_setScale(ButtonClose, scaleclose);
	

	// Affichage Sprites mode jeu
	ButtonZ = sfSprite_create();
	Z = sfTexture_createFromFile(TEXTURE_PATH"ToucheZ.png", NULL);
	sfSprite_setPosition(ButtonZ, positionZ);
	sfSprite_setTexture(ButtonZ, Z, sfTrue);
	sfSprite_setScale(ButtonZ, (sfVector2f) { 4.0f, 4.0f});

	ButtonQ = sfSprite_create();
	Q = sfTexture_createFromFile(TEXTURE_PATH"ToucheQ.png", NULL);
	sfSprite_setPosition(ButtonQ, positionQ);
	sfSprite_setTexture(ButtonQ, Q, sfTrue);
	sfSprite_setScale(ButtonQ, (sfVector2f) { 4.0f, 4.0f});

	ButtonS = sfSprite_create();
	S = sfTexture_createFromFile(TEXTURE_PATH"ToucheS.png", NULL);
	sfSprite_setPosition(ButtonS, positionS);
	sfSprite_setTexture(ButtonS, S, sfTrue);
	sfSprite_setScale(ButtonS, (sfVector2f) { 4.0f, 4.0f});

	ButtonD = sfSprite_create();
	D = sfTexture_createFromFile(TEXTURE_PATH"ToucheD.png", NULL);
	sfSprite_setPosition(ButtonD, positionD);
	sfSprite_setTexture(ButtonD, D, sfTrue);
	sfSprite_setScale(ButtonD, (sfVector2f) { 4.0f, 4.0f});

	ButtonF = sfSprite_create();
	F = sfTexture_createFromFile(TEXTURE_PATH"ToucheF.png", NULL);
	sfSprite_setPosition(ButtonF, positionF);
	sfSprite_setTexture(ButtonF, F, sfTrue);
	sfSprite_setScale(ButtonF, (sfVector2f) { 4.0f, 4.0f});

	ButtonE = sfSprite_create();
	E = sfTexture_createFromFile(TEXTURE_PATH"ToucheE.png", NULL);
	sfSprite_setPosition(ButtonE, positionE);
	sfSprite_setTexture(ButtonE, E, sfTrue);
	sfSprite_setScale(ButtonE, (sfVector2f) { 4.0f, 4.0f });

	
	// Affichage sprites mode editeur
	ButtonUp = sfSprite_create();
	up = sfTexture_createFromFile(TEXTURE_PATH"ToucheUp.png", NULL);
	sfSprite_setPosition(ButtonUp, positionUp);
	sfSprite_setTexture(ButtonUp, up, sfTrue);
	sfSprite_setScale(ButtonUp, (sfVector2f) { 4.0f, 4.0f });

	ButtonDown = sfSprite_create();
	down = sfTexture_createFromFile(TEXTURE_PATH"ToucheDown.png", NULL);
	sfSprite_setPosition(ButtonDown, positionDown);
	sfSprite_setTexture(ButtonDown, down, sfTrue);
	sfSprite_setScale(ButtonDown, (sfVector2f) { 4.0f, 4.0f });

	ButtonLeft = sfSprite_create();
	left = sfTexture_createFromFile(TEXTURE_PATH"ToucheLeft.png", NULL);
	sfSprite_setPosition(ButtonLeft, positionLeft);
	sfSprite_setTexture(ButtonLeft, left, sfTrue);
	sfSprite_setScale(ButtonLeft, (sfVector2f) { 4.0f, 4.0f });

	ButtonRight = sfSprite_create();
	right = sfTexture_createFromFile(TEXTURE_PATH"ToucheRight.png", NULL);
	sfSprite_setPosition(ButtonRight, positionRight);
	sfSprite_setTexture(ButtonRight, right, sfTrue);
	sfSprite_setScale(ButtonRight, (sfVector2f) { 4.0f, 4.0f });

	ButtonRightClic = sfSprite_create();
	RightClic = sfTexture_createFromFile(TEXTURE_PATH"ClicDroit.png", NULL);
	sfSprite_setPosition(ButtonRightClic, positionRightClic);
	sfSprite_setTexture(ButtonRightClic, RightClic, sfTrue);
	sfSprite_setScale(ButtonRightClic, (sfVector2f) { 4.0f, 4.0f });

	ButtonLeftClic = sfSprite_create();
	LeftClic = sfTexture_createFromFile(TEXTURE_PATH"ClicGauche.png", NULL);
	sfSprite_setPosition(ButtonLeftClic, positionLeftClic);
	sfSprite_setTexture(ButtonLeftClic, LeftClic, sfTrue);
	sfSprite_setScale(ButtonLeftClic, (sfVector2f) { 4.0f, 4.0f });
	//FIN MENU TUTO

	// MENU AUDIO
	//Application du bouton close utilis� dans tuto 
	
	// Touche pour mute le son g�n�ral
	coche = VALIDE;
	CaseMute = creationbutton(CaseMute, Sizecasemute, positioncasemute, irectcasemute, casevide);
	sfRectangleShape_setScale(CaseMute, scalecasemute);

	CaseDemute = creationbutton(CaseDemute, Sizecasemute, positioncasemute, irectcasemute, casecoche);
	sfRectangleShape_setScale(CaseDemute, scalecasemute);

	SoundMuted = creationtexte(SoundMuted, "Activer le son:", postextsoundmuted, sfWhite, 30);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(SoundMuted, MC);
	
	// Touche pour mute les SFX

	CaseMute2 = creationbutton(CaseMute2, Sizecasemute, positioncasemute2, irectcasemute, casevide);
	sfRectangleShape_setScale(CaseMute2, scalecasemute);

	CaseDemute2 = creationbutton(CaseDemute2, Sizecasemute, positioncasemute2, irectcasemute, casecoche);
	sfRectangleShape_setScale(CaseDemute2, scalecasemute);

	SFXMuted = creationtexte(SFXMuted, "Activer les SFX:", postextsfxmuted, sfWhite, 30);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(SFXMuted, MC);
	

	// Barre pour monter le son ou le descendre
	soundbarre = creationbutton(soundbarre, Sizesoundbarre, positionsoundbarre, irectsoundbarre, texsoundbarre);
	sfRectangleShape_setScale(soundbarre, scalesoundbarre);
	SoundLevel = creationbutton(SoundLevel, Sizesound, positionsound, irectSoundLevel, backgroundsoundbarre);
	sfRectangleShape_setScale(SoundLevel, scaleSoundLevel);
	sfRectangleShape_setRotation(SoundLevel, 180);

	ChangeSound = creationtexte(ChangeSound, "Modifier le volume:", postextchangesound, sfWhite, 30);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(ChangeSound, MC);

	// Boutons pour monter ou descendre le son
	ButtonPlus = creationbutton(ButtonPlus, SizeButtonplus, positionButtonplus, irectButtonplus, TexButtonPlus);
	sfRectangleShape_setScale(ButtonPlus, scaleButtonplus);

	ButtonMoins = creationbutton(ButtonMoins, SizeButtonmoins, positionButtonmoins, irectButtonmoins, TexButtonMoins);
	sfRectangleShape_setScale(ButtonMoins, scaleButtonmoins);
	//FIN MENU AUDIO

	// MENU PAUSE
	OverlayMenuPause = sfRectangleShape_create();
	sfRectangleShape_setSize(OverlayMenuPause, SizeBackgroundSettingsMenu);
	sfRectangleShape_setPosition(OverlayMenuPause, PosBackgroundSettings);
	sfRectangleShape_setTexture(OverlayMenuPause, BackgroundSettings, sfTrue);

	RetourJeuPause = creationbutton(RetourJeuPause, SizeRectangle, posretourjeu, irectbutton, rpgbutton);
	RetourJeu = creationtexte(RetourJeu, "Resume", postextretourjeu, sfWhite, 35);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(RetourJeu, MC);

	OptionsPause = creationbutton(OptionsPause, SizeRectangle, posoptions,irectbutton, rpgbutton);
	Options = creationtexte(Options, "Options", postextoptions, sfWhite, 35);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Options, MC);

	SauvegarderPause = creationbutton(SauvegarderPause, SizeRectangle, possauvegarder, irectbutton, rpgbutton);
	Sauvegarder = creationtexte(Sauvegarder, "Sauvegarder", postextsauvegarder, sfWhite, 35);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Sauvegarder, MC);

	RetourMenuPrincipalPause = creationbutton(RetourMenuPrincipalPause, SizeRectangle, posmenuprincipal, irectbutton, rpgbutton);
	MenuPrincipal = creationtexte(MenuPrincipal, "Menu principal", postextmenuprincipal, sfWhite, 35);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(MenuPrincipal, MC);

	// MENU SETTINGS PAUSE
	RetourPause = creationbutton(RetourPause, SizeRectangle, posretour, irectbutton, rpgbutton);
	Retour = creationtexte(Retour, "Retour", postextretour, sfWhite, 50);
	MC = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	sfText_setFont(Retour, MC);


}



void updatemenu(sfRenderWindow* _window)
{
	// Bind la touche �chape pour avoir le menu de Pause en mode �ditor ou en jeu
	keytimer += GetDeltaTime();
	if ((state == GAME || state == EDITOR) && sfKeyboard_isKeyPressed(sfKeyEscape) && keytimer > 0.5f)
	{
		if (state == GAME)
		{
			typemenu = INGAME;
		}
		else if (state == EDITOR)
		{
			typemenu = EDITING;
		}
		state = PAUSE;
		sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
		keytimer = 0.0f;
	}

	else if (state == PAUSE && sfKeyboard_isKeyPressed(sfKeyEscape) && keytimer > 0.5f)
	{
		if (typemenu == INGAME)
		{
			state = GAME;
		}
		if (typemenu == EDITING)
		{
			state = EDITOR;
		}
		keytimer = 0.0f;
	}
	
	// Hitbox des touches du mode Menu Principal
	if (state == MENU)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ButtonGame);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = GAME;
			setMusic(MUSIC_Overworld);
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(ButtonEditor);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = EDITOR;
			loadMap("maps/mymap.dat");
			loadSpritesData("maps/sprites.dat");
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(ButtonLeave);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = LEAVE;
			if (state == LEAVE)
			{
				sfRenderWindow_close(_window);
			}
			keytimer = 0.0f;

		}
		sfFloatRect Rectangle4 = sfRectangleShape_getGlobalBounds(ButtonSettings);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle4.left && mousepos.x < (Rectangle4.width + Rectangle4.left) && mousepos.y > Rectangle4.top && mousepos.y < (Rectangle4.top + Rectangle4.height))
		{
			state = SETTINGSMENU;
			keytimer = 0.0f;
		}

	}
	
	// Hitbox dans le menu Option dans le Menu Principal
	if (state == SETTINGSMENU)
	{
		typemenu = PRINCIPAL;
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ButtonAudio);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = AUDIO;
			keytimer = 0.0f;
			
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(ButtonTutoMapping);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = TUTORIAL;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(ButtonRetourMenu);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = MENU;
			keytimer = 0.0f;
		}
	}

	// Hit box dans le menu Tutoriel des touches
	if (state == TUTORIAL)
	{
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ButtonClose);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			switch (typemenu)
			{
			case PRINCIPAL:
				state = SETTINGSMENU;
				break;

			case INGAME:
				state = SETTINGS;
				break;

			default:
				state = SETTINGS;
				break;
			}
			keytimer = 0.0f;

		}
	}

	// Hitbox du menu Audio 
	if (state == AUDIO)
	{
		
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ButtonClose);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			switch(typemenu)
			{
			case PRINCIPAL:
				state = SETTINGSMENU;
				break;

			case INGAME:
				state = SETTINGS;
				break;

			default:
				state = SETTINGS;
				break;
			}
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(CaseMute);
		if (sfMouse_isButtonPressed(sfMouseLeft)&& (coche == VALIDE || coche == SFXNEUTRE ) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
		
			coche = NEUTRE;
			musicMute();
			soundMute();
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(CaseDemute);
		if (sfMouse_isButtonPressed(sfMouseLeft) && coche == NEUTRE && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{

			coche = VALIDE;
			soundUnmute();
			musicUnmute();
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle4 = sfRectangleShape_getGlobalBounds(ButtonPlus);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.3f && mousepos.x > Rectangle4.left && mousepos.x < (Rectangle4.width + Rectangle4.left) && mousepos.y > Rectangle4.top && mousepos.y < (Rectangle4.top + Rectangle4.height))
		{
			
			if (Sizesound.x > 1.0f)
			{
				Sizesound.x -= LERP_F(0, 29.0f, volumelerp);
				
				volumeMusic(volumelerp * 100);
				sfRectangleShape_setSize(SoundLevel, Sizesound);
			}
			
				keytimer = 0.0f;
			
			
		}
		sfFloatRect Rectangle5 = sfRectangleShape_getGlobalBounds(ButtonMoins);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.3f && mousepos.x > Rectangle5.left && mousepos.x < (Rectangle5.width + Rectangle5.left) && mousepos.y > Rectangle5.top && mousepos.y < (Rectangle5.top + Rectangle5.height))
		{
			if (Sizesound.x < 28.0f)
			{
				Sizesound.x += LERP_F(0, 29.0f, volumelerp);
				sfRectangleShape_setSize(SoundLevel, Sizesound);
				volumeMusic(-volumelerp * 100);
			}
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle6 = sfRectangleShape_getGlobalBounds(CaseMute2);
		if (sfMouse_isButtonPressed(sfMouseLeft) && coche == VALIDE && keytimer > 0.5f && mousepos.x > Rectangle6.left && mousepos.x < (Rectangle6.width + Rectangle6.left) && mousepos.y > Rectangle6.top && mousepos.y < (Rectangle6.top + Rectangle6.height))
		{
			coche = SFXNEUTRE;
			soundMute();
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle7 = sfRectangleShape_getGlobalBounds(CaseDemute2);
		if (sfMouse_isButtonPressed(sfMouseLeft) && coche == SFXNEUTRE && keytimer > 0.5f && mousepos.x > Rectangle7.left && mousepos.x < (Rectangle7.width + Rectangle7.left) && mousepos.y > Rectangle7.top && mousepos.y < (Rectangle7.top + Rectangle7.height))
		{
			coche = VALIDE;
			soundUnmute();
			keytimer = 0.0f;
		}
		
	}

	// hitbox du menu de Pause
	if (state == PAUSE)
	{
		
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(RetourJeuPause);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			switch (typemenu)
			{
			case EDITING:
				state = EDITOR;
				break;

			case INGAME:
				state = GAME;
				break;

			default:
				state = GAME;
				break;
			}
			keytimer = 0.0f;

		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(OptionsPause);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = SETTINGS;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(SauvegarderPause);
		if (sfMouse_isButtonPressed(sfMouseLeft)  && keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{

			if (typemenu == EDITING)
			{
				saveMap("maps/mymap.dat");
				saveSpritesData("maps/sprites.dat");
			}
			else if (typemenu == GAME)
			{
				updateElementalMamoswine();
			}
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle4 = sfRectangleShape_getGlobalBounds(RetourMenuPrincipalPause);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle4.left && mousepos.x < (Rectangle4.width + Rectangle4.left) && mousepos.y > Rectangle4.top && mousepos.y < (Rectangle4.top + Rectangle4.height))
		{
			state = MENU;
			setMusic(MUSIC_Menu);
			keytimer = 0.0f;
		}
	}

	// Hitbox du menu Option quand on est en jeu ou �diteur
	if (state == SETTINGS)
	{
		typemenu = INGAME;
		sfFloatRect Rectangle = sfRectangleShape_getGlobalBounds(ButtonAudio);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle.left && mousepos.x < (Rectangle.width + Rectangle.left) && mousepos.y > Rectangle.top && mousepos.y < (Rectangle.top + Rectangle.height))
		{
			state = AUDIO;
			keytimer = 0.0f;

		}
		sfFloatRect Rectangle2 = sfRectangleShape_getGlobalBounds(ButtonTutoMapping);
		if (sfMouse_isButtonPressed(sfMouseLeft) && keytimer > 0.5f && mousepos.x > Rectangle2.left && mousepos.x < (Rectangle2.width + Rectangle2.left) && mousepos.y > Rectangle2.top && mousepos.y < (Rectangle2.top + Rectangle2.height))
		{
			state = TUTORIAL;
			keytimer = 0.0f;
		}
		sfFloatRect Rectangle3 = sfRectangleShape_getGlobalBounds(RetourPause);
		if (sfMouse_isButtonPressed(sfMouseLeft) &&  keytimer > 0.5f && mousepos.x > Rectangle3.left && mousepos.x < (Rectangle3.width + Rectangle3.left) && mousepos.y > Rectangle3.top && mousepos.y < (Rectangle3.top + Rectangle3.height))
		{
			state = PAUSE;
			keytimer = 0.0f;
		}
	}

	mousepos = sfMouse_getPosition(_window);
	positionOnScreen.x = (float)mousepos.x;
	positionOnScreen.y = (float)mousepos.y;

}

void displaymenu(sfRenderWindow* _window)
{
	if (state == MENU)
	{
		sfRenderWindow_drawSprite(_window, Backgroundmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonGame, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonEditor, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonLeave, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonSettings, NULL);
		sfRenderWindow_drawText(_window, Game, NULL);
		sfRenderWindow_drawText(_window, Edit, NULL);
		sfRenderWindow_drawText(_window, Leave, NULL);
	}
	if (state == SETTINGSMENU)
	{
		sfRenderWindow_drawSprite(_window, Backgroundmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonAudio, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonTutoMapping, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonRetourMenu, NULL);
		sfRenderWindow_drawText(_window, TextAudio, NULL);
		sfRenderWindow_drawText(_window, TextMapping, NULL);
		sfRenderWindow_drawText(_window, TextRetourMenu, NULL);
	}
	if (state == AUDIO)
	{
		sfRenderWindow_drawSprite(_window, Backgroundmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, BackgroundSettingsMenu, NULL);
		sfRenderWindow_drawSprite(_window, ButtonClose, NULL);
		if (coche == NEUTRE)
		{
			sfRenderWindow_drawRectangleShape(_window, CaseMute, NULL);
			sfRenderWindow_drawRectangleShape(_window, CaseMute2, NULL);
		}
		else if (coche == VALIDE)
		{
			sfRenderWindow_drawRectangleShape(_window, CaseDemute, NULL);
			sfRenderWindow_drawRectangleShape(_window, CaseDemute2, NULL);
			
		}
		else if (coche == SFXNEUTRE)
		{
			sfRenderWindow_drawRectangleShape(_window, CaseDemute, NULL);
			sfRenderWindow_drawRectangleShape(_window, CaseMute2, NULL);
		}
		sfRenderWindow_drawRectangleShape(_window, soundbarre, NULL);
		sfRenderWindow_drawRectangleShape(_window, SoundLevel, NULL);
		sfRenderWindow_drawText(_window, SoundMuted, NULL);
		sfRenderWindow_drawText(_window, ChangeSound, NULL);
		sfRenderWindow_drawText(_window, SFXMuted, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonPlus, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonMoins, NULL);
		
	}
	if (state == TUTORIAL)
	{
		sfRenderWindow_drawSprite(_window, Backgroundmenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, BackgroundSettingsMenu, NULL);
		sfRenderWindow_drawSprite(_window, ButtonClose, NULL);
		sfRenderWindow_drawSprite(_window, ButtonZ, NULL);
		sfRenderWindow_drawSprite(_window, ButtonS, NULL);
		sfRenderWindow_drawSprite(_window, ButtonD, NULL);
		sfRenderWindow_drawSprite(_window, ButtonQ, NULL);
		sfRenderWindow_drawSprite(_window, ButtonE, NULL);
		sfRenderWindow_drawSprite(_window, ButtonF, NULL);
		sfRenderWindow_drawSprite(_window, ButtonUp, NULL);
		sfRenderWindow_drawSprite(_window, ButtonDown, NULL);
		sfRenderWindow_drawSprite(_window, ButtonLeft, NULL);
		sfRenderWindow_drawSprite(_window, ButtonRight, NULL);
		sfRenderWindow_drawSprite(_window, ButtonRightClic, NULL);
		sfRenderWindow_drawSprite(_window, ButtonLeftClic, NULL);
		sfRenderWindow_drawText(_window, Jeu, NULL);
		sfRenderWindow_drawText(_window, editor, NULL);
		sfRenderWindow_drawText(_window, deplacement, NULL);
		sfRenderWindow_drawText(_window, deplacement2, NULL);
		sfRenderWindow_drawText(_window, Frapper, NULL);
		sfRenderWindow_drawText(_window, Interagir, NULL);
		sfRenderWindow_drawText(_window, SelectTile, NULL);
		sfRenderWindow_drawText(_window, DrawTile, NULL);
	}
	if (state == PAUSE)
	{
		sfRenderWindow_drawRectangleShape(_window, OverlayMenuPause, NULL);
		sfRenderWindow_drawRectangleShape(_window, RetourJeuPause, NULL);
		sfRenderWindow_drawRectangleShape(_window, OptionsPause, NULL);
		sfRenderWindow_drawRectangleShape(_window, SauvegarderPause, NULL);
		sfRenderWindow_drawRectangleShape(_window, RetourMenuPrincipalPause, NULL);
		sfRenderWindow_drawText(_window, RetourJeu, NULL);
		sfRenderWindow_drawText(_window, Options, NULL);
		sfRenderWindow_drawText(_window, Sauvegarder, NULL);
		sfRenderWindow_drawText(_window, MenuPrincipal, NULL);
	}
	if (state == SETTINGS)
	{
		sfRenderWindow_drawRectangleShape(_window, BackgroundSettingsMenu, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonAudio, NULL);
		sfRenderWindow_drawRectangleShape(_window, ButtonTutoMapping, NULL);
		sfRenderWindow_drawRectangleShape(_window, RetourPause, NULL);
		sfRenderWindow_drawText(_window, TextAudio, NULL);
		sfRenderWindow_drawText(_window, TextMapping, NULL);
		sfRenderWindow_drawText(_window, Retour, NULL);
	}
}

// fonction de cr�ation pour les touches du menu
sfRectangleShape* creationbutton(sfRectangleShape* _nomButton, sfVector2f _Size, sfVector2f _position, sfIntRect _irect, sfTexture * _texture)
{
	_nomButton = sfRectangleShape_create();
	sfRectangleShape_setSize(_nomButton, _Size);
	sfRectangleShape_setPosition(_nomButton, _position);
	sfRectangleShape_setTexture(_nomButton, _texture, sfTrue);
	sfRectangleShape_setTextureRect(_nomButton, _irect);
	return _nomButton;
}

// fonction de cr�ation de texte
sfText* creationtexte(sfText* _text, const char* _string,sfVector2f _position, sfColor _couleur, unsigned int _size)
{
	_text = sfText_create();
	sfText_setString(_text, _string);
	sfText_setPosition(_text, _position);
	sfText_setColor(_text, _couleur);
	sfText_setCharacterSize(_text, _size);
	return _text;
}
