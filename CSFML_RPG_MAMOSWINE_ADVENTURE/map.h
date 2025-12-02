
#include "tools.h"



typedef enum {
	peaceful = 1,
	natural,
	swamp,
	water,
	deepWater,
	thundered,
	fire,
	voiding,

}tilesetType;
typedef enum {
	isNotWall = 0,
	isWall ,


}selectionTileType;
typedef enum {
	none = 0,
	plant, // 32x32 size
	boulder, // 24x24 size
	electric_wall,// 24x24 size
	electric_toggle,// 24x24 size
}specialTileType;

typedef struct {
	tilesetType tileset;
	int* nbOfTiles	;
	int isWall[200];
} tileSet;
typedef struct {
	int state;
	specialTileType SpecialTilesType;
} specialTile;
typedef struct {

	int idActivable;
	int numberOfActivable;
} activable;
typedef struct {
	int texture;
	int tileNumber;
	specialTile selectedSpecialTiles;
	activable isActivable;
	int musicOfTile;
} tileOf;




typedef enum {
	tiles = 1,
	specialTiles,
	electric_toggle_link,
	sprite,

}Tilemode;
typedef enum {
	SPRITE_PLAYER = 0,
	SPRITE_NPC,
	SPRITE_DOOR,
	SPRITE_MAMOSWINE_FIRE,
	SPRITE_MAMOSWINE_WATER,
	SPRITE_MAMOSWINE_GRASS,
	SPRITE_MAMOSWINE_ELECTRIC,
	SPRITE_COUNT
} SpriteType;

typedef struct {
	sfVector2f position;
	SpriteType type;
	sfIntRect bounds; 
} SpriteData;
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
void updateTilesetPanel(sfRenderWindow* _window, sfView* _view);
void updateTileSelectionPanel(sfRenderWindow* _window, sfView* viewTileSelection);
tileSet* getCurrentTileset(tilesetType type);
void changeSpecialTiles(specialTileType specialTile);
void bushCutPlayerMap(sfFloatRect _sprite, Direction _direction );
int checkAllTogglesActivated(int idActivable);;
void updateElectricWalls(int idActivable, int state);;
void ElectricTogglePlayerMap(sfFloatRect _sprite, Direction _direction);
void updateSpritePlacementMode(sfRenderWindow* _window);
void updateSpritePositionsFromData();
sfBool canPlaceSpriteAt(sfVector2f position, sfIntRect spriteBounds);
void saveSpritesData(const char* filename);
void loadSpritesData(const char* filename);
void initSpriteData();