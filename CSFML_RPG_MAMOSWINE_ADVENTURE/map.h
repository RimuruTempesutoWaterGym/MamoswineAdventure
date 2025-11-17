
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
void initmap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f* _vitesse);
void changeTileset(tilesetType tileType);
