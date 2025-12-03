#include "view.h"

sfView* minimap;
sfView* viewEdit;
sfView* viewPlayer;
sfView* viewEditUi;
sfView* viewDefault;
sfView* viewTileSelection;
sfView* viewHUD;
sfView* viewBattle;
sfVector2f viewBattleSize = { 800.0f, 600.0f };
sfVector2f posViewBattle = { 400.0f, 300.0f };
sfVector2f posViewEdit = { 400.0f,300.0f };
sfVector2f posViewDefault = { 400.0f,300.0f };
sfVector2f posViewPlayer = { 400.0f,300.0f };
sfVector2f viewEditSize = { 800,600 };
sfVector2f viewPlayerSize = { 400,300.0f };
sfVector2f viewHUDSize = { 250.0f,200.0f };
sfVector2f viewDefaultSize = { 800.f,600.0f };
sfVector2f viewMinimap = { MAP_WIDTH * TILE_WIDTH+800, MAP_HEIGHT * TILE_HEIGHT + 200 };
sfVector2f viewEditUISize = { TILE_WIDTH + 10.f , 600.f };
sfVector2f viewTileSelectionSize = { 110.f, 600.f };
sfVector2f velocityViewEdit = { 300.f,300.f };
sfVector2f posViewEditUi;
sfVector2f posViewTileSelection;
sfVector2f posViewHUD;
sfFloatRect minimapSpot = {
0.77f,0.05f,0.25f,0.30f };
sfFloatRect visibleArea = {
	0.f,0.f,MAP_WIDTH* TILE_WIDTH ,MAP_HEIGHT* TILE_HEIGHT 
};
void initView()
{
	 minimap = sfView_create();

 sfView_setSize(minimap, viewMinimap);
 sfView_setCenter(minimap, (sfVector2f) {
	 viewMinimap.y / 2, viewMinimap.x / 2
 });

	posViewEditUi.x = viewEditUISize.x / 2;
	posViewEditUi.y = viewEditUISize.y / 2;
	posViewHUD.x = viewHUDSize.x / 2;
	posViewHUD.y = viewHUDSize.y / 2;
		
	posViewTileSelection.x = viewTileSelectionSize.x / 2; 
	posViewTileSelection.y = viewTileSelectionSize.y / 2;

viewEdit = sfView_create();
viewPlayer = sfView_create();
viewEditUi = sfView_create();
viewDefault = sfView_create();
viewTileSelection = sfView_create();
viewHUD = sfView_create();
viewBattle = sfView_create();


sfView_setSize(viewBattle, viewBattleSize);
 sfView_setSize(viewEdit, viewEditSize);
 sfView_setSize(viewPlayer, viewPlayerSize);
 sfView_setSize(viewEditUi, viewEditUISize);
 sfView_setSize(viewDefault, viewDefaultSize);
 sfView_setSize(viewTileSelection, viewTileSelectionSize);
 sfView_setSize(viewHUD, viewHUDSize);
 sfView_setCenter(viewBattle, posViewBattle);
 sfView_setCenter(viewEditUi, posViewEditUi);
 sfView_setCenter(viewHUD, posViewHUD);
 sfView_setCenter(viewDefault, posViewDefault);
 sfView_setCenter(viewTileSelection, posViewTileSelection);
 float EditUiviewportWidth = (TILE_WIDTH + 10.f) / 800.0f;  
 sfFloatRect uiViewport = { 0.0f, 0.0f, EditUiviewportWidth, 1.0f };
 sfView_setViewport(viewEditUi, uiViewport);
 float tileSelectionViewportWidth = viewTileSelectionSize.x / 800.0f;
 sfFloatRect tileSelectionViewport = { 1.0f - tileSelectionViewportWidth, 0.0f, tileSelectionViewportWidth, 1.0f };
 float HUDViewportHeight = viewHUDSize.y / 800.0f;

 sfFloatRect HUDViewport = { 0.f , 1.0f - HUDViewportHeight,1.f , HUDViewportHeight };
 sfFloatRect DefaultViewport = { 0.f , 0.0f ,1.f ,1.f };
 sfView_setViewport(viewTileSelection, tileSelectionViewport);
 sfView_setViewport(viewDefault, DefaultViewport);
 sfView_setViewport(viewHUD, HUDViewport);

}


void updateView(sfVector2f playerPos, sfIntRect playerHitbox,sfRenderWindow* _window)
{

	if (state == GAME)
	{
		if (playerPos.x + (playerHitbox.width / 2) >= (MAP_WIDTH * TILE_WIDTH) - (viewPlayerSize.x / 2 ))
	{
			posViewPlayer.x = (MAP_WIDTH * TILE_WIDTH) - (viewPlayerSize.x / 2);
		}
		else if (playerPos.x + (playerHitbox.width / 2) < (viewPlayerSize.x / 2)) {
			posViewPlayer.x = viewPlayerSize.x / 2;
		}
		else {
			posViewPlayer.x = playerPos.x + playerHitbox.width / 2;
		}
		if (playerPos.y + (playerHitbox.height / 2) > (MAP_HEIGHT * TILE_HEIGHT) - (viewPlayerSize.y / 2))
		{
			posViewPlayer.y = (MAP_HEIGHT * TILE_HEIGHT) - (viewPlayerSize.y / 2);
		}
		else if (playerPos.y+ (playerHitbox.height/2) < +(viewPlayerSize.y / 2)) {
			posViewPlayer.y = viewPlayerSize.y / 2;
		}
		else {
			posViewPlayer.y = playerPos.y + playerHitbox.height / 2;
		}

		sfView_setCenter(viewPlayer, posViewPlayer);
		
		sfView_setSize(viewPlayer, viewPlayerSize);
		
	
	}


}

void updateViewEditor(sfRenderWindow* _window)
{

	if (state == EDITOR)
	{
	
		if (sfKeyboard_isKeyPressed(sfKeyDown) && posViewEdit.y < (MAP_HEIGHT * TILE_HEIGHT) - (viewEditSize.y /2) ) {
			posViewEdit.y += velocityViewEdit.y * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyUp) && posViewEdit.y > 0 + (viewEditSize.y / 2)) {


			posViewEdit.y -= velocityViewEdit.y * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyRight) && posViewEdit.x < (MAP_WIDTH * TILE_WIDTH) - (viewEditSize.x / 2) + 200 /*le + 200 a retirer quand on peut bigmac le tileEditor*/)
		{

			posViewEdit.x += velocityViewEdit.x * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyLeft) && posViewEdit.x > 0 + (viewEditSize.x / 2) - 200 /*le - 200 a retirer quand on peut bigmac le tileEditor*/)
		{
			posViewEdit.x -= velocityViewEdit.x * GetDeltaTime();

		}

	}
	
		sfView_setCenter(viewEdit, posViewEdit);

		sfView_setSize(viewEdit, viewEditSize);


	}
void displayViewEdit(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewEdit);
	
}
void displayViewEditUi(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewEditUi);
	updateTilesetPanel(_window, viewEditUi);
}
void displayViewTileSelection(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewTileSelection);
	updateTileSelectionPanel(_window, viewTileSelection);
}
void displayViewPlayer(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewPlayer);
}
void displayViewDefault(sfRenderWindow* _window)
{
	

	sfRenderWindow_setView(_window, viewDefault);
}
void displayHUD(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewHUD);
}
void displayMinimap(sfRenderWindow* _window)
{

	if (state == GAME)
	{


		sfView_setViewport(minimap, minimapSpot);
		sfRenderWindow_setView(_window, minimap);
		displayMap(_window);
		updateMap(_window);
	}
	



}
void displayBattleView(sfRenderWindow* _window)
{
	sfRenderWindow_setView(_window, viewBattle);
}
sfVector2f updatePixelToWorld(sfRenderWindow* _window, sfView* _view)
{
	if (_view == NULL)
	{
		sfVector2i pixelPos = sfMouse_getPositionRenderWindow(_window);
		return sfRenderWindow_mapPixelToCoords(_window, pixelPos, viewEdit);
	}
	else
	{
	sfVector2i pixelPos = sfMouse_getPositionRenderWindow(_window);
	return sfRenderWindow_mapPixelToCoords(_window, pixelPos, _view);
	}
}
sfView* getCurrentView(sfRenderWindow* _window)
{
	return sfRenderWindow_getView(_window);
}

