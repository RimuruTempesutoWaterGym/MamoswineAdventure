
#include "tools.h"



typedef enum {
	peaceful = 1,
	natural,
	swamp,
	water,
	deepWater,
	thundered,
	fire,

}tilesetType;
typedef enum {
	isNotWall = 0,
	isWall 


}selectionTileType;
typedef enum {
	none = 0,
	plant, // 32x32 size
	boulder, // 24x24 size
	electric_toggle


}specialTileType;
typedef struct {
	tilesetType tileset;
	int* nbOfTiles	;
	int isWall[200];
} tileSet;
typedef struct {
	int texture;
	int tileNumber;
	specialTileType selectedSpecialTiles;
} tileOf;

void initmap();
void initTileset();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f* _vitesse);
void changeTileset(tilesetType tileType);
void saveMap(const char* filename);
void loadMap(const char* filename);
void createMap();
sfIntRect giveSpriteTextureDim(sfIntRect tile, int tileNumber);
void updateTilesetPanel(sfRenderWindow* _window);
void updateTileSelectionPanel(sfRenderWindow* _window, sfView* viewTileSelection);
tileSet* getCurrentTileset(tilesetType type);
void changeSpecialTiles(specialTileType specialTile);
