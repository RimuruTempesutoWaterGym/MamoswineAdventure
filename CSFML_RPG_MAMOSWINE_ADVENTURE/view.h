#include "tools.h"
void initView();
void updateView(sfVector2f playerPos, sfIntRect playerHitbox, sfRenderWindow* _window);
void updateEditorView(sfVector2f playerPos, sfIntRect playerHitbox, sfRenderWindow* _window);
void displayViewEdit(sfRenderWindow* _window);
void displayViewEditUi(sfRenderWindow* _window);
void displayViewTileSelection(sfRenderWindow* _window);
void displayViewPlayer(sfRenderWindow* _window);
void displayViewDefault(sfRenderWindow* _window) ;
sfVector2f updatePixelToWorld(sfRenderWindow* _window, sfView* _view);
sfView* getCurrentView(sfRenderWindow* _window);