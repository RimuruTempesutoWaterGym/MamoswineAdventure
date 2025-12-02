
#include "tools.h"

void initplayer();
void updatePlayer(sfRenderWindow* _window);
void displayPlayer(sfRenderWindow* _window);
sfFloatRect getMamoswineHitboxByPos(sfFloatRect _mamoswinePos);
sfFloatRect getCollisionOfPlayer();
void setPlayerPosition(sfVector2f newPos);