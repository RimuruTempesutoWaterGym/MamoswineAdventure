#include "view.h"


sfView* viewEdit;
sfView* viewPlayer;
sfView* viewEditUi;
sfView* viewTileSelection;
sfVector2f posViewEdit = { 400.0f,300.0f };
sfVector2f posViewPlayer = { 400.0f,300.0f };
sfVector2f viewEditSize = { 800,600 };
sfVector2f viewPlayerSize = { 400,300.0f };
sfVector2f viewEditUISize = { TILE_WIDTH + 10.f , 600.f };
sfVector2f viewTileSelectionSize = { 110.f, 600.f };
sfVector2f velocityViewEdit = { 300.f,300.f };
sfVector2f posViewEditUi;
sfVector2f posViewTileSelection;
void initView()
{
	posViewEditUi.x = viewEditUISize.x / 2;
	posViewEditUi.y = viewEditUISize.y / 2;
		
	posViewTileSelection.x = viewTileSelectionSize.x / 2; 
	posViewTileSelection.y = viewTileSelectionSize.y / 2;

viewEdit = sfView_create();
viewPlayer = sfView_create();
viewEditUi = sfView_create();
viewTileSelection = sfView_create();

 sfView_setSize(viewEdit, viewEditSize);
 sfView_setSize(viewPlayer, viewPlayerSize);
 sfView_setSize(viewEditUi, viewEditUISize);
 sfView_setSize(viewTileSelection, viewTileSelectionSize);
 sfView_setCenter(viewEditUi, posViewEditUi);
 sfView_setCenter(viewTileSelection, posViewTileSelection);
 float viewportWidth = (TILE_WIDTH + 10.f) / 800.0f;  
 sfFloatRect uiViewport = { 0.0f, 0.0f, viewportWidth, 1.0f };  
 sfView_setViewport(viewEditUi, uiViewport);
 float rightViewportWidth = viewTileSelectionSize.x / 800.0f;
 sfFloatRect tileSelectionViewport = { 1.0f - rightViewportWidth, 0.0f, rightViewportWidth, 1.0f };
 sfView_setViewport(viewTileSelection, tileSelectionViewport);

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



void displayView(sfRenderWindow* _window)
{

	
	if (state == EDITOR)
	{

		sfRenderWindow_setView(_window, viewEdit);
		displayMap(_window);
		updateMap(_window);  

		
		sfRenderWindow_setView(_window, viewEditUi);
		updateTilesetPanel(_window);

		sfRenderWindow_setView(_window, viewTileSelection);
		updateTileSelectionPanel(_window, viewTileSelection);
	}

	if (state == GAME)
	{
		sfRenderWindow_setView(_window, viewPlayer);
		displayMap(_window);
		updateMap(_window);
	}
	
}
void displayMinimap(sfRenderWindow* _window)
{

	//if (state == GAME)
	//{

	//	sfView_reset(minimap, visibleArea);
	//	sfView_setViewport(minimap, minimapSpot);
	//	sfRenderWindow_setView(_window, minimap);
	//	displayMap(_window);
	//	updateMap(_window);
	//}
	



}
sfVector2f updatePixelToWorld(sfRenderWindow* _window)
{
	sfVector2i pixelPos = sfMouse_getPositionRenderWindow(_window);
	return sfRenderWindow_mapPixelToCoords(_window, pixelPos, viewEdit);
}
sfView* getCurrentView(sfRenderWindow* _window)
{
	return sfRenderWindow_getView(_window);
}
