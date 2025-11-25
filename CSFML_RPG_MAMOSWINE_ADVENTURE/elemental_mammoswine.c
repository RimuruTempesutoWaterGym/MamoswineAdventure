#include"elemental_mammoswine.h"


sfSprite* mammoswineFire;
sfSprite* mammoswineWater;
sfSprite* mammoswineGrass;
sfSprite* mammoswineElectric;
sfTexture* textureMammoswineFire;
sfTexture* textureMammoswineWater;
sfTexture* textureMammoswinGrasse;
sfTexture* textureMammoswineElec;
sfIntRect mammoswineRect = {1220, 450};
sfVector2f mammoswineSize = { 50, 50 };
sfVector2f mammoswineFirePos = { 1250, 450 };
sfVector2f mammoswineWaterPos = { 1190, 350 };
sfVector2f mammoswineGrassPos = { 1250, 260 };
sfVector2f mammoswineElectricPos = { 1190,460 };

float isGaseredFire = 0;
float isGaseredWater = 0;
float isGaseredGrass = 0;
float isGaseredElec = 0;


void initElementalMammoswine()
{
	mammoswineFire = sfSprite_create();
	mammoswineWater = sfSprite_create();
	mammoswineGrass = sfSprite_create();
	mammoswineElectric = sfSprite_create();
	textureMammoswineFire = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	textureMammoswineWater = sfTexture_createFromFile(TEXTURE_PATH"ToucheD.png", NULL);
	textureMammoswinGrasse = sfTexture_createFromFile(TEXTURE_PATH"settings.png", NULL);
	textureMammoswineElec = sfTexture_createFromFile(TEXTURE_PATH"boulder.png", NULL);
	sfSprite_setTexture(mammoswineFire, textureMammoswineFire, sfTrue);
	sfSprite_setTexture(mammoswineWater, textureMammoswineWater, sfTrue);
	sfSprite_setTexture(mammoswineGrass, textureMammoswinGrasse, sfTrue);
	sfSprite_setTexture(mammoswineElectric, textureMammoswineElec, sfTrue);
	sfSprite_setPosition(mammoswineFire, mammoswineFirePos);
	sfSprite_setPosition(mammoswineWater, mammoswineWaterPos);
	sfSprite_setPosition(mammoswineGrass, mammoswineGrassPos);
	sfSprite_setPosition(mammoswineElectric, mammoswineElectricPos);
}

void updateElementalMammoswine()
{

}

sfBool displayElementalMammoswine(sfWindow* _window, sfVector2f playerPos)
{
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
	}
	return isGasered;
}
