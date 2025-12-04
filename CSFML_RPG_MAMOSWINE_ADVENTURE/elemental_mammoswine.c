#include"tools.h"
#include"player.h"
#include"music.h"
#include"elemental_mammoswine.h"

//créer les sprite des mammochons élémentaires
sfSprite* mammoswineFire;
sfSprite* mammoswineWater;
sfSprite* mammoswineGrass;
sfSprite* mammoswineElectric;
sfSprite* mamoDialga;
//créer les textures des mammochons élémentaires
sfTexture* textureMammoswineFire;
sfTexture* textureMammoswineWater;
sfTexture* textureMammoswinGrasse;
sfTexture* textureMammoswineElec;
sfTexture* textureMamoDialga;
//créer et initialiser les rectangles de limitation des mammochons élémentaires
sfIntRect mammoswineFireRect = { 49,0,48,48};
sfIntRect mammoswineWaterRect = { 49,0,48,48};
sfIntRect mammoswineGrassRect = { 49,0,48,48};
sfIntRect mammoswineElectricRect = { 49,0,48,48};
sfIntRect mammoswineRectDialga = {0,0,57,66};
//créer et initialiser les position des mammochons élémentaires
sfVector2f mammoswineFirePos = { 1000, 900 };
sfVector2f mammoswineWaterPos = { 1100, 700 };
sfVector2f mammoswineGrassPos = { 900, 900 };
sfVector2f mammoswineElectricPos = { 1190,460 };
sfVector2f mamoDialgaPos = { 1180, 100 };
//créer une variable qui va stocker en binaire la valeur d'ame de mammochon qu'on a 
char mamoswineElementalCount;


//initialise les valeurs importantes pour les mammochons élémentaires
void initElementalMamoswine()
{
	//Récupère la valeur de MamoswineElementalCount du fichier de sauvegarde
	loadMamowsineData("data/keydata.bin");
	//Initialise les mammochons élementaire
	mammoswineFire = sfSprite_create();
	mammoswineWater = sfSprite_create();
	mammoswineGrass = sfSprite_create();
	mammoswineElectric = sfSprite_create();
	mamoDialga = sfSprite_create();
	//Initialise les textures des mammochons élementaire
	textureMammoswineFire = sfTexture_createFromFile(TEXTURE_PATH"mamofeu.png", NULL);
	textureMammoswineWater = sfTexture_createFromFile(TEXTURE_PATH"mamoeau.png", NULL);
	textureMammoswinGrasse = sfTexture_createFromFile(TEXTURE_PATH"mamoplante.png", NULL);
	textureMammoswineElec = sfTexture_createFromFile(TEXTURE_PATH"mamoelec.png", NULL);
	textureMamoDialga = sfTexture_createFromFile(TEXTURE_PATH"mamoDialga.png", NULL);
	//set les textures et la position des mammochons élementaire sur les sprites
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
// récupère la boite de collision des mammochons
void updateElementalMamoswine()
{
	saveMamowsineData("data/keydata.bin");
}
sfFloatRect GetCollisionMamoswineFire()
{
	return sfSprite_getGlobalBounds(mammoswineFire);
}
sfFloatRect GetCollisionMamoswineDialga()
{
	return sfSprite_getGlobalBounds(mamoDialga);
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
//vérifie si le joueur est a la portée de la porte et que les mammochons n'ont pas été vaincus, puis lance un combat quand on appuie sur E
//si le combat est gagné alors récupère le binaire du bits du mammochon en question,si le combat est loose alors retour au spawn
void SetMamoswineFire(sfRenderWindow* _window, sfFloatRect playerPos)
{
	
	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineFire()) && (GetMamoswineFireElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		startBattle(&mamoswineBat, &mamoswineFireBat, 7);


	}
	if (getBattleResult(&mamoswineFireBat) == 1 && (GetMamoswineFireElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		setHasChangedTo1();
		setMusic(2);
		mamoswineElementalCount |= mamoswineFire;
		sfIntRect mammoswineFireRect = { 0,0,48,48 };
	}

	
}
void SetMamoswineDialga(sfRenderWindow* _window, sfFloatRect playerPos)
{

	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(playerPos, GetCollisionMamoswineDialga()))
	{
		startBattle(&mamoswineBat, &mamoswineDialgaBat, 11);


	}
	if (getBattleResult(&mamoswineDialgaBat) == 1 )
	{
		setMusic(6);
	//	mamoswineElementalCount |= mamoswineWater;
	//	sfIntRect mammoswineDialgaRect = { 0,0,48,48 };
	}



}
void SetMamoswineWater(sfRenderWindow* _window, sfFloatRect playerPos)
{
	
	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineWater()) && (GetMamoswineWaterElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		startBattle(&mamoswineBat, &mamoswineWaterBat, 8);


	}
	if (getBattleResult(&mamoswineWaterBat) == 1 && (GetMamoswineWaterElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		setMusic(3);
		mamoswineElementalCount |= mamoswineWater;
		sfIntRect mammoswineWaterRect = { 0,0,48,48 };
	}

	
	
}
void SetMamoswineGrass(sfRenderWindow* _window, sfFloatRect playerPos)
{


	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineGrass())&& (GetMamoswineGrassElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{

		startBattle(&mamoswineBat, &mamoswineGrassBat, 9);
	
	
	}
	if (getBattleResult(&mamoswineGrassBat) == 1 && (GetMamoswineGrassElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		setMusic(4);
		mamoswineElementalCount |= mamoswineGrass;
		sfIntRect mammoswineGrassRect = { 0,0,48,48 };
	}
}
void SetMamoswineElectric(sfRenderWindow* _window, sfFloatRect playerPos)
{


	if (sfKeyboard_isKeyPressed(sfKeyE) && isInsidePlayer(getMamoswineHitboxByPos(playerPos), GetCollisionMamoswineElectric()) && (GetMamoswineElectricElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		startBattle(&mamoswineBat, &mamoswineElectricBat, 10);
	}
	if (getBattleResult(&mamoswineElectricBat) == 1 && (GetMamoswineElectricElementalCount() != 1 && GetMamoswineElementalCount() != 16))
	{
		setMusic(5);
		mamoswineElementalCount |= mamoswineElectric;
		sfIntRect mammoswineElectricRect = { 0,0,48,48 };
	}
}
//regroupe les sets de tous les mammochons
void SetAllMamoswine(sfRenderWindow* _window, sfFloatRect playerPos)
{
	SetMamoswineFire(_window, playerPos);
	SetMamoswineWater(_window, playerPos);
	SetMamoswineGrass(_window, playerPos);
	SetMamoswineElectric(_window, playerPos);
	SetMamoswineDialga(_window, playerPos);
}
//affiche tous les mammochons
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

//recupere le bits mamoswineElementalCount
int GetMamoswineElementalCount()
{

	return mamoswineElementalCount ;
}
//recupere une partie du bits mamoswineElementalCount
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
//monte la valeur du bits mamoswineElementalCount de +1 pour pouvoir afficher la porte ouverte
void SetMamoswineElementalCountToPlusOne()
{

	mamoswineElementalCount++;
}
//sauvegarde et load les mammoswine
void saveMamowsineData(const char* filename)
{

	FILE* file = fopen(filename, "wb");
	if (file == NULL)
	{
		printf("Erreur: Impossible de creer le fichier %s\n", filename);
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
		printf("Aucune sauvegarde trouvee. Creation de %s...\n", filename);
		saveMamowsineData(filename);
		return;
	}
	fread(&mamoswineElementalCount, sizeof(char), 1, file);

	fclose(file);

	printf("Map chargee depuis %s\n", filename);
}
//give la valeur de position des mammochons de la savewine
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