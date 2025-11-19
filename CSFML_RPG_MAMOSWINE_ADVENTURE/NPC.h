#include"tools.h"


void initNPC();
void initTextBox();
void updateTextBox();
void displayNPC(sfRenderWindow* _window);
void displayTextBox(sfRenderWindow* _window, sfVector2f playerPos, sfIntRect playerHitbox);
sfBool collisionNPC(sfVector2f _playerPos);