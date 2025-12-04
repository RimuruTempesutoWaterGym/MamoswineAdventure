
#include "map.h"
#include "door.h"
#include "elemental_mammoswine.h"
#include "player.h"
#include "music.h"
#include "NPC.h"

sfRectangleShape* selectTileSetSquare;
sfVector2f mousepos;
sfVector2f mouseposViewUi;
sfRectangleShape* RectangleTilesetPanel;
sfRectangleShape* RectangleTileSelectionPanel;
sfRectangleShape* RectangleButtonSwitchTileWall;
sfRectangleShape* RectangleButtonSwitchTileMode;
sfRectangleShape* mouseCornerIndicator;
sfVector2f tailleTilesetPanel = { TILE_WIDTH + 10.f, TILE_HEIGHT*MAP_HEIGHT };
sfVector2f tailleTileSelectionPanel = { 110.f, TILE_HEIGHT * MAP_HEIGHT }; 
sfVector2f tailleButtonSwitchTileWall = { 70.f, 25.f };
sfVector2f tailleButtonSwitchTileMode = { 25.f, 20.f };
sfVector2f PositionTilesetPanel = { 0.f,-100.f };
sfVector2f PositionButtonSwitchTileWall = { 20.f,525.f };
sfVector2f PositionButtonSwitchTileMode = { 5.f,525.f };
sfSprite* mapSprite;
//initialise les textures des tilesets
 sfTexture* peacefulTexture;
sfTexture* naturalTexture;
sfTexture* swampTexture;
sfTexture* waterTexture;
sfTexture* deepWaterTexture;
sfTexture* fireTexture;
sfTexture* plantTexture;
sfTexture* boulderTexture;
sfTexture* voidTilesetTexture;
sfTexture* voidTexture;
sfTexture* electricCircuitTexture;
sfTexture* electricMushroomTexture;
sfTexture* switchRectangleTexture;
sfTexture* thunderedTexture;
sfTexture* tilesetBarTexture;
sfTexture*	directionTexture;
selectionTileType filterTile = 0;
float switchTileTypeTimer = 0.0f;

int currentPage = 0;
int tilesPerPage = 45;  // 15 colonnes × 3 lignes = 45 tiles par page
float pageButtonTimer = 0.0f;
float bushCutTimer = 0.0f;
float bushCutTimer2 = 0.0f;
float rockStrengthTimer = 0.0f;
float rockStrengthTimer2 = 0.0f;
sfRectangleShape* buttonPrevPage;
sfRectangleShape* buttonNextPage;

tileSet peacefulTileset;
tileSet naturalTileset;
sfColor musicColors[6] = {
				{100, 100, 255, 255},
				{255, 100, 255, 255},
				{255, 0, 0, 255},
				{0, 100, 255, 255},
				{0, 255, 0, 255},
				{255, 255, 0, 255}
};
sfColor spriteColors[SPRITE_COUNT] = {
	{100, 100, 255, 255},
	{255, 100, 255, 255},
	{150, 75, 0, 255},
	{255, 0, 0, 255},
	{0, 100, 255, 255},
	{0, 255, 0, 255},
	{255, 255, 0, 255},
	{0, 0, 0, 255}
};
tileSet swampTileset;
tileSet waterTileset;
tileSet deepWaterTileset ;
tileSet fireTileset ;
tileSet voidTileset;
tileSet thunderedTileset;
int bushFrameX = 0;
int bushFrameY = 0;

int selectedSprite = 0;
SpriteData sprites[SPRITE_COUNT];
float spriteInteractionTimer = 0.0f;

sfIntRect tile = { 0, 0, TILE_WIDTH, TILE_HEIGHT };
sfVector2f tilepos = { 0.0f,0.0f };
int selectedTiles = 1;
int selectedTexture = 1;
int selectedSpecialTiles = 1;
int selectedMusic = 0;

Tilemode selectedTileMode = 1;


float keyMapTimer = 0.0f;
int tileSelection;

char pathFile[100];

tileOf tileMap[MAP_HEIGHT][MAP_WIDTH];


tilesetType tileType;
specialTileType typeOfSpecialTile;

 
sfFont* font;
sfText* idText;



void initmap()
{
	initSpriteData();
	loadSpritesData("maps/sprites.dat");
	initTileset();
loadMap("maps/mymap.dat");
peacefulTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-grassy-peaceful.png", NULL);
tilesetBarTexture = sfTexture_createFromFile(TEXTURE_PATH"box.png", NULL);
directionTexture = sfTexture_createFromFile(TEXTURE_PATH"scroll.png", NULL);
switchRectangleTexture = sfTexture_createFromFile(TEXTURE_PATH"switch.png", NULL);
naturalTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-natural.png", NULL);
swampTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-swamp.png", NULL);
waterTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-water.png", NULL);
deepWaterTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-deep-water.png", NULL);
fireTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-fire.png", NULL);
thunderedTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-thundered.png", NULL);
plantTexture = sfTexture_createFromFile(TEXTURE_PATH"treeDestruction.png", NULL);
boulderTexture = sfTexture_createFromFile(TEXTURE_PATH"boulder.png", NULL);
electricCircuitTexture = sfTexture_createFromFile(TEXTURE_PATH"arcelectrique.png", NULL);
electricMushroomTexture = sfTexture_createFromFile(TEXTURE_PATH"champignon.png", NULL);
boulderTexture = sfTexture_createFromFile(TEXTURE_PATH"boulder.png", NULL);
voidTexture = sfTexture_createFromFile(TEXTURE_PATH"voidTile.png", NULL);
voidTilesetTexture = sfTexture_createFromFile(TEXTURE_PATH"voidTileset.png", NULL);
//electricToggleTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-thundered.png", NULL); a trouver une texture
buttonPrevPage = sfRectangleShape_create();
sfRectangleShape_setSize(buttonPrevPage, (sfVector2f) { 30.f, 30.f });
sfRectangleShape_setPosition(buttonPrevPage, (sfVector2f) { 45.f, 600.f });
sfRectangleShape_setTexture(buttonPrevPage, directionTexture,sfTrue);
sfRectangleShape_setRotation(buttonPrevPage, 180.f);

buttonNextPage = sfRectangleShape_create();
sfRectangleShape_setSize(buttonNextPage, (sfVector2f) { 30.f, 30.f });
sfRectangleShape_setPosition(buttonNextPage, (sfVector2f) { 69.f, 570.f });
sfRectangleShape_setTexture(buttonNextPage, directionTexture, sfTrue);


mouseCornerIndicator = sfRectangleShape_create();
sfRectangleShape_setSize(mouseCornerIndicator, (sfVector2f) { 4.f, 4.f });
sfRectangleShape_setFillColor(mouseCornerIndicator, sfBlack);

	RectangleTilesetPanel = sfRectangleShape_create();
	sfRectangleShape_setTexture(RectangleTilesetPanel, tilesetBarTexture, sfTrue);
	sfRectangleShape_setSize(RectangleTilesetPanel, tailleTilesetPanel);
	sfRectangleShape_setFillColor(RectangleTilesetPanel, sfWhite);
	sfRectangleShape_setPosition(RectangleTilesetPanel, PositionTilesetPanel);

	RectangleTileSelectionPanel = sfRectangleShape_create();
	sfRectangleShape_setTexture(RectangleTileSelectionPanel, tilesetBarTexture, sfTrue);
	sfRectangleShape_setSize(RectangleTileSelectionPanel, tailleTileSelectionPanel);
	sfRectangleShape_setFillColor(RectangleTileSelectionPanel, sfWhite);
	sfRectangleShape_setPosition(RectangleTileSelectionPanel, PositionTilesetPanel);

	RectangleButtonSwitchTileWall = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleButtonSwitchTileWall, tailleButtonSwitchTileWall);
	sfRectangleShape_setFillColor(RectangleButtonSwitchTileWall, sfBlue);
	sfRectangleShape_setPosition(RectangleButtonSwitchTileWall, PositionButtonSwitchTileWall);
	sfRectangleShape_setTexture(RectangleButtonSwitchTileWall, switchRectangleTexture, sfTrue);
	RectangleButtonSwitchTileMode = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleButtonSwitchTileMode, tailleButtonSwitchTileMode);
	sfRectangleShape_setFillColor(RectangleButtonSwitchTileMode, sfBlue);
	sfRectangleShape_setPosition(RectangleButtonSwitchTileMode, PositionButtonSwitchTileMode);
	sfRectangleShape_setTexture(RectangleButtonSwitchTileMode, switchRectangleTexture, sfTrue);
	mapSprite = sfSprite_create();

	font = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
	idText = sfText_create();
	sfText_setFont(idText, font);
	sfText_setCharacterSize(idText, 12);
	sfText_setFillColor(idText, sfWhite);
	sfText_setOutlineColor(idText, sfBlack);
	sfText_setOutlineThickness(idText, 1.f);
}

void updateMap(sfRenderWindow* _window)
{



	if (state == EDITOR)
	{
		keyMapTimer += GetDeltaTime();
		//récupères la position de la souris 
		mousepos = updatePixelToWorld(_window,NULL);



		tilepos.y += 10;
		sfVector2i posNewTile = { 0,0 };
		tilepos.y = 0;

		//save map et sprite pos
		if (sfKeyboard_isKeyPressed(sfKeyS) && keyMapTimer > 1.0f)
		{

			keyMapTimer = 0.0f;
			saveMap("maps/mymap.dat");
			saveSpritesData("maps/sprites.dat");

		}

		//mode tilesets
		if (selectedTileMode == 1)

		{//obtient la bonne dimension pour les tiles
			tile = giveSpriteTextureDim(tile, selectedTiles);

			//dessine la tile qui est sélectionné sur la souris
			changeTileset(selectedTexture);
			sfSprite_setTextureRect(mapSprite, tile);
			sfSprite_setPosition(mapSprite, (sfVector2f) { mousepos.x, mousepos.y });
			sfRectangleShape_setPosition(mouseCornerIndicator, (sfVector2f) { mousepos.x, mousepos.y });
			sfRenderWindow_drawSprite(_window, mapSprite, NULL);
			sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			if (selectedTiles == 0)
			{

				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
			}
			else
			{
				changeTileset(selectedTexture);
				sfRenderWindow_setMouseCursorVisible(_window, sfFalse);


				//pose la tile qui est sélectionné sur le tilemap a l'endroit de la souris
				if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight))
				{
					if (keyMapTimer > 0.02f) {
						posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
						posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
						if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT && tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType == none)
						{

							tileMap[posNewTile.y][posNewTile.x].texture = selectedTexture;
							tileMap[posNewTile.y][posNewTile.x].tileNumber = selectedTiles;
						}
						keyMapTimer = 0.0f;
					}
				}
			}
		}
		//mode specialtiles
		if (selectedTileMode == 2)
		{
			tile = giveSpriteTextureDim(tile, selectedTiles);
			//dessine la tile qui est sélectionné sur la souris
			sfSprite_setTextureRect(mapSprite, tile);
			changeSpecialTiles(selectedTexture);
			sfSprite_setPosition(mapSprite, (sfVector2f) { mousepos.x, mousepos.y });
			sfRectangleShape_setPosition(mouseCornerIndicator, (sfVector2f) { mousepos.x, mousepos.y });
			sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			sfRenderWindow_drawSprite(_window, mapSprite, NULL);

			if (selectedTiles == 0)
			{

				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
			}
			else
			{
				changeSpecialTiles(selectedTexture);
				sfRenderWindow_setMouseCursorVisible(_window, sfFalse);

			}
			//pose la tile qui est sélectionné sur le tilemap a l'endroit de la souris
				if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight))
				{
				
					if (keyMapTimer > 0.02f) {
						posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
						posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
						if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
						{
							tileSet* tilesetTile = getCurrentTileset(tileMap[posNewTile.y][posNewTile.x].texture);
							if (tilesetTile->isWall[tileMap[posNewTile.y][posNewTile.x].tileNumber] < 1 || selectedTexture == 0)
							{
								tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType = selectedTexture;
								tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.state = 0; 
							}

						}
						keyMapTimer = 0.0f;
					}
				}
			
		}
		//mode circuit_link
		if (selectedTileMode == 3){
			tile = giveSpriteTextureDim(tile, selectedTiles);

	
			sfSprite_setPosition(mapSprite, (sfVector2f) { mousepos.x, mousepos.y });
			sfRectangleShape_setPosition(mouseCornerIndicator, (sfVector2f) { mousepos.x, mousepos.y });
			sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			sfRenderWindow_drawSprite(_window, mapSprite, NULL);

				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
			
			
				//Monte l'id de circuit de la tile
			if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight))
			{

				if (keyMapTimer > 1.0f) {
					posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
					posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
					if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
					{
						tileSet* tilesetTile = getCurrentTileset(tileMap[posNewTile.y][posNewTile.x].texture);
						if (tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType == 3 || tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType == 4)
						{
							tileMap[posNewTile.y][posNewTile.x].isActivable.idActivable++;
					
						}

					}
					keyMapTimer = 0.0f;
				}
			
			}

			//Descend l'id de circuit de la tile
			if (pressed == 1 && sfMouse_isButtonPressed(sfMouseLeft))
			{

				if (keyMapTimer > 1.0f) {
					posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
					posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
					if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
					{
						tileSet* tilesetTile = getCurrentTileset(tileMap[posNewTile.y][posNewTile.x].texture);
						if (tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType == 3 || tileMap[posNewTile.y][posNewTile.x].selectedSpecialTiles.SpecialTilesType == 4 && tileMap[posNewTile.y][posNewTile.x].isActivable.idActivable> 0)
						{
							tileMap[posNewTile.y][posNewTile.x].isActivable.idActivable--;

						}

					}
					keyMapTimer = 0.0f;
				}
			}
		}
		//mode sprite
		if (selectedTileMode == 4) {
			updateSpritePlacementMode(_window);

	
		}
		//mode Music
		if (selectedTileMode == 5) {
			//pose la music qui est sélectionné sur le tilemap a l'endroit de la souris
			if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight))
			{
				if (keyMapTimer > 0.02f) {
					posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
					posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
					if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
					{
						tileSet* tilesetTile = getCurrentTileset(tileMap[posNewTile.y][posNewTile.x].texture);
						if (tilesetTile->isWall[tileMap[posNewTile.y][posNewTile.x].tileNumber] < 1)
						{
							tileMap[posNewTile.y][posNewTile.x].musicOfTile = selectedMusic;
						}

					}
					keyMapTimer = 0.0f;
				}
			}
		}
	}
}
//affiche la map
void displayMap(sfRenderWindow* _window)
{
	
	if (state != MENU)
	{
		//affiche les tiles
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			for (int y = 0; y < MAP_WIDTH; y++)
			{

				tile = giveSpriteTextureDim(tile, tileMap[x][y].tileNumber);

				tileType = tileMap[x][y].texture;
				changeTileset(tileType);
				sfSprite_setTextureRect(mapSprite, tile);
				sfSprite_setPosition(mapSprite, tilepos);
				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
			
			
				tilepos.x += tile.width;

			

			}
			tilepos.y += tile.height;
			tilepos.x = 0;
		}
		tilepos.y = 0;
		// affiche la music des tiles si en editeur music
		if (selectedTileMode == 5 && state == EDITOR)
		{
			for (int x = 0; x < MAP_HEIGHT; x++)
			{
				for (int y = 0; y < MAP_WIDTH; y++)
				{
					if (tileMap[x][y].musicOfTile > 0)
					{
						// Créer un rectangle de couleur selon la musique
						sfRectangleShape* musicIndicator = sfRectangleShape_create();
						sfRectangleShape_setSize(musicIndicator, (sfVector2f) { TILE_WIDTH, TILE_HEIGHT });
						sfRectangleShape_setPosition(musicIndicator, tilepos);

						// Couleurs selon le type de musique (même que dans le panel)
			
						if (tileMap[x][y].musicOfTile < 6)
						{
							sfRectangleShape_setFillColor(musicIndicator, musicColors[tileMap[x][y].musicOfTile]);
						}

						sfRenderWindow_drawRectangleShape(_window, musicIndicator, NULL);

						// Afficher le numéro de la musique
						char musicStr[16];
						sprintf(musicStr, "M%d", tileMap[x][y].musicOfTile);
						sfText_setString(idText, musicStr);

						sfFloatRect textBounds = sfText_getLocalBounds(idText);
						sfVector2f textPos;
						textPos.x = tilepos.x + (TILE_WIDTH - textBounds.width) / 2.0f;
						textPos.y = tilepos.y + (TILE_HEIGHT - textBounds.height) / 2.0f - 4.0f;
						sfText_setPosition(idText, textPos);
						sfRenderWindow_drawText(_window, idText, NULL);

						sfRectangleShape_destroy(musicIndicator);
					}

					tilepos.x += TILE_WIDTH;
				}
				tilepos.y += TILE_HEIGHT;
				tilepos.x = 0;
			}
			tilepos.y = 0;
		}
		// affiche les specialtiles
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			for (int y = 0; y < MAP_WIDTH; y++)
			{

				typeOfSpecialTile = tileMap[x][y].selectedSpecialTiles.SpecialTilesType;
	
				if (typeOfSpecialTile != none)
				{
					changeSpecialTiles(typeOfSpecialTile);
					// animation de l'arbuste si il se fait casser
					if (typeOfSpecialTile == plant)
					{
						if (tileMap[x][y].selectedSpecialTiles.state > 0)
						{
							tile.top = 32 * ((tileMap[x][y].selectedSpecialTiles.state ) / 4);
							tile.width = 32;
							tile.left = 32 * ((tileMap[x][y].selectedSpecialTiles.state ) % 4);
							tile.height = 32;
							sfSprite_setTextureRect(mapSprite, tile);
						}
						//Redimensionnement et repositionnement de la tile pour afficher les plantes 
						tilepos.x -= 4;
						tilepos.y -= 16;
						sfSprite_setPosition(mapSprite, tilepos);
						tilepos.x += 4;
						tilepos.y += 16;
						tile.height = 24;
						tile.width = 24;
					}
					// le mur devient transparent quand désactivé
					if (typeOfSpecialTile == electric_wall) {
					
						if (tileMap[x][y].selectedSpecialTiles.state == 1 ) {
						
							sfSprite_setColor(mapSprite, (sfColor) { 255, 255, 255, 100 }); 
						}
						else {
							sfSprite_setColor(mapSprite, sfWhite);
						}
					
						sfSprite_setPosition(mapSprite, tilepos);
					}
					else {
						sfSprite_setColor(mapSprite, sfWhite);
					}
					// est électrique quand activé et sans si désactivé
					if (typeOfSpecialTile == electric_toggle) {
						if (tileMap[x][y].selectedSpecialTiles.state > 0)
						{
							tile.left = 24;
							tile.top = 0;
						}
						else
						{
							tile.left = 0;
							tile.top = 0;
						}
							sfSprite_setTextureRect(mapSprite, tile);
				
					}
					else
					{
						sfSprite_setPosition(mapSprite, tilepos);
					}
			
					if (x > 0 && y > 0 && y <  MAP_WIDTH && x < MAP_HEIGHT)
					{
						sfRenderWindow_drawSprite(_window, mapSprite, NULL);
					
					}
					// si mode  circuit_link alors afficher l'id des circuits
					if (selectedTileMode == 3 && state == EDITOR)
					{
						if (tileMap[x][y].selectedSpecialTiles.SpecialTilesType == 3 || tileMap[x][y].selectedSpecialTiles.SpecialTilesType == 4)
						{
							char idStr[16];
							sprintf(idStr, "%d", tileMap[x][y].isActivable.idActivable);


							sfText_setString(idText, idStr);


							sfFloatRect textBounds = sfText_getLocalBounds(idText);
							sfVector2f textPos;
							textPos.x = tilepos.x + (TILE_WIDTH - textBounds.width) / 2.0f;
							textPos.y = tilepos.y + (TILE_HEIGHT - textBounds.height) / 2.0f - 4.0f;
							sfText_setPosition(idText, textPos);
							sfRenderWindow_drawText(_window, idText, NULL);
							
						}
					}
				
				}
			
				tilepos.x += tile.width;



			}
			tilepos.y += tile.height;
			tilepos.x = 0;
		}

		tilepos.y = 0;


	}

}
//change le tilesets utilisé par mapSprite
void changeTileset(tilesetType tileType)
{
	switch (tileType)
	{

	case peaceful:
		sfSprite_setTexture(mapSprite, peacefulTexture, sfTrue);
		break;
	case natural:
		sfSprite_setTexture(mapSprite, naturalTexture, sfTrue);
		break;
	case swamp:
		sfSprite_setTexture(mapSprite, swampTexture, sfTrue);
		break;
	case water:
		sfSprite_setTexture(mapSprite, waterTexture, sfTrue);
		break;
	case deepWater:
		sfSprite_setTexture(mapSprite, deepWaterTexture, sfTrue);
		break;
	case thundered:
		sfSprite_setTexture(mapSprite, thunderedTexture, sfTrue);
		break;
	case fire:
		sfSprite_setTexture(mapSprite, fireTexture, sfTrue);
		break;
	case voiding:
		sfSprite_setTexture(mapSprite, voidTilesetTexture, sfTrue);
		break;
	}
}//change la texture de specialtile utilisé par mapSprite
void changeSpecialTiles(specialTileType specialTile)
{
	switch (specialTile)
	{
	case none:
		sfSprite_setTexture(mapSprite, voidTexture, sfTrue);
		break;
	case plant:
		sfSprite_setTexture(mapSprite, plantTexture, sfTrue);
		sfSprite_setTextureRect(mapSprite, (sfIntRect){ 0,0,32,32});
		break;
	case boulder:
		sfSprite_setTexture(mapSprite, boulderTexture, sfTrue);
		break;
	case electric_toggle:
		sfSprite_setTexture(mapSprite, electricMushroomTexture, sfTrue);
		break;
	case electric_wall:
		sfSprite_setTexture(mapSprite, electricCircuitTexture, sfTrue);
		break;
	}
}
//sauvegarde la map
void saveMap(const char* filename)
{

	FILE* file = fopen(filename, "wb");
	if (file == NULL)
	{
		printf("Erreur: Impossible de créer le fichier %s\n", filename);
		return;
	}

	int width = MAP_WIDTH;
	int height = MAP_HEIGHT;
	fwrite(&width, sizeof(int), 1, file);
	fwrite(&height, sizeof(int), 1, file);

	fwrite(tileMap, sizeof(tileOf), MAP_HEIGHT * MAP_WIDTH, file);
	fclose(file);
	printf("Map sauvegardée dans %s\n", filename);
}
//charge la map
void loadMap(const char* filename)
{
	FILE* file = fopen(filename, "rb");

	if (file == NULL)
	{
		printf("Aucune sauvegarde trouvée. Création de %s...\n", filename);
		createMap();
		saveMap(filename);
		return;
	}

	int width, height; 
	fread(&width, sizeof(int), 1, file);
	fread(&height, sizeof(int), 1, file);

	if (width != MAP_WIDTH || height != MAP_HEIGHT)
	{

		fclose(file);
		return;
	}

	fread(tileMap, sizeof(tileOf), MAP_HEIGHT * MAP_WIDTH, file);

	fclose(file);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			tileMap[i][j].selectedSpecialTiles.state = 0;
			if (tileMap[i][j].selectedSpecialTiles.SpecialTilesType != 3 && tileMap[i][j].selectedSpecialTiles.SpecialTilesType != 4)
			{
				tileMap[i][j].isActivable.idActivable = 0;
			}
	

		}
	}
	printf("Map chargée depuis %s\n", filename);
}
//créer une map
void createMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			tileMap[i][j].texture = 1;
			tileMap[i][j].tileNumber = 4;
			tileMap[i][j].selectedSpecialTiles.SpecialTilesType = none;
			tileMap[i][j].selectedSpecialTiles.state = 0;
			tileMap[i][j].selectedSpecialTiles.state = 0;
			tileMap[i][j].isActivable.idActivable= 0;
			tileMap[i][j].isActivable.numberOfActivable= 0;
			tileMap[i][j].musicOfTile= 0;
		}
	}
}

sfIntRect giveSpriteTextureDim(sfIntRect tile, int tileNumber)
{

			tile.top = (tileNumber / 16) * tile.height;
			tile.left = (tileNumber - (tile.top - 8 *tile.top / tile.height) ) * tile.width;
			return tile;
}
//un update pour la viewUI
void updateTilesetPanel(sfRenderWindow* _window, sfView* _view)
{
	if (state == EDITOR)
	{

		switchTileTypeTimer += GetDeltaTime();
		mouseposViewUi = updatePixelToWorld(_window, _view);
		sfVector2i screenMousePos = sfMouse_getPositionRenderWindow(_window);
		sfVector2f screenMousePosF = { (float)screenMousePos.x, (float)screenMousePos.y };

		sfVector2f tilepos_ui = { 5.0f, 10.0f };



		tile.left = 0;
		tile.top = 0;
		tile.left += 48;
		sfRenderWindow_drawRectangleShape(_window, RectangleTilesetPanel, NULL);
		sfRenderWindow_drawRectangleShape(_window, RectangleButtonSwitchTileMode, NULL);
		sfFloatRect rectfrect = sfRectangleShape_getGlobalBounds(RectangleButtonSwitchTileMode);
		if (sfMouse_isButtonPressed(sfMouseLeft) && isInsideMouse(mouseposViewUi, rectfrect) && switchTileTypeTimer >= 0.5f)
		{
			if (selectedTileMode == 5)
			{
				selectedTileMode = 1;
			}
			else
			{
				selectedTileMode++;
			}
			switchTileTypeTimer = 0;
			selectedTexture = 1;
			selectedTiles = 1;
		}
		if (selectedTileMode == 1)
		{

			for (int i = 1; i < 9; i++)
			{

				changeTileset(i);

				sfSprite_setTextureRect(mapSprite, tile);
				sfSprite_setPosition(mapSprite, tilepos_ui);


				sfFloatRect mapfrect = sfSprite_getGlobalBounds(mapSprite);
				if (sfMouse_isButtonPressed(sfMouseLeft) &&
					isInsideMouse(mouseposViewUi, mapfrect))
				{
					selectedTexture = i;
					selectedTiles = 1;
					currentPage = 0;
				}
				
				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
				//Met le tileset en surbriance
				if (selectedTexture == i)
				{

					sfRectangleShape* highlight = sfRectangleShape_create();
					sfRectangleShape_setSize(highlight, (sfVector2f) { tile.width, tile.height });
					sfRectangleShape_setPosition(highlight, tilepos_ui);
					sfRectangleShape_setFillColor(highlight, sfTransparent);
					sfRectangleShape_setOutlineColor(highlight, sfYellow);
					sfRectangleShape_setOutlineThickness(highlight, 2.f);
					sfRenderWindow_drawRectangleShape(_window, highlight, NULL);
					sfRectangleShape_destroy(highlight);
				}
				tilepos_ui.y += tile.height + 10;
			}
			tile = giveSpriteTextureDim(tile, selectedTiles);
			changeTileset(selectedTexture);
			//Affiche la tile choisi sur la souris quand elle est dans l'EditUI
			sfSprite_setTextureRect(mapSprite, tile);
			sfSprite_setPosition(mapSprite, mouseposViewUi);
			sfRectangleShape_setPosition(mouseCornerIndicator, mouseposViewUi);
			sfRenderWindow_drawSprite(_window, mapSprite, NULL);
			sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			if (selectedTiles == 0)
			{

				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
			}
			else
			{
				changeTileset(selectedTexture);
				sfRenderWindow_setMouseCursorVisible(_window, sfFalse);

			}

		}
		if (selectedTileMode == 2)
		{

			for (int i = 0; i < 5; i++)
			{
				sfSprite_setTextureRect(mapSprite, tile);
				changeSpecialTiles(i);


				sfSprite_setPosition(mapSprite, tilepos_ui);


				sfFloatRect mapfrect = sfSprite_getGlobalBounds(mapSprite);
				if (sfMouse_isButtonPressed(sfMouseLeft) &&
					isInsideMouse(screenMousePosF, mapfrect))
				{
					selectedTexture = i;
				}

				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
				if (selectedTexture == i)
				{

					sfRectangleShape* highlight = sfRectangleShape_create();
					sfRectangleShape_setSize(highlight, (sfVector2f) { tile.width, tile.height });
					sfRectangleShape_setPosition(highlight, tilepos_ui);
					sfRectangleShape_setFillColor(highlight, sfTransparent);
					sfRectangleShape_setOutlineColor(highlight, sfYellow);
					sfRectangleShape_setOutlineThickness(highlight, 2.f);
					sfRenderWindow_drawRectangleShape(_window, highlight, NULL);
					sfRectangleShape_destroy(highlight);
				}
				tilepos_ui.y += tile.height + 10;
			}
			tile = giveSpriteTextureDim(tile, 0);
			sfSprite_setTextureRect(mapSprite, tile);
			changeSpecialTiles(selectedTexture);


			sfSprite_setPosition(mapSprite, mouseposViewUi);
			sfRectangleShape_setPosition(mouseCornerIndicator, mouseposViewUi);
			sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			sfRenderWindow_drawSprite(_window, mapSprite, NULL);
			if (selectedTiles == 0)
			{

				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
			}
			else
			{
				changeSpecialTiles(selectedTexture);
				sfRenderWindow_setMouseCursorVisible(_window, sfFalse);

			}
			if (selectedTileMode == 3)
			{

				tile = giveSpriteTextureDim(tile, 0);

				changeSpecialTiles(selectedTexture);

				sfRectangleShape_setPosition(mouseCornerIndicator, mouseposViewUi);
				sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
				sfRenderWindow_setMouseCursorVisible(_window, sfTrue);


			}
		}
		if (selectedTileMode == 4) {
			sfVector2f tilepos_ui = { 5.0f, 10.0f };


			for (int i = 0; i < SPRITE_COUNT; i++) {
				// Draw sprite icon/preview
				sfRectangleShape* spriteIcon = sfRectangleShape_create();
				sfRectangleShape_setSize(spriteIcon, (sfVector2f) { 24.f, 24.f });
				sfRectangleShape_setPosition(spriteIcon, tilepos_ui);

				// Color code each sprite type

				sfRectangleShape_setFillColor(spriteIcon, spriteColors[i]);

				sfFloatRect iconRect = sfRectangleShape_getGlobalBounds(spriteIcon);
				if (sfMouse_isButtonPressed(sfMouseLeft) && isInsideMouse(mouseposViewUi, iconRect)) {
					selectedSprite = i;
				}
		


				sfRenderWindow_drawRectangleShape(_window, spriteIcon, NULL);

				// Highlight selected sprite
				if (selectedSprite == i) {
					sfRectangleShape* highlight = sfRectangleShape_create();
					sfRectangleShape_setSize(highlight, (sfVector2f) { 24.f, 24.f });
					sfRectangleShape_setPosition(highlight, tilepos_ui);
					sfRectangleShape_setFillColor(highlight, sfTransparent);
					sfRectangleShape_setOutlineColor(highlight, sfYellow);
					sfRectangleShape_setOutlineThickness(highlight, 2.f);
					sfRenderWindow_drawRectangleShape(_window, highlight, NULL);
					sfRectangleShape_destroy(highlight);
				}

				sfRectangleShape_destroy(spriteIcon);
				tilepos_ui.y += 30.f;
			}
		}
			if (selectedTileMode == 5)
			{
			
				sfVector2f tilepos_ui = { 5.0f, 10.0f };
		

				for (int i = 0; i < 7; i++) {
					// Draw sprite icon/preview
					sfRectangleShape* musicIcon = sfRectangleShape_create();
					sfRectangleShape_setSize(musicIcon, (sfVector2f) { 24.f, 24.f });
					sfRectangleShape_setPosition(musicIcon, tilepos_ui);

					// Color code each sprite type
			
					sfRectangleShape_setFillColor(musicIcon, musicColors[i]);

					sfFloatRect iconRect = sfRectangleShape_getGlobalBounds(musicIcon);
					if (sfMouse_isButtonPressed(sfMouseLeft) && isInsideMouse(mouseposViewUi, iconRect)) {
						selectedMusic = i;
						if(selectedMusic> 0)
							ChangeMusic(i);
					}

					sfRenderWindow_drawRectangleShape(_window, musicIcon, NULL);

					//Highlight selected sprite
					if (selectedMusic == i) {
						sfRectangleShape* highlight = sfRectangleShape_create();
						sfRectangleShape_setSize(highlight, (sfVector2f) { 24.f, 24.f });
						sfRectangleShape_setPosition(highlight, tilepos_ui);
						sfRectangleShape_setFillColor(highlight, sfTransparent);
						sfRectangleShape_setOutlineColor(highlight, sfYellow);
						sfRectangleShape_setOutlineThickness(highlight, 2.f);
						sfRenderWindow_drawRectangleShape(_window, highlight, NULL);
						sfRectangleShape_destroy(highlight);
					}

					sfRectangleShape_destroy(musicIcon);
					tilepos_ui.y += 30.f;
				}
				 
			
		}

	}
}

void updateTileSelectionPanel(sfRenderWindow* _window, sfView* viewTileSelection)
{
	if (state == EDITOR)
	{
		if (selectedTileMode == 1)
		{
			switchTileTypeTimer += GetDeltaTime();
			pageButtonTimer += GetDeltaTime();

			sfRenderWindow_drawRectangleShape(_window, RectangleTileSelectionPanel, NULL);
			sfRenderWindow_drawRectangleShape(_window, RectangleButtonSwitchTileWall, NULL);
			sfRenderWindow_drawRectangleShape(_window, buttonPrevPage, NULL);
			sfRenderWindow_drawRectangleShape(_window, buttonNextPage, NULL);

			sfVector2i screenMousePos = sfMouse_getPositionRenderWindow(_window);
			sfVector2f viewMousePos = sfRenderWindow_mapPixelToCoords(_window, screenMousePos, viewTileSelection);

			tileSet* currentTileset = getCurrentTileset(selectedTexture);

			sfVector2f tilepos_ui = { 5.0f, 10.0f };
			int tilesPerRow = 3;
			int currentCol = 0;
			changeTileset(selectedTexture);

			for (int i = 0; i < currentTileset->nbOfTiles; i++)
			{
				sfFloatRect rectfrect = sfRectangleShape_getGlobalBounds(RectangleButtonSwitchTileWall);

				if (sfMouse_isButtonPressed(sfMouseLeft) && isInsideMouse(viewMousePos, rectfrect) && switchTileTypeTimer >= 0.5f)
				{
					switch (filterTile)
					{
					case isNotWall:
						filterTile = 1;
						currentPage = 0;
						break;
					case isWall:
						filterTile = 0;
						currentPage = 0;
						break;
					}
					switchTileTypeTimer = 0.f;
				}
				int filteredTiles[200];
				int filteredCount = 0;

				for (int i = 1; i < currentTileset->nbOfTiles; i++)
				{
					if (currentTileset->isWall[i] == filterTile)
					{
						filteredTiles[filteredCount] = i;
						filteredCount++;
					}
				}


				int totalPages = (filteredCount + tilesPerPage - 1) / tilesPerPage;
				if (totalPages == 0) totalPages = 1;

				if (currentPage >= totalPages) currentPage = totalPages - 1;
				if (currentPage < 0) currentPage = 0;

				sfFloatRect rectPrevPage = sfRectangleShape_getGlobalBounds(buttonPrevPage);
				sfFloatRect rectNextPage = sfRectangleShape_getGlobalBounds(buttonNextPage);

				if (sfMouse_isButtonPressed(sfMouseLeft) && pageButtonTimer >= 0.3f)
				{
					if (isInsideMouse(viewMousePos, rectPrevPage) && currentPage > 0)
					{
						currentPage--;
						pageButtonTimer = 0.f;
					}
					else if (isInsideMouse(viewMousePos, rectNextPage) && currentPage < totalPages - 1)
					{
						currentPage++;
						pageButtonTimer = 0.f;
					}
				}


				int startIndex = currentPage * tilesPerPage;
				int endIndex = startIndex + tilesPerPage;
				if (endIndex > filteredCount) endIndex = filteredCount;


				sfVector2f tilepos_ui = { 15.0f, 10.0f };
				int tilesPerRow = 3;
				int currentCol = 0;
				changeTileset(selectedTexture);

				for (int i = startIndex; i < endIndex; i++)
				{
					int tileNum = filteredTiles[i];
					tile = giveSpriteTextureDim(tile, tileNum);
					sfSprite_setTextureRect(mapSprite, tile);
					sfSprite_setPosition(mapSprite, tilepos_ui);


					if (selectedTiles == tileNum)
					{

						sfRectangleShape* highlight = sfRectangleShape_create();
						sfRectangleShape_setSize(highlight, (sfVector2f) { tile.width, tile.height });
						sfRectangleShape_setPosition(highlight, tilepos_ui);
						sfRectangleShape_setFillColor(highlight, sfTransparent);
						sfRectangleShape_setOutlineColor(highlight, sfYellow);
						sfRectangleShape_setOutlineThickness(highlight, 2.f);
						sfRenderWindow_drawRectangleShape(_window, highlight, NULL);
						sfRectangleShape_destroy(highlight);

					}

					sfFloatRect mapfrect = sfSprite_getGlobalBounds(mapSprite);
					if (sfMouse_isButtonPressed(sfMouseLeft) && isInsideMouse(viewMousePos, mapfrect))
					{
						selectedTiles = filteredTiles[i];
					}

					sfRenderWindow_drawSprite(_window, mapSprite, NULL);
				
					currentCol++;
					if (currentCol >= tilesPerRow)
					{
						currentCol = 0;
						tilepos_ui.x = 15.0f;
						tilepos_ui.y += tile.height + 5;
					}
					else
					{
						tilepos_ui.x += tile.width + 5;
					}
				}


				tile = giveSpriteTextureDim(tile, selectedTiles);

				changeTileset(selectedTexture);
				sfSprite_setTextureRect(mapSprite, tile);
				sfSprite_setPosition(mapSprite, viewMousePos);
				sfRectangleShape_setPosition(mouseCornerIndicator, viewMousePos);
				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
				sfRenderWindow_drawRectangleShape(_window, mouseCornerIndicator, NULL);
			}
		}
	}
	}
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f* _vitesse)
{

	_sprite.left += _sprite.width / 4;
	_sprite.top += _sprite.height / 2;
	_sprite.height /= 2;
	_sprite.width /= 2;
	int sideOfNewTileY = 0;
	int sideOfNewTileX = 0;
	sfVector2i isTreeInNextPosInTab = { 0,0 };
	sfVector2i isTreeInNextPosInTab2 = { 0,0 };
	sfVector2i nextPosInTab2 = { 0,0 };
	sfVector2i nextPosInTab = { 0,0 };


		float delataTime = GetDeltaTime();
			switch (_direction)
			{
			case Down:
				nextPosInTab.y = (int)((_sprite.top + (_sprite.height/2) + _vitesse->y * delataTime) );
				nextPosInTab.x = (int)(_sprite.left );
				isTreeInNextPosInTab.y = (int)((_sprite.top + 16+ (_sprite.height / 2) + _vitesse->y * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
				nextPosInTab2.x = (_sprite.left + _sprite.width) ;
				nextPosInTab2.y = (int)((_sprite.top + (_sprite.height / 2) + _vitesse->y * delataTime) );
				isTreeInNextPosInTab2.y = (int)((_sprite.top + 16 +(_sprite.height / 2) + _vitesse->y * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
				sideOfNewTileY = 1;
				break;
			case Top:
				
				nextPosInTab.y = (int)((_sprite.top  - _vitesse->y * delataTime ));
				nextPosInTab.x =(int)(_sprite.left );
				nextPosInTab2.x = (_sprite.left + _sprite.width) ;
				nextPosInTab2.y = (int)((_sprite.top - _vitesse->y * delataTime) );
				isTreeInNextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
				isTreeInNextPosInTab.y = (int)((_sprite.top + 6 - _vitesse->y * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.y = (int)((_sprite.top + 6 - _vitesse->y * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
				sideOfNewTileY = -1;
			
				break;
			case Right:
				nextPosInTab.y = (int)((_sprite.top )   );
				nextPosInTab.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) );
				nextPosInTab2.y = (_sprite.top + _sprite.height / 2) ;
				nextPosInTab2.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) );
				isTreeInNextPosInTab.y = (int)((_sprite.top + 6) / TILE_WIDTH);
				isTreeInNextPosInTab.x = (int)((_sprite.left +  _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.y = (_sprite.top+ 16 + _sprite.height / 2) / TILE_WIDTH;
				isTreeInNextPosInTab2.x = (int)((_sprite.left +  _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
				sideOfNewTileX = 1;
				break;
			case Left:
				nextPosInTab.y = (int)((_sprite.top ) );
				nextPosInTab.x = (int)((_sprite.left  - _vitesse->x * delataTime) );
				nextPosInTab2.x = (int)((_sprite.left  - _vitesse->x * delataTime) );
				nextPosInTab2.y = (_sprite.top + _sprite.height/2) ;
				isTreeInNextPosInTab.y = (int)((_sprite.top + 6) / TILE_WIDTH);
				isTreeInNextPosInTab.x = (int)((_sprite.left  - _vitesse->x * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.x = (int)((_sprite.left  - _vitesse->x * delataTime) / TILE_WIDTH);
				isTreeInNextPosInTab2.y = (_sprite.top + 16 + _sprite.height / 2) / TILE_WIDTH;
				sideOfNewTileX = -1;
				break;
			}
			
	

			
			if (isInsideMousei(nextPosInTab, GetCollisionOfDoor()) && GetMamoswineElementalCount() < 16 || isInsideMousei(nextPosInTab2, GetCollisionOfDoor()) && GetMamoswineElementalCount() < 16
				|| isInsideOpenDoor(nextPosInTab,GetCollisionOfDoor())  || isInsideOpenDoor(nextPosInTab2,GetCollisionOfDoor())
				|| isInsideMousei(nextPosInTab, GetCollisionOfNPC()) || isInsideMousei(nextPosInTab2, GetCollisionOfNPC())
				|| isInsideMousei(nextPosInTab, getMamoswineHitboxByPos(GetCollisionMamoswineFire())) || isInsideMousei(nextPosInTab2, getMamoswineHitboxByPos(GetCollisionMamoswineFire()))
				|| isInsideMousei(nextPosInTab, getMamoswineHitboxByPos(GetCollisionMamoswineWater())) || isInsideMousei(nextPosInTab2, getMamoswineHitboxByPos(GetCollisionMamoswineWater()))
				|| isInsideMousei(nextPosInTab, getMamoswineHitboxByPos(GetCollisionMamoswineElectric())) || isInsideMousei(nextPosInTab2, getMamoswineHitboxByPos(GetCollisionMamoswineElectric()))
				|| isInsideMousei(nextPosInTab, getMamoswineHitboxByPos(GetCollisionMamoswineGrass())) || isInsideMousei(nextPosInTab2, getMamoswineHitboxByPos(GetCollisionMamoswineGrass()))
				|| isInsideMousei(nextPosInTab, GetCollisionMamoswineDialga()) || isInsideMousei(nextPosInTab2, GetCollisionMamoswineDialga())
				)
			{
				return sfTrue;
			}
			nextPosInTab.y /= (int)TILE_WIDTH;
			nextPosInTab.x /= (int)TILE_WIDTH;
			nextPosInTab2.y /= (int)TILE_WIDTH;
			nextPosInTab2.x /=(int) TILE_WIDTH;
			tileSet* tilesetInFront = getCurrentTileset(tileMap[nextPosInTab.y][nextPosInTab.x].texture);
			tileSet* tilesetNearFront = getCurrentTileset(tileMap[nextPosInTab2.y][nextPosInTab2.x].texture);
			tileSet* tilesetInFrontBehind = getCurrentTileset(tileMap[nextPosInTab.y + sideOfNewTileY][nextPosInTab.x + sideOfNewTileX].texture);
			tileSet* tilesetNearFrontBehind = getCurrentTileset(tileMap[nextPosInTab2.y + sideOfNewTileY][nextPosInTab2.x + sideOfNewTileX].texture);
				if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 2 
					&& (nextPosInTab.y + sideOfNewTileY > 0 || nextPosInTab.y + sideOfNewTileY < MAP_HEIGHT)
					&& (nextPosInTab.x + sideOfNewTileX > 0 || nextPosInTab.x + sideOfNewTileX < MAP_HEIGHT)
					&& tilesetInFrontBehind->isWall[tileMap[nextPosInTab.y + sideOfNewTileY][nextPosInTab.x + sideOfNewTileX].tileNumber] <= 0
					&& tileMap[nextPosInTab.y + sideOfNewTileY][nextPosInTab.x + sideOfNewTileX].selectedSpecialTiles.SpecialTilesType == none)
				{
					playSoundBoulder();
					rockStrengthTimer += GetDeltaTime();
					if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state == 0)
					{
						tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state = 1;
					}
					if (rockStrengthTimer > 0.03f * tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state && tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state < 8)
					{
						tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state++;
					}
					if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state == 8)
					{

						tileMap[nextPosInTab.y + sideOfNewTileY][nextPosInTab.x + sideOfNewTileX].selectedSpecialTiles.SpecialTilesType = 2;
						tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType = 0;
						rockStrengthTimer = 0;

					}
				}
				if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 2 && (nextPosInTab2.y + sideOfNewTileY > 0 ||
					nextPosInTab2.y + sideOfNewTileY < MAP_HEIGHT) && (nextPosInTab2.x + sideOfNewTileX > 0 || 
					nextPosInTab2.x + sideOfNewTileX < MAP_HEIGHT )&& 
					tilesetNearFrontBehind->isWall[tileMap[nextPosInTab2.y + sideOfNewTileY][nextPosInTab2.x + sideOfNewTileX].tileNumber] <= 0
					&& tileMap[nextPosInTab2.y + sideOfNewTileY][nextPosInTab2.x + sideOfNewTileX].selectedSpecialTiles.SpecialTilesType == none)
				{
					rockStrengthTimer2 += GetDeltaTime();
					if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state == 0)
					{
						tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state = 1;
					}
					if (rockStrengthTimer2 > 0.03f * tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state && tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state < 8)
					{
						tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state++;
					}
					if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state == 8)
					{
						tileMap[nextPosInTab2.y + sideOfNewTileY][nextPosInTab2.x + sideOfNewTileX].selectedSpecialTiles.SpecialTilesType = 2;
						tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType = 0;
						rockStrengthTimer2 = 0;

					}
			
				}
			
			
			if (
				tilesetInFront->isWall[tileMap[nextPosInTab.y][nextPosInTab.x].tileNumber] > 0  
				|| tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 2
				|| tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 4
				|| tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 3 &&
				tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state == 0
				|| (tileMap[isTreeInNextPosInTab.y][isTreeInNextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 1
				
				&& tileMap[isTreeInNextPosInTab.y][isTreeInNextPosInTab.x].selectedSpecialTiles.state < 15)
			
				||tilesetNearFront->isWall[tileMap[nextPosInTab2.y][nextPosInTab2.x].tileNumber] > 0
				|| tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 2
				|| tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 4
				|| tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 3 &&
				tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state == 0
				|| (tileMap[isTreeInNextPosInTab2.y][isTreeInNextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 1
				&& tileMap[isTreeInNextPosInTab2.y][isTreeInNextPosInTab2.x].selectedSpecialTiles.state < 15))
			{
							return sfTrue;
			}
		
			if (tileMap[nextPosInTab.y][nextPosInTab.x].musicOfTile > 0)
			{
		
				setMusic(tileMap[nextPosInTab.y][nextPosInTab.x].musicOfTile);
				
			}
			if (tileMap[nextPosInTab2.y][nextPosInTab2.x].musicOfTile > 0)
			{
			
				setMusic(tileMap[nextPosInTab2.y][nextPosInTab2.x].musicOfTile);

			} 
			return sfFalse;
}
void ElectricTogglePlayerMap(sfFloatRect _sprite, Direction _direction) {

	_sprite.left += _sprite.width / 4;

	_sprite.top += _sprite.height / 2;
	_sprite.height /= 2;
	_sprite.width /= 2;

	sfVector2i nextPosInTab = { 0, 0 };
	sfVector2i nextPosInTab2 = { 0, 0 };


	switch (_direction)
	{
	case Down:
		
		nextPosInTab.y = (int)((_sprite.top + _sprite.height - 1) / TILE_WIDTH);
		nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
		nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
		nextPosInTab2.y = (int)((_sprite.top + _sprite.height  - 1) / TILE_WIDTH);

		break;
	case Top:

		nextPosInTab.y = (int)((_sprite.top - _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
		nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
		nextPosInTab2.y = (int)((_sprite.top - _sprite.height) / TILE_WIDTH);

	

		break;
	case Right:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);

		break;
	case RightTop:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);


		break;
	case  DownRight:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);

		break;
	case Left:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top) / TILE_WIDTH;


		break;
	case DownLeft:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;


		break;
	case  TopLeft:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;



		break;
	}
		
	if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == electric_toggle) {
		int currentState = tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state;
		int idActivable = tileMap[nextPosInTab.y][nextPosInTab.x].isActivable.idActivable;


		tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state = (currentState == 0) ? 1 : 0;

	
		if (checkAllTogglesActivated(idActivable)) {

			updateElectricWalls(idActivable, 1);
	
		}
		else {
			updateElectricWalls(idActivable, 0);
		}
	}
	if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == electric_toggle) {
		int currentState = tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state;
		int idActivable = tileMap[nextPosInTab2.y][nextPosInTab2.x].isActivable.idActivable;


		tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state = (currentState == 0) ? 1 : 0;


		if (checkAllTogglesActivated(idActivable)) {

			updateElectricWalls(idActivable, 1);

		}
		else {
		
			updateElectricWalls(idActivable, 0);
			
		}
	}
}
void bushCutPlayerMap(sfFloatRect _sprite, Direction _direction)
{
	playSoundTree();
	_sprite.left += _sprite.width / 4;
	
	_sprite.top += _sprite.height / 2;
	_sprite.height /= 2;
	_sprite.width /= 2;
	sfVector2i nextPosInTab = { 0,0 };
	sfVector2i nextPosInTab2 = { 0,0 };
	float delataTime = GetDeltaTime();
	switch (_direction)
	{
	case Down:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
		nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
		nextPosInTab2.y = (int)((_sprite.top + _sprite.height + TILE_WIDTH-1) / TILE_WIDTH);


		break;
	case Top:

		nextPosInTab.y = (int)((_sprite.top + _sprite.height - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
		nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
		nextPosInTab2.y = (int)((_sprite.top + _sprite.height  - TILE_WIDTH + 1) / TILE_WIDTH);


		break;
	case Right:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top ) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);

		break;
	case RightTop:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);


		break;
	case  DownRight:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
		nextPosInTab2.x = (int)((_sprite.left + _sprite.width + TILE_WIDTH - 1) / TILE_WIDTH);

		break;
	case Left:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top ) / TILE_WIDTH;


		break;
	case DownLeft:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;


		break;
	case  TopLeft:
		nextPosInTab.y = (int)((_sprite.top + _sprite.height ) / TILE_WIDTH);
		nextPosInTab.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.x = (int)((_sprite.left - TILE_WIDTH + 1) / TILE_WIDTH);
		nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;



		break;
	}

	
	if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.SpecialTilesType == 1 && tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state < 15)
	{
		bushCutTimer += GetDeltaTime();
		if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state == 0)
		{
			tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state = 1;
		}
		if (bushCutTimer > 0.03f * tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state && tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state < 15)
		{
			tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state++;
		}
		if (tileMap[nextPosInTab.y][nextPosInTab.x].selectedSpecialTiles.state == 15)
		{
			bushCutTimer = 0;
		}
	}
	if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.SpecialTilesType == 1 && tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state < 15)
	{
		bushCutTimer2 += GetDeltaTime();
		if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state == 0)
		{
			tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state = 1;
		}
	if (bushCutTimer2  > 0.03f * tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state && tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state < 15)
	{
		tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state++;
	}
	if (tileMap[nextPosInTab2.y][nextPosInTab2.x].selectedSpecialTiles.state == 15)
	{
		bushCutTimer2 = 0;
	}
}



	

}

tileSet* getCurrentTileset(tilesetType type)
{
	switch (type )
	{
	case peaceful: return &peacefulTileset;
	case natural: return &naturalTileset;
	case swamp: return &swampTileset;
	case water: return &waterTileset;
	case deepWater: return &deepWaterTileset;
	case fire: return &fireTileset;
	case thundered: return &thunderedTileset;
	case voiding: return &voidTileset;
	default: return &peacefulTileset;
	}
}
int checkAllTogglesActivated(int idActivable) {
	int totalToggles = 0;
	int activatedToggles = 0;

	
	for (int x = 0; x < MAP_HEIGHT; x++) {
		for (int y = 0; y < MAP_WIDTH; y++) {
			if (tileMap[x][y].selectedSpecialTiles.SpecialTilesType == electric_toggle &&
				tileMap[x][y].isActivable.idActivable == idActivable) {
				totalToggles++;
				if (tileMap[x][y].selectedSpecialTiles.state == 1) { 
					activatedToggles++;
				}
			}
		}
	}


	if (totalToggles > 0 && activatedToggles == totalToggles) {
		return 1;
	}
	return 0;
}
void updateElectricWalls(int idActivable, int state) {
    for (int x = 0; x < MAP_HEIGHT; x++) {
        for (int y = 0; y < MAP_WIDTH; y++) {
            if (tileMap[x][y].selectedSpecialTiles.SpecialTilesType == electric_wall && 
                tileMap[x][y].isActivable.idActivable == idActivable) {
                tileMap[x][y].selectedSpecialTiles.state = state; 
            }
        }
    }
}
sfBool canPlaceSpriteAt(sfVector2f position, sfIntRect spriteBounds) {

	int tileMinX = (int)(position.x / TILE_WIDTH);
	int tileMinY = (int)(position.y / TILE_HEIGHT);
	int tileMaxX = (int)((position.x + spriteBounds.width) / TILE_WIDTH);
	int tileMaxY = (int)((position.y + spriteBounds.height) / TILE_HEIGHT);


	for (int y = tileMinY; y <= tileMaxY; y++) {
		for (int x = tileMinX; x <= tileMaxX; x++) {
	
			if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
				return sfFalse;
			}

	
			tileSet* tileset = getCurrentTileset(tileMap[y][x].texture);
			if (tileset->isWall[tileMap[y][x].tileNumber] > 0) {
				return sfFalse;
			}

			if (tileMap[y][x].selectedSpecialTiles.SpecialTilesType == boulder ||
				(tileMap[y][x].selectedSpecialTiles.SpecialTilesType == electric_wall &&
					tileMap[y][x].selectedSpecialTiles.state == 0)) {
				return sfFalse;
			}
		}
	}

	return sfTrue;
}
void updateSpritePlacementMode(sfRenderWindow* _window) {
	spriteInteractionTimer += GetDeltaTime();
	mousepos = updatePixelToWorld(_window, NULL);

	sfVector2f snappedPos = mousepos;

	snappedPos.x = ((int)(mousepos.x / TILE_WIDTH)) * TILE_WIDTH;
	snappedPos.y = ((int)(mousepos.y / TILE_HEIGHT)) * TILE_HEIGHT;

	if (sfKeyboard_isKeyPressed(sfKeyE) && selectedSprite >= 3 && selectedSprite <= 6&&spriteInteractionTimer > 0.5f)
	{

		if (sprites[selectedSprite].FrameY < 6)
			sprites[selectedSprite].FrameY += 2;
		else
			sprites[selectedSprite].FrameY = 0;
		spriteInteractionTimer = 0.0f;
	}
	if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight) && spriteInteractionTimer > 0.2f) {
		if (canPlaceSpriteAt(snappedPos, sprites[selectedSprite].bounds)) {
			if (sprites[selectedSprite].type == SPRITE_DOOR)
			{
				snappedPos.y -= sprites[selectedSprite].bounds.height *3 ;
			}
			else {
				snappedPos.y -= sprites[selectedSprite].bounds.height;
			}
			sprites[selectedSprite].position = snappedPos;
		

	
			updateSpritePositionsFromData();
		}
		else {
	
		}
		spriteInteractionTimer = 0.0f;
	}


	sfRectangleShape* preview = sfRectangleShape_create();
	sfRectangleShape_setSize(preview, (sfVector2f) {
		sprites[selectedSprite].bounds.width,
			sprites[selectedSprite].bounds.height
	});
	sfRectangleShape_setPosition(preview, snappedPos);


	if (canPlaceSpriteAt(snappedPos, sprites[selectedSprite].bounds)) {
		sfRectangleShape_setFillColor(preview, (sfColor) { 0, 255, 0, 100 }); 
	}
	else {
		sfRectangleShape_setFillColor(preview, (sfColor) { 255, 0, 0, 100 }); 
	}
	sfRectangleShape_setOutlineColor(preview, sfYellow);
	sfRectangleShape_setOutlineThickness(preview, 2.f);

	sfRenderWindow_drawRectangleShape(_window, preview, NULL);
	sfRectangleShape_destroy(preview);


	sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
}
void initSpriteData() {

	sprites[SPRITE_PLAYER].type = SPRITE_PLAYER;
	sprites[SPRITE_PLAYER].position = (sfVector2f){ 1200.0f, 300.0f };
	sprites[SPRITE_PLAYER].bounds = (sfIntRect){ 0, 0, 48, 24 };

	sprites[SPRITE_NPC].type = SPRITE_NPC;
	sprites[SPRITE_NPC].position = (sfVector2f){ 1200.0f, 900.0f };
	sprites[SPRITE_NPC].bounds = (sfIntRect){ 0, 0, 26, 19 };

	sprites[SPRITE_DOOR].type = SPRITE_DOOR;
	sprites[SPRITE_DOOR].position = (sfVector2f){ 1201.0f, 600.0f };
	sprites[SPRITE_DOOR].bounds = (sfIntRect){ 0, 0, 118, 42 };

	sprites[SPRITE_MAMOSWINE_FIRE].type = SPRITE_MAMOSWINE_FIRE;
	sprites[SPRITE_MAMOSWINE_FIRE].position = (sfVector2f){ 1000.0f, 900.0f };
	sprites[SPRITE_MAMOSWINE_FIRE].bounds = (sfIntRect){ 0, 0, 48, 24 };

	sprites[SPRITE_MAMOSWINE_WATER].type = SPRITE_MAMOSWINE_WATER;
	sprites[SPRITE_MAMOSWINE_WATER].position = (sfVector2f){ 1100.0f, 700.0f };
	sprites[SPRITE_MAMOSWINE_WATER].bounds = (sfIntRect){ 0, 0, 48, 24 };

	sprites[SPRITE_MAMOSWINE_GRASS].type = SPRITE_MAMOSWINE_GRASS;
	sprites[SPRITE_MAMOSWINE_GRASS].position = (sfVector2f){ 900.0f, 900.0f };
	sprites[SPRITE_MAMOSWINE_GRASS].bounds = (sfIntRect){ 0, 0, 48, 24 };

	sprites[SPRITE_MAMOSWINE_ELECTRIC].type = SPRITE_MAMOSWINE_ELECTRIC;
	sprites[SPRITE_MAMOSWINE_ELECTRIC].position = (sfVector2f){ 1190.0f, 460.0f };
	sprites[SPRITE_MAMOSWINE_ELECTRIC].bounds = (sfIntRect){ 0, 0, 48, 24 };

	sprites[SPRITE_MAMOSWINE_DIALGA].type = SPRITE_MAMOSWINE_DIALGA;
	sprites[SPRITE_MAMOSWINE_DIALGA].position = (sfVector2f){ 1180.0f, 100.0f };
	sprites[SPRITE_MAMOSWINE_DIALGA].bounds = (sfIntRect){ 0, 0, 57, 33 };
}
void saveSpritesData(const char* filename) {
	FILE* file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Error: Cannot create file %s\n", filename);
		return;
	}

	fwrite(sprites, sizeof(SpriteData), SPRITE_COUNT, file);
	fclose(file);
	printf("Sprites saved to %s\n", filename);

}
void updateSpritePositionsFromData() {

	setPlayerPosition(sprites[SPRITE_PLAYER].position);
	setNPCPosition(sprites[SPRITE_NPC].position);
	setDoorPosition(sprites[SPRITE_DOOR].position);
	setMamoswineFirePosition(sprites[SPRITE_MAMOSWINE_FIRE].position, sprites[SPRITE_MAMOSWINE_FIRE].FrameY);
	setMamoswineWaterPosition(sprites[SPRITE_MAMOSWINE_WATER].position, sprites[SPRITE_MAMOSWINE_WATER].FrameY);
	setMamoswineGrassPosition(sprites[SPRITE_MAMOSWINE_GRASS].position, sprites[SPRITE_MAMOSWINE_GRASS].FrameY);
	setMamoswineElectricPosition(sprites[SPRITE_MAMOSWINE_ELECTRIC].position, sprites[SPRITE_MAMOSWINE_ELECTRIC].FrameY);
	setMamoswineDialgaPosition(sprites[SPRITE_MAMOSWINE_DIALGA].position);
}
sfVector2f getPlayerSpawnPoint()
{
	return sprites[SPRITE_PLAYER].position;
}


void loadSpritesData(const char* filename) {
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		printf("No sprite data found. Using defaults...\n");
		initSpriteData();
		saveSpritesData(filename);
		return;
	}

	fread(sprites, sizeof(SpriteData), SPRITE_COUNT, file);
	fclose(file);
	printf("Sprites loaded from %s\n", filename);


	updateSpritePositionsFromData();
}

void initTileset()
{
	//Equivalent des tilesets en binaire 1 /si c'est un wall 0 sinon
	//16 tiles par ligne
	//{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 //1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
	 peacefulTileset = (tileSet){ peaceful,151,
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,
	 1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,
	 1,1,1,0,0,0,0,0,1,1,1,1,0,1,1,0,
	 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,
	 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0} };
	naturalTileset = (tileSet){ natural,128,
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0} };

	swampTileset = (tileSet){ swamp,128,
	{1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,

	 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,0,0,0} };

	waterTileset = (tileSet){ water,137,
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,0,0,0,0,0,0,0,0} };

	deepWaterTileset = (tileSet){ deepWater,129,
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1} };
	fireTileset = (tileSet){ fire,133,
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,
	 1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,
	 1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,
	 0,0,0,1,1,1,1,0,1,1,0,0,0,0,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,
	 0,0,0,0,0} };

	thunderedTileset = (tileSet){ thundered,164,
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,
	 1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	 0,0,0,1,1,1,1,0,1,1,0,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,
	 0,0,0,0} };
	voidTileset = (tileSet){ voiding ,68,
	{1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,
	 1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,
	 0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
	 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1} };}
