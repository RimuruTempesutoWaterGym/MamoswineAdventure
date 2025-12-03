#include"tools.h"
#include"player.h"
#include"elemental_mammoswine.h"


sfSprite* mammoswineFire;
sfSprite* mammoswineWater;
sfSprite* mammoswineGrass;
sfSprite* mammoswineElectric;
sfSprite* mamoDialga;
sfTexture* textureMammoswineFire;
sfTexture* textureMammoswineWater;
sfTexture* textureMammoswinGrasse;
sfTexture* textureMammoswineElec;
sfTexture* textureMamoDialga;
sfIntRect mammoswineFireRect = { 49,0,48,48};
sfIntRect mammoswineWaterRect = { 49,0,48,48};
sfIntRect mammoswineGrassRect = { 49,0,48,48};
sfIntRect mammoswineElectricRect = { 49,0,48,48};
sfIntRect mammoswineRectDialga = {0,0,57,66};
sfVector2f mammoswineFirePos = { 1000, 900 };
sfVector2f mammoswineWaterPos = { 1100, 700 };
sfVector2f mammoswineGrassPos = { 900, 900 };
sfVector2f mammoswineElectricPos = { 1190,460 };
sfVector2f mamoDialgaPos = { 1180, 100 };
char mamoswineElementalCount;



void initElementalMamoswine()
{
	
	loadMamowsineData("data/keydata.bin");
	mammoswineFire = sfSprite_create();
	mammoswineWater = sfSprite_create();
	mammoswineGrass = sfSprite_create();
	mammoswineElectric = sfSprite_create();
	mamoDialga = sfSprite_create();
	textureMammoswineFire = sfTexture_createFromFile(TEXTURE_PATH"mamofeu.png", NULL);
	textureMammoswineWater = sfTexture_createFromFile(TEXTURE_PATH"mamoeau.png", NULL);
	textureMammoswinGrasse = sfTexture_createFromFile(TEXTURE_PATH"mamoplante.png", NULL);
	textureMammoswineElec = sfTexture_createFromFile(TEXTURE_PATH"mamoelec.png", NULL);
	textureMamoDialga = sfTexture_createFromFile(TEXTURE_PATH"mamoDialga.png", NULL);
	sfSprite_setTexture(mammoswineFire, textureMammoswineFire, sfTrue);
	sfSprite_setTexture(mammoswineWater, textureMammoswineWater, sfTrue);
	sfSprite_setTexture(mammoswineGrass, textureMammoswinGrasse, sfTrue);
	sfSprite_setTexture(mammoswineElectric, textureMammoswineElec, sfTrue);
	sfSprite_setTexture(mamoDialga, textureMamoDialga, sfTrue);
	sfSprite_setTextureRect(mammoswineFire, mammoswineFireRect);
	sfSprite_setTextureRect(mammoswineWater, mammoswineWaterRect);
	sfSprite_setTextureRect(mammoswineGrass, mammoswineGrassRect);
	sfSprite_setTextureRect(mammoswineElectric, mammoswineElectricRect);
	sfSprite_setTextureRect(mamoDialga, mammoswineRectDialga);
	sfSprite_setPosition(mammoswineFire, mammoswineFirePos);
	sfSprite_setPosition(mammoswineWater, mammoswineWaterPos);
	sfSprite_setPosition(mammoswineGrass, mammoswineGrassPos);
	sfSprite_setPosition(mammoswineElectric, mammoswineElectricPos);
	sfSprite_setPosition(mamoDialga, mamoDialgaPos);
}

void updateElementalMamoswine()
{
	saveMamowsineData("data/keydata.bin");
}
void updateMamoDialga()
{

}
sfFloatRect GetCollisionMamoswineFire()
{
	return sfSprite_getGlobalBounds(mammoswineFire);
}
sfFloatRect GetCollisionMamoswineDialga()
{
	return sfSprite_getGlobalBounds(mamoDialga);
}
sfFloatRect GetRangeMamoswineDialga()
{
	sfFloatRect rangeMamoswineDialga = sfSprite_getGlobalBounds(mamoDialga);
	printf("%f", rangeMamoswineDialga.left);
	printf("%f", rangeMamoswineDialga.top);
	printf("%f", rangeMamoswineDialga.height);
	printf("%f", rangeMamoswineDialga.width);
	rangeMamoswineDialga.left -= 20;
		rangeMamoswineDialga.top -= 30;
		rangeMamoswineDialga.height += 60;
		rangeMamoswineDialga.width += 40;
	return rangeMamoswineDialga;
}
sfFloatRect GetCollisionMamoswineGrass()
{
	return sfSprite_getGlobalBounds(mammoswineGrass);
}
sfFloatRect GetCollisionMamoswineElectric()
{
	return sfSprite_getGlobalBounds(mammoswineElectric);
}
sfFloatRect GetCollisionMamoswineWater()
{
	return sfSprite_getGlobalBounds(mammoswineWater);
}
void SetMamoswineFire(sfRenderWindow* _window, sfFloatRect playerPos)
{
	
	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineFire()) && (GetMamoswineFireElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		
		if (startBattle(&mamoswineBat, &mamoswineFireBat))
		{
			mamoswineElementalCount |= mamoswineFire;

		}
		else
		{

			SetPosAtRespawn();
		}
	}
}
void SetMamoswineDialga(sfRenderWindow* _window, sfFloatRect playerPos)
{

	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetRangeMamoswineDialga()))
	{
		if (startBattle(&mamoswineBat, &mamoswineDialgaBat))
		{


		}
		else
		{

			SetPosAtRespawn();
		}

	}
}
void SetMamoswineWater(sfRenderWindow* _window, sfFloatRect playerPos)
{
	
	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineWater()) && (GetMamoswineWaterElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		if (startBattle(&mamoswineBat, &mamoswineWaterBat))
		{
			mamoswineElementalCount |= mamoswineWater;

		}
		else
		{

			SetPosAtRespawn();
		}
	
	
	}
}
void SetMamoswineGrass(sfRenderWindow* _window, sfFloatRect playerPos)
{


	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineGrass())&& (GetMamoswineGrassElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{

		if (startBattle(&mamoswineBat, &mamoswineGrassBat)) 
		{
		
			mamoswineElementalCount |= mamoswineGrass;
		}
		else
		{
		
			SetPosAtRespawn();
		}
	}
}
void SetMamoswineElectric(sfRenderWindow* _window, sfFloatRect playerPos)
{


	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineElectric()) && (GetMamoswineElectricElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		if (startBattle(&mamoswineBat, &mamoswineElectricBat))
		{
			mamoswineElementalCount |= mamoswineElectric;

		}
		else
		{

			SetPosAtRespawn();
		}

		


	}
}
void SetAllMamoswine(sfRenderWindow* _window, sfFloatRect playerPos)
{
	SetMamoswineFire(_window, playerPos);
	SetMamoswineWater(_window, playerPos);
	SetMamoswineGrass(_window, playerPos);
	SetMamoswineElectric(_window, playerPos);

}
void displayElementalMamoswine(sfRenderWindow* _window)
{
	if (state == GAME || state == EDITOR)
	{

		sfRenderWindow_drawSprite(_window, mammoswineFire, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineGrass, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineWater, NULL);
		sfRenderWindow_drawSprite(_window, mammoswineElectric, NULL);
	}
	}
void displayMamoDialga(sfRenderWindow* _window)
{
	if (state == GAME || state == EDITOR)
	{

		sfRenderWindow_drawSprite(_window, mamoDialga, NULL);
	}
	}
int GetMamoswineElementalCount()
{

	return mamoswineElementalCount ;
}
int GetMamoswineGrassElementalCount()
{

	return (mamoswineElementalCount & mamoswineGrass) >> MAMOSWINE_GRASS;
}
int GetMamoswineFireElementalCount()
{

	return (mamoswineElementalCount & mamoswineFire) >> MAMOSWINE_FIRE;
}
int GetMamoswineElectricElementalCount()
{

	return (mamoswineElementalCount & mamoswineElectric) >> MAMOSWINE_ELECTRIC;
}
int GetMamoswineWaterElementalCount()
{

	return (mamoswineElementalCount & mamoswineWater) >> MAMOSWINE_WATER;
}
void SetMamoswineElementalCountToPlusOne()
{

	mamoswineElementalCount++;
}
void saveMamowsineData(const char* filename)
{

	FILE* file = fopen(filename, "wb");
	if (file == NULL)
	{
		printf("Erreur: Impossible de cr�er le fichier %s\n", filename);
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
		printf("Aucune sauvegarde trouv�e. Cr�ation de %s...\n", filename);
		saveMamowsineData(filename);
		return;
	}
	fread(&mamoswineElementalCount, sizeof(char), 1, file);

	fclose(file);

	printf("Map charg�e depuis %s\n", filename);
}
void setMamoswineFirePosition(sfVector2f newPos,int frame) {
	mammoswineFirePos = newPos;
	mammoswineFireRect.top = frame * (mammoswineFireRect.height+1);
	sfSprite_setPosition(mammoswineFire, mammoswineFirePos);
	sfSprite_setTextureRect(mammoswineFire, mammoswineFireRect);
}

void setMamoswineWaterPosition(sfVector2f newPos, int frame) {
	mammoswineWaterPos = newPos;
	mammoswineWaterRect.top = frame * (mammoswineWaterRect.height +1);
	sfSprite_setPosition(mammoswineWater, mammoswineWaterPos);
	sfSprite_setTextureRect(mammoswineWater, mammoswineWaterRect);
}
void setMamoswineDialgaPosition(sfVector2f newPos) {
	mamoDialgaPos = newPos;
	sfSprite_setPosition(mamoDialga, mamoDialgaPos);

}

void setMamoswineGrassPosition(sfVector2f newPos, int frame) {
	mammoswineGrassPos = newPos;
	mammoswineGrassRect.top = frame  * (mammoswineGrassRect.height+1) ;
	sfSprite_setPosition(mammoswineGrass, mammoswineGrassPos);
	sfSprite_setTextureRect(mammoswineGrass, mammoswineGrassRect);
}

void setMamoswineElectricPosition(sfVector2f newPos, int frame) {
	mammoswineElectricPos = newPos;
	mammoswineElectricRect.top = frame * (mammoswineElectricRect.height+1);
	sfSprite_setPosition(mammoswineElectric, mammoswineElectricPos);
	sfSprite_setTextureRect(mammoswineElectric, mammoswineElectricRect);

}