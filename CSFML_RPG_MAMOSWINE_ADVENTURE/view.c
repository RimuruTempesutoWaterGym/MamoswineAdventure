#include "view.h"


sfView* viewEdit;
sfView* viewPlayer;


sfVector2f posViewEdit = { 400.0f,300.0f };
sfVector2f posViewPlayer = { 400.0f,300.0f };
sfVector2f viewEditSize = { 800,600.0f };
sfVector2f viewPlayerSize = { 400,300.0f };
sfVector2f velocityViewEdit = { 300.f,300.f };

void initView()
{
viewEdit = sfView_create();
viewPlayer = sfView_create();
 sfView_setSize(viewEdit, viewEditSize);
 sfView_setSize(viewPlayer, viewPlayerSize);
}


void updateView(sfVector2f playerPos, sfIntRect playerHitbox,sfRenderWindow* _window)
{

	if (state == GAME)
	{
		if (playerPos.x >= (MAP_WIDTH * TILE_WIDTH) - (viewPlayerSize.x / 2 * 1.10))
	{
			posViewPlayer.x = (MAP_WIDTH * TILE_WIDTH) - (viewPlayerSize.x / 2);
		}
		else if (playerPos.x < (viewPlayerSize.x / 2*0.91)) {
			posViewPlayer.x = viewPlayerSize.x / 2;
		}
		else {
			posViewPlayer.x = playerPos.x + playerHitbox.width / 2;
		}
		if (playerPos.y >= (MAP_HEIGHT * TILE_HEIGHT) - (viewPlayerSize.y / 2 * 1.20))
		{
			posViewPlayer.y = (MAP_HEIGHT * TILE_HEIGHT) - (viewPlayerSize.y / 2);
		}
		else if (playerPos.y < (viewPlayerSize.y / 2 *0.80)) {
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

		if (sfKeyboard_isKeyPressed(sfKeyDown)) {
			posViewEdit.y += velocityViewEdit.y * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyUp)) {


			posViewEdit.y -= velocityViewEdit.y * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyRight))
		{

			posViewEdit.x += velocityViewEdit.x * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyLeft))
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