#include "tools.h"
sfTime sftime;
sfClock* sfclock;



void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

void restartClock()
{
	sftime = sfClock_restart(sfclock);
}

float GetDeltaTime()
{
	return sfTime_asSeconds(sftime);
}


// Fonction pour gérer si la souris passe sur un élément ayant une hitbox pour position en float et retourner une valeur
int isInsideMouse(sfVector2f item, sfFloatRect obstacle)
{
	if (item.x > obstacle.left &&
		item.x < (obstacle.width + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height))
	{
	
		return 1;

	}
	return 0;
}

// Fonction pour gérer si la souris passe sur un élément ayant une hitbox pour position en int et retourner une valeur
int isInsideMousei(sfVector2i item, sfFloatRect obstacle)
{
	if (item.x > obstacle.left &&
		item.x < (obstacle.width + obstacle.left) &&
		item.y > obstacle.top &&
		item.y < (obstacle.top + obstacle.height))
	{
		return 1;
	}
	return 0;
}

// Fonction pour gérer si le joueur passe sur un élément ayant une hitbox pour position en int et retourner une valeur
int isInsidePlayer(sfFloatRect player, sfFloatRect obstacle)
{

		if (player.left > obstacle.left &&
			player.left < (obstacle.width + obstacle.left) &&
			player.top > obstacle.top &&
			player.top < (obstacle.top + obstacle.height) ||
			player.left + player.width > obstacle.left &&
			player.left + player.width < (obstacle.width + obstacle.left) &&
			player.top + player.height > obstacle.top &&
			player.top + player.height < (obstacle.top + obstacle.height) ||
			player.left  > obstacle.left &&
			player.left < (obstacle.width + obstacle.left) &&
			player.top + player.height > obstacle.top &&
			player.top + player.height < (obstacle.top + obstacle.height) ||
			player.left + player.width > obstacle.left &&
			player.left + player.width< (obstacle.width + obstacle.left) &&
			player.top  > obstacle.top &&
			player.top < (obstacle.top + obstacle.height)
			)
		{
			return 1;

		}


	return 0;
}

// fonction pour initialiser tout les inits dans le main et rendre plus propre
// cette fonction est liée à tous les inits de notre code
void initAll()
{
	initTools();
	initMusic();
	initSound();
	initView();
	initplayer();
	initNPC();
	initBattle();
	initDoor();
	initTextBox();
	initmenu();
	initElementalMamoswine();
	initmap();
	updateSpritePositionsFromData();
}

// fonction pour rassembler les updates de dans le main et rendre plus propre
void updateAll(sfRenderWindow* _window)
{
	updatemenu(_window);
	updateViewEditor(_window);
	updatePlayer(_window);
	updateTextBox();
	updateMap(_window);
	updateTextBox();
	updateDoor();
	updateMusic();
	updateBattle(_window);
}

// fonction de display en fonction du state 
void displayAll(sfRenderWindow* _window)
{
	switch (state)
	{
	case EDITOR:
		displayViewEdit(_window);
		displayMap(_window);
		updateMap(_window);
		displayPlayer(_window);
		displayDoor(_window);
		displayElementalMamoswine(_window);
		displayNPC(_window);
		displayMamoDialga(_window);
		displayViewEditUi(_window);
		displayViewTileSelection(_window);	
		break;
	case GAME:
		displayViewPlayer(_window);
		displayMap(_window);
		displayNPC(_window);
		displayElementalMamoswine(_window);		
		displayMamoDialga(_window);
		if (isPlayerOverDoor())
		{
			displayPlayer(_window);
			displayDoor(_window);
		}
		else
		{
			displayDoor(_window);
			displayPlayer(_window);
		}

		displayMinimap(_window);
		displayHUD(_window);
		displayTextBox(_window);

		break;

	case BATTLE: 
		displayBattleView(_window);
		displayBattleUI(_window);
		break;
	default:
		displayMap(_window);
		displayViewDefault(_window);
		displaymenu(_window);
		break;
	}
}