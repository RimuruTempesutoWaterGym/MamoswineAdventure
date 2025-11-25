#include"elemental_mammoswine.h"


sfSprite* mammoswineFire;
sfSprite* mammoswineWater;
sfSprite* mammoswineGrass;
sfSprite* mammoswineElectric;
sfTexture* textureMammoswineFire;
sfTexture* textureMammoswineWater;
sfTexture* textureMammoswinGrasse;
sfTexture* textureMammoswineElec;
sfIntRect mammoswineRect = {0,0,48,48};
sfVector2f mammoswineFirePos = { 1000, 700 };
sfVector2f mammoswineWaterPos = { 1100, 700 };
sfVector2f mammoswineGrassPos = { 900, 700 };
sfVector2f mammoswineElectricPos = { 1190,460 };
char mamoswineElementalCount;



void initElementalMammoswine()
{
	
	loadMamowsineData("data/keydata.bin");
	mammoswineFire = sfSprite_create();
	mammoswineWater = sfSprite_create();
	mammoswineGrass = sfSprite_create();
	mammoswineElectric = sfSprite_create();
	textureMammoswineFire = sfTexture_createFromFile(TEXTURE_PATH"mamoswine.png", NULL);
	textureMammoswineWater = sfTexture_createFromFile(TEXTURE_PATH"mamoswine.png", NULL);
	textureMammoswinGrasse = sfTexture_createFromFile(TEXTURE_PATH"mamoswine.png", NULL);
	textureMammoswineElec = sfTexture_createFromFile(TEXTURE_PATH"mamoswine.png", NULL);
	sfSprite_setTexture(mammoswineFire, textureMammoswineFire, sfTrue);
	sfSprite_setTexture(mammoswineWater, textureMammoswineWater, sfTrue);
	sfSprite_setTexture(mammoswineGrass, textureMammoswinGrasse, sfTrue);
	sfSprite_setTexture(mammoswineElectric, textureMammoswineElec, sfTrue);
	sfSprite_setTextureRect(mammoswineFire, mammoswineRect);
	sfSprite_setTextureRect(mammoswineWater, mammoswineRect);
	sfSprite_setTextureRect(mammoswineGrass, mammoswineRect);
	sfSprite_setTextureRect(mammoswineElectric, mammoswineRect);
	sfSprite_setPosition(mammoswineFire, mammoswineFirePos);
	sfSprite_setPosition(mammoswineWater, mammoswineWaterPos);
	sfSprite_setPosition(mammoswineGrass, mammoswineGrassPos);
	sfSprite_setPosition(mammoswineElectric, mammoswineElectricPos);
}

void updateElementalMammoswine()
{
	saveMamowsineData("data/keydata.bin");
}
void SetMamoswineFire(sfRenderWindow* _window, sfFloatRect playerPos)
{
	sfFloatRect mammoswinefRectFire = sfSprite_getGlobalBounds(mammoswineFire);
	if (isInsidePlayer(playerPos, mammoswinefRectFire))
	{
		mamoswineElementalCount |= mamoswineFire;
		printf("%d", (mamoswineElementalCount & mamoswineFire) >> MAMOSWINE_FIRE);
	}
}
void SetMamoswineWater(sfRenderWindow* _window, sfFloatRect playerPos)
{
	sfFloatRect mammoswinefRectWater = sfSprite_getGlobalBounds(mammoswineWater);
	if (isInsidePlayer(playerPos, mammoswinefRectWater))
	{
		mamoswineElementalCount |= mamoswineWater;
		printf("%d", (mamoswineElementalCount & mamoswineWater) >> MAMOSWINE_WATER);
	}
}
void SetMamoswineGrass(sfRenderWindow* _window, sfFloatRect playerPos)
{

	sfFloatRect mammoswinefRectGrass = sfSprite_getGlobalBounds(mammoswineGrass);
	if (isInsidePlayer(playerPos, mammoswinefRectGrass))
	{
		mamoswineElementalCount |= mamoswineGrass;
		printf("%d", (mamoswineElementalCount & mamoswineGrass) >> MAMOSWINE_GRASS);
	}
}
void SetMamoswineElectric(sfRenderWindow* _window, sfFloatRect playerPos)
{

	sfFloatRect mammoswinefRectElec = sfSprite_getGlobalBounds(mammoswineElectric);


	if (isInsidePlayer(playerPos, mammoswinefRectElec))
	{
		mamoswineElementalCount |= mamoswineElectric;
		printf("%d", (mamoswineElementalCount & mamoswineElectric) >> MAMOSWINE_ELECTRIC);
		printf("%d", mamoswineElementalCount);

	}
}
void SetAllMamoswine(sfRenderWindow* _window, sfFloatRect playerPos)
{
	SetMamoswineFire(_window, playerPos);
	SetMamoswineWater(_window, playerPos);
	SetMamoswineGrass(_window, playerPos);
	SetMamoswineElectric(_window, playerPos);

}
void displayElementalMammoswine(sfRenderWindow* _window)
{
<<<<<<< HEAD
	sfBool isGasered = sfTrue;
	sfFloatRect mammoswinefRectFire = sfSprite_getGlobalBounds(mammoswineFire);
	sfFloatRect mammoswinefRectWater = sfSprite_getGlobalBounds(mammoswineWater);
	sfFloatRect mammoswinefRectGrass = sfSprite_getGlobalBounds(mammoswineGrass);
	sfFloatRect mammoswinefRectElec = sfSprite_getGlobalBounds(mammoswineElectric);
	if (isInside(playerPos, mammoswinefRectFire) || isGaseredFire)
	{
		isGaseredFire = 1;
	}
	else
	{
		sfRenderWindow_drawSprite(_window, mammoswineFire, NULL);
	}
	if (isInside(playerPos, mammoswinefRectWater) || isGaseredWater)
	{
		isGaseredWater = 1;
	}
	else
	{
		sfRenderWindow_drawSprite(_window, mammoswineWater, NULL);
	}
	if (isInside(playerPos, mammoswinefRectGrass) || isGaseredGrass)
	{
		isGaseredGrass = 1;
	}
	else
	{
		sfRenderWindow_drawSprite(_window, mammoswineGrass, NULL);
	}
	if (isInside(playerPos, mammoswinefRectElec) || isGaseredElec)
	{
		isGaseredElec = 1;
	}
	else
	{
		sfRenderWindow_drawSprite(_window, mammoswineElectric, NULL);
	}
	if (isGaseredFire && isGaseredWater && isGaseredGrass && isGaseredElec)
	{
		return sfFalse;
=======
	if (state == GAME)
	{
		sfRenderWindow_drawSprite(_window, mammoswineFire, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineGrass, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineWater, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineElectric, NULL);
>>>>>>> main
	}
	}
int GetMamoswineElementalCount()
{

	return mamoswineElementalCount ;
}
void saveMamowsineData(const char* filename)
{

	FILE* file = fopen(filename, "wb");
	if (file == NULL)
	{
		printf("Erreur: Impossible de créer le fichier %s\n", filename);
		return;
	}


	fwrite(&mamoswineElementalCount, sizeof(char), 1, file);
	fclose(file);

}
void loadMamowsineData(const char* filename)
{
	FILE* file = fopen(filename, "rb");

	if (file == NULL)
	{
		printf("Aucune sauvegarde trouvée. Création de %s...\n", filename);
		saveMamowsineData(filename);
		return;
	}
	fread(&mamoswineElementalCount, sizeof(char), 1, file);

	fclose(file);

	printf("Map chargée depuis %s\n", filename);
}