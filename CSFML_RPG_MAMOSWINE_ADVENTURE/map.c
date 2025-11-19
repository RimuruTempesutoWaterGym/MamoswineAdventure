
#include "map.h"
sfRectangleShape* selectTileSetSquare;
sfVector2f mousepos;
sfRectangleShape* RectangleTilesetPanel;
sfRectangleShape* RectangleTileSelectionPanel;
sfRectangleShape* RectangleButtonSwitchTileWall;
sfVector2f tailleTilesetPanel = { TILE_WIDTH + 10.f, TILE_HEIGHT*MAP_HEIGHT };
sfVector2f tailleTileSelectionPanel = { 100.f, TILE_HEIGHT * MAP_HEIGHT };
sfVector2f tailleButtonSwitchTileWall = { 50.f, 20.f };
sfVector2f PositionTilesetPanel = { 0.f,0.f };
sfVector2f PositionButtonSwitchTileWall = { 25.f,530.f };
sfSprite* mapSprite;
sfTexture* peacefulTexture;
sfTexture* naturalTexture;
sfTexture* swampTexture;
sfTexture* waterTexture;
sfTexture* deepWaterTexture;
sfTexture* fireTexture;
sfTexture* thunderedTexture;
selectionTileType filterTile = 0;
float switchTileTypeTimer = 0.0f;

int currentPage = 0;
int tilesPerPage = 45;  // 15 colonnes × 3 lignes = 45 tiles par page
float pageButtonTimer = 0.0f;
sfRectangleShape* buttonPrevPage;
sfRectangleShape* buttonNextPage;

tileSet peacefulTileset;
tileSet naturalTileset;
/*what is not a wall */ tileSet swampTileset;
tileSet waterTileset;
tileSet deepWaterTileset ;
tileSet fireTileset ;
tileSet thunderedTileset;


sfIntRect tile = { 0, 0, TILE_WIDTH, TILE_HEIGHT };
sfVector2f tilepos = { 0.0f,0.0f };
int selectedTiles = 1;
int selectedTexture = 1;


float keyMapTimer = 0.0f;
int tileSelection;

char pathFile[100];
tileOf tileMap[MAP_HEIGHT][MAP_WIDTH];
tilesetType tileType;

 




void initmap()
{
	initTileset();
loadMap("maps/mymap.dat");

buttonPrevPage = sfRectangleShape_create();
sfRectangleShape_setSize(buttonPrevPage, (sfVector2f) { 40.f, 30.f });
sfRectangleShape_setFillColor(buttonPrevPage, sfColor_fromRGB(100, 100, 255));
sfRectangleShape_setPosition(buttonPrevPage, (sfVector2f) { 5.f, 570.f });

buttonNextPage = sfRectangleShape_create();
sfRectangleShape_setSize(buttonNextPage, (sfVector2f) { 40.f, 30.f });
sfRectangleShape_setFillColor(buttonNextPage, sfColor_fromRGB(100, 100, 255));
sfRectangleShape_setPosition(buttonNextPage, (sfVector2f) { 55.f, 570.f });


	RectangleTilesetPanel = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleTilesetPanel, tailleTilesetPanel);
	sfRectangleShape_setFillColor(RectangleTilesetPanel, sfWhite);
	sfRectangleShape_setPosition(RectangleTilesetPanel, PositionTilesetPanel);
	RectangleTileSelectionPanel = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleTileSelectionPanel, tailleTileSelectionPanel);
	sfRectangleShape_setFillColor(RectangleTileSelectionPanel, sfWhite);
	sfRectangleShape_setPosition(RectangleTileSelectionPanel, PositionTilesetPanel);
	RectangleButtonSwitchTileWall = sfRectangleShape_create();
	sfRectangleShape_setSize(RectangleButtonSwitchTileWall, tailleButtonSwitchTileWall);
	sfRectangleShape_setFillColor(RectangleButtonSwitchTileWall, sfBlue);
	sfRectangleShape_setPosition(RectangleButtonSwitchTileWall, PositionButtonSwitchTileWall);
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

		mousepos = updatePixelToWorld(_window);
	


	tilepos.y +=10;
	sfVector2i posNewTile = { 0,0 };
	
	tilepos.y = 0;
	
		keyMapTimer += GetDeltaTime();
		if (sfKeyboard_isKeyPressed(sfKeyN) && selectedTiles < 100 && keyMapTimer > 0.5f)
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

		
	
		tile = giveSpriteTextureDim(tile, selectedTiles);
		

		changeTileset(selectedTexture);
		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, (sfVector2f) { mousepos.x, mousepos.y });
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
	}
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
sfIntRect giveSpriteTextureDim(sfIntRect tile, int tileNumber)
{

			tile.top = (tileNumber / 16) * tile.height;
			tile.left = (tileNumber - (tile.top - 8 *tile.top / tile.height) ) * tile.width;
			return tile;
}
void updateTilesetPanel(sfRenderWindow* _window)
{
	if (state == EDITOR)
	{
		mousepos = updatePixelToWorld(_window);
		sfVector2i screenMousePos = sfMouse_getPositionRenderWindow(_window);
		sfVector2f screenMousePosF = { (float)screenMousePos.x, (float)screenMousePos.y };

		sfVector2f tilepos_ui = { 5.0f, 10.0f };


		sfRenderWindow_drawRectangleShape(_window, RectangleTilesetPanel, NULL);
		tile.left = 0;
		tile.top = 0;
		tile.left += 48;
		for (int i = 1; i < 8; i++)
		{
			changeTileset(i);
	
			sfSprite_setTextureRect(mapSprite, tile);
			sfSprite_setPosition(mapSprite, tilepos_ui);

			
			sfFloatRect mapfrect = sfSprite_getGlobalBounds(mapSprite);
			if (sfMouse_isButtonPressed(sfMouseLeft) &&
				isInside(screenMousePosF, mapfrect))
			{
				selectedTexture = i;
				selectedTiles = 1;
				currentPage = 0;
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
		tile = giveSpriteTextureDim(tile, selectedTiles);
		changeTileset(selectedTexture);

		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, (sfVector2f) { screenMousePosF.x, screenMousePosF.y });
		sfRenderWindow_drawSprite(_window, mapSprite, NULL);
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
}
void updateTileSelectionPanel(sfRenderWindow* _window, sfView* viewTileSelection)
{
	if (state == EDITOR)
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

			if (sfMouse_isButtonPressed(sfMouseLeft) && isInside(viewMousePos, rectfrect) && switchTileTypeTimer >= 0.5f)
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
				if (isInside(viewMousePos, rectPrevPage) && currentPage > 0)
				{
					currentPage--;
					pageButtonTimer = 0.f;
				}
				else if (isInside(viewMousePos, rectNextPage) && currentPage < totalPages - 1)
				{
					currentPage++;
					pageButtonTimer = 0.f;
				}
			}


			int startIndex = currentPage * tilesPerPage;
			int endIndex = startIndex + tilesPerPage;
			if (endIndex > filteredCount) endIndex = filteredCount;


			sfVector2f tilepos_ui = { 5.0f, 10.0f };
			int tilesPerRow = 3;
			int currentCol = 0;
			changeTileset(selectedTexture);

			for (int i = startIndex; i < endIndex; i++)
			{
				int tileNum = filteredTiles[i];
				tile = giveSpriteTextureDim(tile, tileNum);
				sfSprite_setTextureRect(mapSprite, tile);
				sfSprite_setPosition(mapSprite, tilepos_ui);
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
				if (sfMouse_isButtonPressed(sfMouseLeft) && isInside(viewMousePos, mapfrect))
				{
					selectedTiles = tileNum;
				}

				sfRenderWindow_drawSprite(_window, mapSprite, NULL);

				currentCol++;
				if (currentCol >= tilesPerRow)
				{
					currentCol = 0;
					tilepos_ui.x = 5.0f;
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
				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
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
	default: return &peacefulTileset;
	}
}
void initTileset()
{
	//Equivalent des tilesets en binaire 1 si c'est un wall 0 sinon
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
	 0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,
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
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	waterTileset = (tileSet){ water,129,
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1} };

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
	 1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,
	 0,0,0,0} };

}