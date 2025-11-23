
#include "map.h"
sfRectangleShape* selectTileSetSquare;
sfVector2f mousepos;
sfRectangleShape* RectangleTilesetPanel;
sfRectangleShape* RectangleTileSelectionPanel;
sfRectangleShape* RectangleButtonSwitchTileWall;
sfVector2f tailleTilesetPanel = { TILE_WIDTH + 10.f, TILE_HEIGHT*MAP_HEIGHT };
sfVector2f tailleTileSelectionPanel = { 110.f, TILE_HEIGHT * MAP_HEIGHT }; 
sfVector2f tailleButtonSwitchTileWall = { 70.f, 25.f };
sfVector2f PositionTilesetPanel = { 0.f,-100.f };
sfVector2f PositionButtonSwitchTileWall = { 20.f,525.f };
sfSprite* mapSprite;
sfTexture* peacefulTexture;
sfTexture* naturalTexture;
sfTexture* swampTexture;
sfTexture* waterTexture;
sfTexture* deepWaterTexture;
sfTexture* fireTexture;
sfTexture* plantTexture;
sfTexture* boulderTexture;
sfTexture* electricToggleTexture;
sfTexture* switchRectangleTexture;
sfTexture* thunderedTexture;
sfTexture* tilesetBarTexture;
sfTexture*	directionTexture;
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
int selectedSpecialTiles = 1;


float keyMapTimer = 0.0f;
int tileSelection;

char pathFile[100];
tileOf tileMap[MAP_HEIGHT][MAP_WIDTH];
tilesetType tileType;
specialTileType specialTile;

 




void initmap()
{

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
	mapSprite = sfSprite_create();


}

void updateMap(sfRenderWindow* _window)
{

	
	if (state == EDITOR)
	{
		keyMapTimer += GetDeltaTime();
		mousepos = updatePixelToWorld(_window);
	


	tilepos.y +=10;
	sfVector2i posNewTile = { 0,0 };
	
	tilepos.y = 0;
	
	
		if (sfKeyboard_isKeyPressed(sfKeyS) && keyMapTimer > 1.0f)
		{
			printf("%f", keyMapTimer);
			keyMapTimer = 0.0f;
			saveMap("maps/mymap.dat");
			
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

		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			for (int y = 0; y < MAP_WIDTH; y++)
			{
				specialTile = 1;
			
				if (specialTile != none)
				{
					changeSpecialTiles(specialTile);
					sfSprite_setPosition(mapSprite, tilepos);
					if (x > 0 && y > 0 && y <  MAP_WIDTH && x < MAP_HEIGHT)
					{
						sfRenderWindow_drawSprite(_window, mapSprite, NULL);
					
					}

					if (specialTile == plant)
					{
						tilepos.x += 4;
						tilepos.y += 16;
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
void changeSpecialTiles(specialTileType specialTile)
{
	switch (specialTile)
	{

	case plant:
		sfSprite_setTexture(mapSprite, plantTexture, sfTrue);
		tilepos.x -= 4;
		tilepos.y -= 16;

		sfSprite_setTextureRect(mapSprite, (sfIntRect){0,0,32,32});
		break;
	case boulder:
		sfSprite_setTexture(mapSprite, boulderTexture, sfTrue);
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
			tileMap[i][j].selectedSpecialTiles = 0;
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
				sfRenderWindow_drawSprite(_window, mapSprite, NULL);
			}
		}
	}
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f* _vitesse)
{

	sfVector2i nextPosInTab = { 0,0 };
	sfVector2i nextPosInTab2 = { 0,0 };


		float delataTime = GetDeltaTime();
			switch (_direction)
			{
			case Down:
				nextPosInTab.y = (int)((_sprite.top + _sprite.height + _vitesse->y * delataTime) / TILE_WIDTH);
				nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
				nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
				nextPosInTab2.y = (int)((_sprite.top + _sprite.height + _vitesse->y * delataTime) / TILE_WIDTH);
			
				break;
			case Top:
				
				nextPosInTab.y = (int)((_sprite.top + (_sprite.height/2) - _vitesse->y * delataTime )/ TILE_WIDTH);
				nextPosInTab.x =(int)(_sprite.left / TILE_WIDTH);
				nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
				nextPosInTab2.y = (int)((_sprite.top + (_sprite.height / 2) - _vitesse->y * delataTime) / TILE_WIDTH);
		
			
				break;
			case Right:
				nextPosInTab.y = (int)((_sprite.top +(_sprite.height / 2))   / TILE_WIDTH);
				nextPosInTab.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
				nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
				nextPosInTab2.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
		
				break;
			case Left:
				nextPosInTab.y = (int)((_sprite.top + (_sprite.height / 2)) / TILE_WIDTH);
				nextPosInTab.x = (int)((_sprite.left  - _vitesse->x * delataTime) / TILE_WIDTH);
				nextPosInTab2.x = (int)((_sprite.left  - _vitesse->x * delataTime) / TILE_WIDTH);
				nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
				
		
				break;
			}
			tileSet* tilesetInFront = getCurrentTileset(tileMap[nextPosInTab.y][nextPosInTab.x].texture);
			tileSet* tilesetNearFront = getCurrentTileset(tileMap[nextPosInTab2.y][nextPosInTab2.x].texture);
			
			if (tilesetInFront->isWall[tileMap[nextPosInTab.y][nextPosInTab.x].tileNumber] > 0 || tilesetNearFront->isWall[tileMap[nextPosInTab2.y][nextPosInTab2.x].tileNumber] > 0)
			{
							return sfTrue;
			}
				
			return sfFalse;
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

}