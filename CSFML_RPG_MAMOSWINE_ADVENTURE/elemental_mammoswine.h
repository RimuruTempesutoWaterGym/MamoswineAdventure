#include"tools.h"

#define MAMOSWINE_FIRE 0
#define MAMOSWINE_GRASS 1
#define MAMOSWINE_WATER 2
#define MAMOSWINE_ELECTRIC 3


void initElementalMamoswine();
void updateElementalMamoswine();
void displayElementalMamoswine(sfRenderWindow* _window);
int GetMamoswineElementalCount();
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
void setMamoswineFirePosition(sfVector2f newPos);
void setMamoswineWaterPosition(sfVector2f newPos);
void setMamoswineGrassPosition(sfVector2f newPos);
void setMamoswineElectricPosition(sfVector2f newPos);
void saveMamowsineData(const char* filename);
void loadMamowsineData(const char* filename);
typedef enum {
	mamoswineFire = 1 << MAMOSWINE_FIRE,
	mamoswineGrass = 1 << MAMOSWINE_GRASS,
	mamoswineWater = 1 << MAMOSWINE_WATER,
	mamoswineElectric = 1 << MAMOSWINE_ELECTRIC,
}elementalsMamoswine;

