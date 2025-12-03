#include "tools.h"
typedef enum {
    Normal, Ground, Ice, Grass, Fire, Combat, Fairy, Water, Electric, Steel, Dragon, Bug, Ghost, Dark, Psy, Fly, Rock, Poison,
    TYPE_COUNT, Null
} Types;
typedef enum {
    physical, special
} Category;
typedef struct {
    int id;
    char name[20];
    int power;
    int accuracy;
    int priority;
    Category category;
    Types type;
} Attack;

typedef struct {
    char name[30];
    int maxHp;
    int currentHp;
    Attack attacks[4];
    int stats[6];  // HP, Attack, Defense, SpAtk, SpDef, Speed
    Types type[2];
} Pokemon;



extern Pokemon mamoswineBat;
extern Pokemon mamoswineFireBat;
extern Pokemon mamoswineWaterBat;
extern Pokemon mamoswineGrassBat;
extern Pokemon mamoswineElectricBat;
extern Pokemon mamoswineDialgaBat;

void initTypeChart();
float getTypeEffectiveness(Types attackType, Types defenderType1, Types defenderType2);
const char* getTypeName(Types type);
void initPokemons();
void initAttacks();
void initBattle();
int startBattle(Pokemon* player, Pokemon* opponent);
void displayBattleUI(sfRenderWindow* _window);
void checkWhichSpriteToDraw(sfRenderWindow* _window);
void setCurrentMamoswineBattle(Pokemon* opponent);