#include"tools.h"
#include "menu.h"

void initNPC();
void initTextBox();
void updateTextBox();
void displayNPC(sfRenderWindow* _window);
void displayTextBox(sfRenderWindow* _window);
void collisionNPC();
sfFloatRect GetCollisionOfNPC();
void setNPCPosition(sfVector2f newPos);