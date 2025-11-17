
#include "map.h"

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
int selectedTiles = 0;

float keyMapTimer = 0.0f;
typedef enum {
	peaceful = 1,
	natural,
	swamp,
	water,
	deepWater,
	thundered,
	fire,

}tilesetType;
//typedef struct {
//	tilesetType tileset;
//	int isWall[30];
//	char tilesetName[30];
//} tileset;
typedef struct {
	int texture;
	int tileNumber;
} tileOf;
char pathFile[100];

tilesetType tileType;

tileOf tileMap[MAP_HEIGHT][MAP_WIDTH] =
{
 { {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{{2,2}, {3,2}, {4,2}, {5,2},{6,3},{7,3},{2,3},{2,3},{2,3},{2,4},{2,4},{2,4},{2,4},{2,4},{2,4},{1,2}, },
{{ 1,2 },{1,2},{1,2},{1,2}, {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},},
{{2,2}, {2,2}, {2,2}, {2,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{ { 1,2 },{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{{2,2}, {2,2}, {2,2}, {2,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
 {{ 1,2 },{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, {1,2},{1,2},{1,2},{1,2},},
{{2,2}, {2,2}, {2,2}, {2,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
 {{ 1,2 },{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{{2,2}, {2,2}, {2,2}, {2,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{ { 1,2 },{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{ {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{{2,2}, {2,2}, {2,2}, {2,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2}, },
{{2,2}, {2,2}, {2,2}, {2,2}, {1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},{1,2},}

};


void initmap()
{

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
	tilepos.y +=10;
	sfVector2i posNewTile = { 0,0 };
	for (int i = 0; i < 8; i++)
	{
		sfSprite_setTexture(mapSprite, thunderedTexture, sfTrue);
		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, tilepos);
		sfRenderWindow_drawSprite(_window, mapSprite, NULL);
		tilepos.y += tile.width+10;
	};
	tilepos.y = 0;
		keyMapTimer += GetDeltaTime();
		if (sfKeyboard_isKeyPressed(sfKeyAdd) && selectedTiles < 6 && keyMapTimer > 0.5f)
		{
			selectedTiles++;
			keyMapTimer = 0.0f;
		}
		if (sfKeyboard_isKeyPressed(sfKeySubtract) && selectedTiles > 0 && keyMapTimer > 0.5f)
		{
			selectedTiles--;
			keyMapTimer = 0.0f;
		}


		tile.left = selectedTiles * tile.width;


		sfSprite_setTextureRect(mapSprite, tile);
		sfSprite_setPosition(mapSprite, (sfVector2f) { (float)sfMouse_getPositionRenderWindow(_window).x, (float)sfMouse_getPositionRenderWindow(_window).y });
		sfRenderWindow_drawSprite(_window, mapSprite, NULL);
		if (selectedTiles == 0)
			sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
		else
		{
			sfRenderWindow_setMouseCursorVisible(_window, sfFalse);
			if (pressed == 1)
			{
				if (keyMapTimer > 0.02f) {
					posNewTile.x = (int)(sfMouse_getPositionRenderWindow(_window).x / TILE_WIDTH);
					posNewTile.y = (int)(sfMouse_getPositionRenderWindow(_window).y / TILE_WIDTH);
					if (posNewTile.x >= 0 && posNewTile.x < MAP_WIDTH && posNewTile.y >= 0 && posNewTile.y < MAP_HEIGHT)
					{
						tileMap[posNewTile.y][posNewTile.x].tileNumber = selectedTiles;
					}
					keyMapTimer = 0.0f;
				}
			}
		}
	}
void displayMap(sfRenderWindow* _window)
{
	for (int x = 0; x < MAP_HEIGHT; x++)
	{
		for (int y = 0; y < MAP_WIDTH; y++)
		{

			tile.left = tileMap[x][y].tileNumber * tile.width;
			tileType = tileMap[x][y].texture;
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

