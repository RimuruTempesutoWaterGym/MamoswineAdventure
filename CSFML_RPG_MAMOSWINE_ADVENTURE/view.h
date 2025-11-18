#include "tools.h"
void initView();
void updateView(sfVector2f playerPos, sfIntRect playerHitbox, sfRenderWindow* _window);
void updateEditorView(sfVector2f playerPos, sfIntRect playerHitbox, sfRenderWindow* _window);
void displayView(sfRenderWindow* _window);
sfVector2f updatePixelToWorld(sfRenderWindow* _window);