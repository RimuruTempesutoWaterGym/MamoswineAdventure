
#include "tools.h"




void initmap();
void updateMap(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
sfBool collisionMapPlayer(sfFloatRect _sprite, Direction _direction, sfVector2f* _vitesse);