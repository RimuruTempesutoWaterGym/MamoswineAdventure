
#include "map.h"
sfRectangleShape* selectTileSetSquare;
sfVector2i mousepos;
sfRectangleShape* RectangleTilesetPanel;
sfVector2f tailleTilesetPanel = { TILE_WIDTH + 10.f, TILE_HEIGHT*MAP_HEIGHT };
sfVector2f PositionTilesetPanel = { 0.f,0.f };
sfSprite* mapSprite;
sfTexture* peacefulTexture;
sfTexture* naturalTexture;
sfTexture* swampTexture;
sfTexture* waterTexture;
sfTexture* deepWaterTexture;
sfTexture* fireTexture;
sfTexture* thunderedTexture;

sfIntRect tile = { 0, 0, TILE_WIDTH, TILE_HEIGHT };
sfVector2f tilepos = { 0.0f,0.0f };
int selectedTiles = 1;
int selectedTexture = 1;

float keyMapTimer = 0.0f;
int tileSelection;
typedef struct {
	tilesetType tileset;
	int isWall[30];
	char tilesetName[30];
} tileSet;
typedef struct {
	int texture;
	int tileNumber;
} tileOf;
char pathFile[100];
tileOf tileMap[MAP_HEIGHT][MAP_WIDTH];
tilesetType tileType;

 




void initmap()
{
	loadMap("maps/mymap.dat");
	RectangleTilesetPanel = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleTilesetPanel, tailleTilesetPanel);
	sfRectangleShape_setFillColor(RectangleTilesetPanel, sfWhite);
	sfRectangleShape_setPosition(RectangleTilesetPanel, PositionTilesetPanel);
	peacefulTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-grassy-peaceful.png", NULL);
	naturalTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-natural.png", NULL);
	swampTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-swamp.png", NULL);
	waterTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-water.png", NULL);
	deepWaterTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-deep-water.png", NULL);
	fireTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-fire.png", NULL);
	thunderedTexture = sfTexture_createFromFile(TEXTURE_PATH"tile-thundered.png", NULL); 
	mapSprite = sfSprite_create();


}

void updateMap(sfRenderWindow* _window)
{
	if (state == EDITOR)
	{
		mousepos = sfMouse_getPositionRenderWindow(_window);

	tilepos.y +=10;
	sfVector2i posNewTile = { 0,0 };
	sfRenderWindow_drawRectangleShape(_window, RectangleTilesetPanel, NULL);
	//if(tileSection  == 1)

	for (int i = 1; i < 8; i++)
	{
	
		changeTileset(i);
		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, tilepos);
		
		 
	
		sfFloatRect mapfrect = sfSprite_getGlobalBounds(mapSprite);
		if (sfMouse_isButtonPressed(sfMouseLeft) &&
			isInside(mousepos, mapfrect))
		{
			selectedTexture = i;
				selectedTiles = 1;
		}
	
		sfRenderWindow_drawSprite(_window, mapSprite, NULL);
		
		tilepos.y += tile.height + 10; 
	}
	tilepos.y = 0;
		keyMapTimer += GetDeltaTime();
		if (sfKeyboard_isKeyPressed(sfKeyN) && selectedTiles < 24 && keyMapTimer > 0.5f)
		{
			selectedTiles++;
			keyMapTimer = 0.0f;
		}
		if (sfKeyboard_isKeyPressed(sfKeyS) && keyMapTimer > 1.f)
		{
			saveMap("maps/mymap.dat");
			keyMapTimer = 0.0f;
		}

		if (sfKeyboard_isKeyPressed(sfKeyB) && selectedTiles > 1 && keyMapTimer > 0.5f)
		{
			selectedTiles--;
			keyMapTimer = 0.0f;
		}
		tile.left = selectedTiles * tile.width;
		tile.top = 0; 

	

		changeTileset(selectedTexture);
		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, (sfVector2f) { (float)mousepos.x, (float)mousepos.y });
		sfRenderWindow_drawSprite(_window, mapSprite, NULL);
		if (selectedTiles == 0)
		{
			
			sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
		}
		else
		{
			changeTileset(selectedTexture);
			sfRenderWindow_setMouseCursorVisible(_window, sfFalse);

			if (pressed == 1 && sfMouse_isButtonPressed(sfMouseRight))
			{
				if (keyMapTimer > 0.02f) {
					posNewTile.x = (int)(mousepos.x / TILE_WIDTH);
					posNewTile.y = (int)(mousepos.y / TILE_WIDTH);
					if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
					{
						
						tileMap[posNewTile.y][posNewTile.x].texture = selectedTexture;  
						tileMap[posNewTile.y][posNewTile.x].tileNumber = selectedTiles;
					}
					keyMapTimer = 0.0f;
				}
			}
		}
	}
}
void displayMap(sfRenderWindow* _window)
{
	if (state != MENU)
	{
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			for (int y = 0; y < MAP_WIDTH; y++)
			{

				tile.left = tileMap[x][y].tileNumber * tile.width;
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
	}
}
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direcstion, sfVector2f _vector)
{
	sfVector2i nextPosInTab = { 0,0 };
	sfVector2i nextPosInTab2 = { 0,0 };

	if (_direcstion == Top)
	{
		nextPosInTab.x = _sprite.left / 32;
		nextPosInTab.y = (_sprite.top - _vector.y * GetDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.left + _sprite.width) / 32;
		nextPosInTab2.y = (_sprite.top - _vector.y * GetDeltaTime()) / 32;
	}
	if (_direcstion == Down)
	{
		nextPosInTab.x = _sprite.left / 32;
		nextPosInTab.y = (_sprite.top + _vector.y * GetDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.left + _sprite.width) / 32;
		nextPosInTab2.y = (_sprite.top + _vector.y * GetDeltaTime()) / 32;
	}
	if (_direcstion == Right)
	{
		nextPosInTab.x = _sprite.left / 32;
		nextPosInTab.y = (_sprite.top + _vector.y * GetDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.left + _sprite.width) / 32;
		nextPosInTab2.y = (_sprite.top + _vector.y * GetDeltaTime()) / 32;
	}
	if (_direcstion == Left)
	{
		nextPosInTab.x = _sprite.left / 32;
		nextPosInTab.y = (_sprite.top + _vector.y * GetDeltaTime()) / 32;
		nextPosInTab2.x = (_sprite.left + _sprite.width) / 32;
		nextPosInTab2.y = (_sprite.top - _vector.y * GetDeltaTime()) / 32;
	}
	// Si la ou les case(s) est une case non traversable (entre 3 et 6)
	if (tileMap[nextPosInTab.y][nextPosInTab.x].tileNumber >= 3 && tileMap[nextPosInTab.y][nextPosInTab.x].tileNumber <= 6 || tileMap[nextPosInTab2.y][nextPosInTab2.x].tileNumber >= 3 && tileMap[nextPosInTab2.y][nextPosInTab2.x].tileNumber <= 6)
	{
		return sfTrue;
	}

	return sfFalse;
}



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
	}
}
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
	printf("Map chargée depuis %s\n", filename);
}
void createMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			tileMap[i][j].texture = 1;
			tileMap[i][j].tileNumber = 4;
		}
	}
}