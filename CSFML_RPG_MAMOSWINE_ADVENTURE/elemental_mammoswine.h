#include"tools.h"
#include"battle.h"

#define MAMOSWINE_FIRE 0
#define MAMOSWINE_GRASS 1
#define MAMOSWINE_WATER 2
#define MAMOSWINE_ELECTRIC 3


void initElementalMamoswine();
void updateElementalMamoswine();
void updateMamoDialga();
void displayElementalMamoswine(sfRenderWindow* _window);
void displayMamoDialga(sfRenderWindow* _window);
int GetMamoswineElementalCount();
int GetMamoswineGrassElementalCount();
int GetMamoswineFireElementalCount();
int GetMamoswineWaterElementalCount();
int GetMamoswineElectricElementalCount();
void SetMamoswineFire(sfRenderWindow* _window, sfFloatRect playerPos);
void SetMamoswineWater(sfRenderWindow* _window, sfFloatRect playerPos);
void SetMamoswineGrass(sfRenderWindow* _window, sfFloatRect playerPos);
void SetMamoswineElectric(sfRenderWindow* _window, sfFloatRect playerPos);
void SetAllMamoswine(sfRenderWindow* _window, sfFloatRect playerPos);
void SetMamoswineElementalCountToPlusOne();
sfFloatRect GetCollisionMamoswineWater();
sfFloatRect GetCollisionMamoswineGrass();
sfFloatRect GetCollisionMamoswineFire();
sfFloatRect GetCollisionMamoswineElectric();
sfFloatRect GetCollisionMamoswineDialga();
sfFloatRect GetRangeMamoswineDialga();
void setMamoswineFirePosition(sfVector2f newPos, int frame);
void setMamoswineWaterPosition(sfVector2f newPos, int frame);
void setMamoswineGrassPosition(sfVector2f newPos, int frame);
void setMamoswineElectricPosition(sfVector2f newPos,int frame);
void setMamoswineDialgaPosition(sfVector2f newPos);
void saveMamowsineData(const char* filename);
void loadMamowsineData(const char* filename);
typedef enum {
	mamoswineFire = 1 << MAMOSWINE_FIRE,
	mamoswineGrass = 1 << MAMOSWINE_GRASS,
	mamoswineWater = 1 << MAMOSWINE_WATER,
	mamoswineElectric = 1 << MAMOSWINE_ELECTRIC,
}elementalsMamoswine;

