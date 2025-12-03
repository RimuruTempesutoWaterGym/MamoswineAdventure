#include"battle.h"
#define GET_EFFECTIVENESS(attacker, defender) \
    ((typeChart[attacker][(defender) / 4] >> (((defender) % 4) * 2)) & 0x03)
#define SET_EFFECTIVENESS(attacker, defender, value) \
    do { \
        int byte_idx = (defender) / 4; \
        int bit_offset = ((defender) % 4) * 2; \
        typeChart[attacker][byte_idx] &= ~(0x03 << bit_offset); \
        typeChart[attacker][byte_idx] |= ((value) & 0x03) << bit_offset; \
    } while(0)
#define EFF_IMMUNE      0x00  // 00 en binaire = 0.0x
#define EFF_NOT_VERY    0x01  // 01 en binaire = 0.5x
#define EFF_NORMAL      0x02  // 10 en binaire = 1.0x
#define EFF_SUPER       0x03  // 11 en binaire = 2.0x

static unsigned char typeChart[TYPE_COUNT][5];
char currentMamoswineBattle[30] = "";
Pokemon mamoswineBat;
Pokemon mamoswineFireBat;
Pokemon mamoswineWaterBat;
Pokemon mamoswineGrassBat;
Pokemon mamoswineElectricBat;
Pokemon mamoswineDialgaBat;
Pokemon* currentPlayer;
Pokemon* currentOpponent;
int selectedMove = 0;
float battleTimer = 0.0f;
char battleMessage[100] = "";
int playerTurn = 1;


BattleState battleState = BATTLE_INTRO;
sfSprite* battleBackgroundFire;
sfSprite* battleBackgroundWater;
sfSprite* battleBackgroundElectric;
sfSprite* battleBackgroundGrass;
sfSprite* battleBackgroundTime;

sfSprite* battleMamoswine;
sfSprite* battleMamoswineFire;
sfSprite* battleMamoswineWater;
sfSprite* battleMamoswineElectric;
sfSprite* battleMamoswineGrass;
sfSprite* battleMamoswineDialga;

sfSprite* battleUiMove1;
sfSprite* battleUiMove2;
sfSprite* battleUiMove3;
sfSprite* battleUiMove4;

sfTexture* battleBgFireTexture;
sfTexture* battleBgWaterTexture;
sfTexture* battleBgElectricTexture;
sfTexture* battleBgGrassTexture;
sfTexture* battleBgTimeTexture;

sfTexture* battleUiTexture;
sfTexture* battleUiMove1Texture;
sfTexture* battleUiMove2Texture;
sfTexture* battleUiMove3Texture;
sfTexture* battleUiMove4Texture;

sfTexture* battleMamoswineTexture;
sfTexture* battleMamoswineFireTexture;
sfTexture* battleMamoswineWaterTexture;
sfTexture* battleMamoswineElectricTexture;
sfTexture* battleMamoswineGrassTexture;
sfTexture* battleMamoswineDialgaTexture;

sfVector2f battlePosMamoswineOpponent = {490.f,0.f };
sfVector2f battleMamoswineScaleOpponent = {2.6f,2.6f };
sfVector2f battleMamoswineScalePlayer = {5.f,5.f };
sfVector2f battlePosMamoswinePlayer = {130.f,150.f };
sfVector2f battleBgGrassSize = {3.3f,2.8f };
sfIntRect battleMamoswineRect ={0,0,81,71 };
sfIntRect battleMamoswineFireRect = { 0,0,83,74 };
sfIntRect battleMamoswineWaterRect = { 0,0,83,74 };
sfIntRect battleMamoswineElectricRect = { 0,0,83,74 };
sfIntRect battleMamoswineGrassRect = {0, 0, 83, 74 };
sfIntRect battleMamoswineDialgaRect = {0, 0, 83, 74 };
sfRectangleShape* battleUI;
sfText* battleText;
Attack iceShard;
Attack earthquake;
Attack flamethrower;
Attack fireBlast;
Attack surf;
Attack hydroPump;
Attack trailblaze;
Attack energyBall;
Attack thunderbolt;
Attack thunder;
Attack ironHead;
Attack dragonClaw;
Attack icicleCrash;

void initBattle() {
    initTypeChart();
    initAttacks();
    initPokemons();



    battleBackgroundFire = sfSprite_create();
    battleBackgroundWater = sfSprite_create();
    battleBackgroundElectric = sfSprite_create();
    battleBackgroundGrass = sfSprite_create();
    battleBackgroundTime = sfSprite_create();

    battleMamoswine = sfSprite_create();
    battleMamoswineFire = sfSprite_create();
    battleMamoswineWater = sfSprite_create();
    battleMamoswineElectric = sfSprite_create();
    battleMamoswineGrass = sfSprite_create();
    battleMamoswineDialga = sfSprite_create();

    battleUiMove1 = sfSprite_create();
    battleUiMove2 = sfSprite_create();
    battleUiMove3 = sfSprite_create();
    battleUiMove4 = sfSprite_create();

    battleBgFireTexture = sfTexture_createFromFile(TEXTURE_PATH"grassy_bg.png", NULL);
    battleBgWaterTexture = sfTexture_createFromFile(TEXTURE_PATH"grassy_bg.png", NULL);
    battleBgElectricTexture = sfTexture_createFromFile(TEXTURE_PATH"grassy_bg.png", NULL);
    battleBgGrassTexture = sfTexture_createFromFile(TEXTURE_PATH"grassy_bg.png", NULL);
    battleBgTimeTexture = sfTexture_createFromFile(TEXTURE_PATH"grassy_bg.png", NULL);

    battleMamoswineTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleBack.png", NULL);
    battleMamoswineFireTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleFront.png", NULL);
    battleMamoswineWaterTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleFront.png", NULL);
    battleMamoswineElectricTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleFront.png", NULL);
    battleMamoswineGrassTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleFront.png", NULL);
    battleMamoswineDialgaTexture = sfTexture_createFromFile(TEXTURE_PATH"mamoswinebattleFront.png", NULL);
    
    sfSprite_setTexture(battleMamoswine, battleMamoswineTexture, sfTrue);
    sfSprite_setTexture(battleMamoswineFire, battleMamoswineFireTexture, sfTrue);
    sfSprite_setTexture(battleMamoswineWater, battleMamoswineWaterTexture, sfTrue);
    sfSprite_setTexture(battleMamoswineElectric, battleMamoswineElectricTexture, sfTrue);
    sfSprite_setTexture(battleMamoswineGrass, battleMamoswineGrassTexture, sfTrue);
    sfSprite_setTexture(battleMamoswineDialga, battleMamoswineDialgaTexture, sfTrue);

    sfSprite_setTextureRect(battleMamoswine,battleMamoswineRect);
    sfSprite_setTextureRect(battleMamoswineFire,battleMamoswineFireRect);
    sfSprite_setTextureRect(battleMamoswineWater,battleMamoswineWaterRect);
    sfSprite_setTextureRect(battleMamoswineElectric,battleMamoswineElectricRect);
    sfSprite_setTextureRect(battleMamoswineGrass,battleMamoswineGrassRect);
    sfSprite_setTextureRect(battleMamoswineDialga,battleMamoswineDialgaRect);
    
    sfSprite_setPosition(battleMamoswine, battlePosMamoswinePlayer);
    sfSprite_setPosition(battleMamoswineFire, battlePosMamoswineOpponent);
    sfSprite_setPosition(battleMamoswineWater, battlePosMamoswineOpponent);
    sfSprite_setPosition(battleMamoswineElectric, battlePosMamoswineOpponent);
    sfSprite_setPosition(battleMamoswineGrass, battlePosMamoswineOpponent);
    sfSprite_setPosition(battleMamoswineDialga, battlePosMamoswineOpponent);
     
    sfSprite_setScale(battleMamoswine, battleMamoswineScalePlayer);
    sfSprite_setScale(battleMamoswineFire, battleMamoswineScaleOpponent);
    sfSprite_setScale(battleMamoswineWater, battleMamoswineScaleOpponent);
    sfSprite_setScale(battleMamoswineElectric, battleMamoswineScaleOpponent);
    sfSprite_setScale(battleMamoswineGrass, battleMamoswineScaleOpponent);
    sfSprite_setScale(battleMamoswineDialga, battleMamoswineScaleOpponent);
     
   

    battleUiMove1Texture = sfTexture_createFromFile(TEXTURE_PATH"BattleUiMove1.png", NULL);
    battleUiMove2Texture = sfTexture_createFromFile(TEXTURE_PATH"BattleUiMove2.png", NULL);
    battleUiMove3Texture = sfTexture_createFromFile(TEXTURE_PATH"BattleUiMove3.png", NULL);
    battleUiMove4Texture = sfTexture_createFromFile(TEXTURE_PATH"BattleUiMove4.png", NULL);

    sfSprite_setTexture(battleBackgroundGrass, battleBgGrassTexture, sfTrue);
    sfSprite_setScale(battleBackgroundGrass, battleBgGrassSize);


    sfSprite_setTexture(battleUiMove1, battleUiMove1Texture, sfTrue);
    sfSprite_setPosition(battleUiMove1, (sfVector2f) { 20.0f, 450.0f});
    sfSprite_setScale(battleUiMove1, (sfVector2f) {
        2.5f, 1.f
    });
    sfSprite_setTexture(battleUiMove2, battleUiMove2Texture, sfTrue);
    sfSprite_setPosition(battleUiMove2, (sfVector2f) { 20.0f, 525.0f });
    sfSprite_setScale(battleUiMove2, (sfVector2f) {
        2.5f, 1.f
    });
    sfSprite_setTexture(battleUiMove3, battleUiMove3Texture, sfTrue);
    sfSprite_setPosition(battleUiMove3, (sfVector2f) { 400.0f, 450.0f
    });
    sfSprite_setScale(battleUiMove3, (sfVector2f) { 2.5f, 1.f
    });

    sfSprite_setTexture(battleUiMove4, battleUiMove4Texture, sfTrue);
    sfSprite_setPosition(battleUiMove4, (sfVector2f) {
        400.0f, 525.0f
    });
    sfSprite_setScale(battleUiMove4, (sfVector2f) {
        2.5f, 1.f
    });

    battleUI = sfRectangleShape_create();
    sfRectangleShape_setSize(battleUI, (sfVector2f) { 800.0f, 200.0f });
    sfRectangleShape_setPosition(battleUI, (sfVector2f) { 0.0f, 426.0f });
    sfRectangleShape_setFillColor(battleUI, (sfColor) { 255, 86, 79, 255 });

    battleText = sfText_create();
    sfText_setFont(battleText, sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf"));
    sfText_setCharacterSize(battleText, 24);
    sfText_setFillColor(battleText, sfWhite);
}

void initAttacks() {
  
    iceShard = (Attack){
        1,
        "Eclat Glace",
        40,
        100,
        1,
         physical,
        Ice
    };
    earthquake = (Attack){
        2,
        "Seisme",
        100,
        100,
        0,
         physical,
        Ground
    };
    icicleCrash = (Attack){
    13,
    "Chute Glace",
    90,
    100,
    0,
    physical,
    Ice
    };

 
    flamethrower = (Attack){
        3,
        "Lance-Flammes",
        90,
        100,
        0,
         special,
        Fire
    };
     fireBlast = (Attack){
        4,
        "Deflagration",
        110,
        85,
        0,
         special,
        Fire
    };

  
     surf = (Attack){
        5,
        "Surf",
        90,
        100,
        0,
         special,
        Water
    };
     hydroPump = (Attack){
        6,
        "Hydrocanon",
        110,
        80,
        0,
         special,
        Water
    };


     trailblaze = (Attack){
        7,
        "Desherbaffe",
        90,
        100,
        0,
         physical,
        Grass
    };
     energyBall = (Attack){
        8,
        "EcoSphere",
        90,
        100,
        0,
 special,
 Grass
    };


     thunderbolt = (Attack){
        9,
        "Tonnerre",
        90,
        100,
        0,
         special,
        Electric
    };
     thunder = (Attack){
        10,
        "Fatal-Foudre",
        110,
        70,
        0,
         special,
        Electric
    };


     ironHead = (Attack){
        11,
        "Tete de Fer",
        80,
        100,
        0,
         physical,
        Steel
    };
     dragonClaw = (Attack){
        12,
        "Draco Griffe",
        80,
        100,
        0,
         physical,
        Dragon
    };
}


void initPokemons() {

    mamoswineBat = (Pokemon){
        "Mammochon",
        0,
        0,
        {earthquake,iceShard,icicleCrash,trailblaze

        },
        {110, 130, 80, 70, 60, 80},
        {Ground, Ice}
    };
    mamoswineBat.maxHp = mamoswineBat.stats[0] * 3.14;
    mamoswineBat.currentHp = mamoswineBat.maxHp;


    mamoswineFireBat = (Pokemon){
        "Mammochon Feu",
          0,
        0,
        {
        fireBlast,flamethrower,
            {0}, {0}
        },
        {90, 100, 50, 100, 100, 90},
        {Fire, Null}
    };
    mamoswineFireBat.maxHp = mamoswineFireBat.stats[0] * 3.14;
    mamoswineFireBat.currentHp = mamoswineFireBat.maxHp;

    
    mamoswineWaterBat = (Pokemon){
        "Mammochon Eau",
          0,
        0,
        {surf,hydroPump,
            {0}, {0}
        },
        {110, 80, 100, 80, 85, 75},
        {Water, Null}
    };
    mamoswineWaterBat.maxHp = mamoswineWaterBat.stats[0] * 3.14;
    mamoswineWaterBat.currentHp = mamoswineWaterBat.maxHp;
    mamoswineGrassBat = (Pokemon){
        "Mammochon Plante",
          0,
        0,
        {
         trailblaze,energyBall,
            {0}, {0}
        },
        {130, 50, 90, 95, 90, 75},
        {Grass, Null}
    };
    mamoswineGrassBat.maxHp = mamoswineGrassBat.stats[0] * 3.14;
    mamoswineGrassBat.currentHp = mamoswineGrassBat.maxHp;
    mamoswineElectricBat = (Pokemon){

        "Mammochon Electrique",
          0,
        0,
        {thunderbolt,thunder,
            {0}, {0}
        },
        {70, 80, 60, 140, 60, 120},
        {Electric, Null}
    };
    mamoswineElectricBat.maxHp = mamoswineElectricBat.stats[0] * 3.14;
    mamoswineElectricBat.currentHp = mamoswineElectricBat.maxHp;
    mamoswineDialgaBat = (Pokemon){
        "Mammochon Dialga",
          0,
        0,
        {
      dragonClaw,ironHead,
            {0}, {0}
        },
        {110, 80, 100, 80, 100, 100},
        {Steel, Dragon}
    };
    mamoswineDialgaBat.maxHp = mamoswineDialgaBat.stats[1] * 4;
    mamoswineDialgaBat.currentHp = mamoswineDialgaBat.maxHp;
}   
void initTypeChart() {

    for (int i = 0; i < TYPE_COUNT; i++) {
        for (int j = 0; j < TYPE_COUNT; j++) {
            SET_EFFECTIVENESS(i, j, EFF_NORMAL);
        }
    }
    // Normal (attaquant)
    typeChart[Normal][Rock] = EFF_NOT_VERY;
    typeChart[Normal][Ghost] = EFF_IMMUNE;
    typeChart[Normal][Steel] = EFF_NOT_VERY;

    // Ground (attaquant)
    typeChart[Ground][Fire] = EFF_SUPER;
    typeChart[Ground][Electric] = EFF_SUPER;
    typeChart[Ground][Grass] = EFF_NOT_VERY;
    typeChart[Ground][Poison] = EFF_SUPER;
    typeChart[Ground][Fly] = EFF_IMMUNE;
    typeChart[Ground][Bug] = EFF_NOT_VERY;
    typeChart[Ground][Rock] = EFF_SUPER;
    typeChart[Ground][Steel] = EFF_SUPER;

    // Ice (attaquant)
    typeChart[Ice][Fire] = EFF_NOT_VERY;
    typeChart[Ice][Water] = EFF_NOT_VERY;
    typeChart[Ice][Grass] = EFF_SUPER;
    typeChart[Ice][Ice] = EFF_NOT_VERY;
    typeChart[Ice][Ground] = EFF_SUPER;
    typeChart[Ice][Fly] = EFF_SUPER;
    typeChart[Ice][Dragon] = EFF_SUPER;
    typeChart[Ice][Steel] = EFF_NOT_VERY;

    // Grass (attaquant)
    typeChart[Grass][Fire] = EFF_NOT_VERY;
    typeChart[Grass][Water] = EFF_SUPER;
    typeChart[Grass][Grass] = EFF_NOT_VERY;
    typeChart[Grass][Poison] = EFF_NOT_VERY;
    typeChart[Grass][Ground] = EFF_SUPER;
    typeChart[Grass][Fly] = EFF_NOT_VERY;
    typeChart[Grass][Bug] = EFF_NOT_VERY;
    typeChart[Grass][Rock] = EFF_SUPER;
    typeChart[Grass][Dragon] = EFF_NOT_VERY;
    typeChart[Grass][Steel] = EFF_NOT_VERY;

    // Fire (attaquant)
    typeChart[Fire][Fire] = EFF_NOT_VERY;
    typeChart[Fire][Water] = EFF_NOT_VERY;
    typeChart[Fire][Grass] = EFF_SUPER;
    typeChart[Fire][Ice] = EFF_SUPER;
    typeChart[Fire][Bug] = EFF_SUPER;
    typeChart[Fire][Rock] = EFF_NOT_VERY;
    typeChart[Fire][Dragon] = EFF_NOT_VERY;
    typeChart[Fire][Steel] = EFF_SUPER;

    // Combat/Fighting (attaquant)
    typeChart[Combat][Normal] = EFF_SUPER;
    typeChart[Combat][Ice] = EFF_SUPER;
    typeChart[Combat][Poison] = EFF_NOT_VERY;
    typeChart[Combat][Fly] = EFF_NOT_VERY;
    typeChart[Combat][Psy] = EFF_NOT_VERY;
    typeChart[Combat][Bug] = EFF_NOT_VERY;
    typeChart[Combat][Rock] = EFF_SUPER;
    typeChart[Combat][Ghost] = EFF_IMMUNE;
    typeChart[Combat][Dark] = EFF_SUPER;
    typeChart[Combat][Steel] = EFF_SUPER;
    typeChart[Combat][Fairy] = EFF_NOT_VERY;

    // Fairy (attaquant)
    typeChart[Fairy][Fire] = EFF_NOT_VERY;
    typeChart[Fairy][Combat] = EFF_SUPER;
    typeChart[Fairy][Poison] = EFF_NOT_VERY;
    typeChart[Fairy][Dragon] = EFF_SUPER;
    typeChart[Fairy][Dark] = EFF_SUPER;
    typeChart[Fairy][Steel] = EFF_NOT_VERY;

    // Water (attaquant)
    typeChart[Water][Fire] = EFF_SUPER;
    typeChart[Water][Water] = EFF_NOT_VERY;
    typeChart[Water][Grass] = EFF_NOT_VERY;
    typeChart[Water][Ground] = EFF_SUPER;
    typeChart[Water][Rock] = EFF_SUPER;
    typeChart[Water][Dragon] = EFF_NOT_VERY;

    // Electric (attaquant)
    typeChart[Electric][Water] = EFF_SUPER;
    typeChart[Electric][Electric] = EFF_NOT_VERY;
    typeChart[Electric][Grass] = EFF_NOT_VERY;
    typeChart[Electric][Ground] = EFF_IMMUNE;
    typeChart[Electric][Fly] = EFF_SUPER;
    typeChart[Electric][Dragon] = EFF_NOT_VERY;

    // Steel (attaquant)
    typeChart[Steel][Fire] = EFF_NOT_VERY;
    typeChart[Steel][Water] = EFF_NOT_VERY;
    typeChart[Steel][Electric] = EFF_NOT_VERY;
    typeChart[Steel][Ice] = EFF_SUPER;
    typeChart[Steel][Rock] = EFF_SUPER;
    typeChart[Steel][Steel] = EFF_NOT_VERY;
    typeChart[Steel][Fairy] = EFF_SUPER;

    // Dragon (attaquant)
    typeChart[Dragon][Dragon] = EFF_SUPER;
    typeChart[Dragon][Steel] = EFF_NOT_VERY;
    typeChart[Dragon][Fairy] = EFF_IMMUNE;

    // Bug (attaquant)
    typeChart[Bug][Fire] = EFF_NOT_VERY;
    typeChart[Bug][Grass] = EFF_SUPER;
    typeChart[Bug][Combat] = EFF_NOT_VERY;
    typeChart[Bug][Poison] = EFF_NOT_VERY;
    typeChart[Bug][Fly] = EFF_NOT_VERY;
    typeChart[Bug][Psy] = EFF_SUPER;
    typeChart[Bug][Ghost] = EFF_NOT_VERY;
    typeChart[Bug][Dark] = EFF_SUPER;
    typeChart[Bug][Steel] = EFF_NOT_VERY;
    typeChart[Bug][Fairy] = EFF_NOT_VERY;

    // Ghost (attaquant)
    typeChart[Ghost][Normal] = EFF_IMMUNE;
    typeChart[Ghost][Psy] = EFF_SUPER;
    typeChart[Ghost][Ghost] = EFF_SUPER;
    typeChart[Ghost][Dark] = EFF_NOT_VERY;

    // Dark (attaquant)
    typeChart[Dark][Combat] = EFF_NOT_VERY;
    typeChart[Dark][Psy] = EFF_SUPER;
    typeChart[Dark][Ghost] = EFF_SUPER;
    typeChart[Dark][Dark] = EFF_NOT_VERY;
    typeChart[Dark][Fairy] = EFF_NOT_VERY;

    // Psy (attaquant)
    typeChart[Psy][Combat] = EFF_SUPER;
    typeChart[Psy][Poison] = EFF_SUPER;
    typeChart[Psy][Psy] = EFF_NOT_VERY;
    typeChart[Psy][Dark] = EFF_IMMUNE;
    typeChart[Psy][Steel] = EFF_NOT_VERY;

    // Fly (attaquant)
    typeChart[Fly][Electric] = EFF_NOT_VERY;
    typeChart[Fly][Grass] = EFF_SUPER;
    typeChart[Fly][Combat] = EFF_SUPER;
    typeChart[Fly][Bug] = EFF_SUPER;
    typeChart[Fly][Rock] = EFF_NOT_VERY;
    typeChart[Fly][Steel] = EFF_NOT_VERY;

    // Rock (attaquant)
    typeChart[Rock][Fire] = EFF_SUPER;
    typeChart[Rock][Ice] = EFF_SUPER;
    typeChart[Rock][Combat] = EFF_NOT_VERY;
    typeChart[Rock][Ground] = EFF_NOT_VERY;
    typeChart[Rock][Fly] = EFF_SUPER;
    typeChart[Rock][Bug] = EFF_SUPER;
    typeChart[Rock][Steel] = EFF_NOT_VERY;

    // Poison (attaquant)
    typeChart[Poison][Grass] = EFF_SUPER;
    typeChart[Poison][Poison] = EFF_NOT_VERY;
    typeChart[Poison][Ground] = EFF_NOT_VERY;
    typeChart[Poison][Rock] = EFF_NOT_VERY;
    typeChart[Poison][Ghost] = EFF_NOT_VERY;
    typeChart[Poison][Steel] = EFF_IMMUNE;
    typeChart[Poison][Fairy] = EFF_SUPER;
}
void displayBattleUI(sfRenderWindow* _window) {

    sfRenderWindow_drawSprite(_window, battleBackgroundGrass, NULL);


    checkWhichSpriteToDraw(_window);


    sfRenderWindow_drawSprite(_window, battleMamoswine, NULL);

 
    displayHealthBars(_window);

 
    sfRenderWindow_drawRectangleShape(_window, battleUI, NULL);

  
    if (battleState == BATTLE_PLAYER_TURN) {
        displayMoveButtons(_window);
    }

   
    sfText_setString(battleText, battleMessage);
    sfText_setPosition(battleText, (sfVector2f) { 30.0f, 425.0f });
    sfText_setFillColor(battleText, sfWhite);
    sfText_setOutlineColor(battleText, sfBlack);
    sfText_setOutlineThickness(battleText, 2.0f);
    sfRenderWindow_drawText(_window, battleText, NULL);
}
void displayMoveButtons(sfRenderWindow* _window) {
    printf("Affichage des moves, battleState = %d\n", battleState);

    for (int i = 0; i < 4; i++) {
        printf("Attaque %d: id=%d, nom=%s\n",
            i,
            currentPlayer->attacks[i].id,
            currentPlayer->attacks[i].name);
    }
    sfSprite* moves[4] = { battleUiMove1, battleUiMove2, battleUiMove3, battleUiMove4 };
    sfVector2f positions[4] = {
        {20.0f, 450.0f},
        {20.0f, 525.0f},
        {400.0f, 450.0f},
        {400.0f, 525.0f}
    };

    for (int i = 0; i < 4; i++) {
        if (currentPlayer->attacks[i].id != 0) {
      
            if (i == selectedMove) {
                sfSprite_setColor(moves[i], (sfColor) { 255, 255, 100, 255 }); 
            }
            else {
                sfSprite_setColor(moves[i], sfWhite);
            }

            sfRenderWindow_drawSprite(_window, moves[i], NULL);

            sfText_setCharacterSize(battleText, 20);
            sfText_setString(battleText, currentPlayer->attacks[i].name);
            sfText_setFillColor(battleText, sfWhite);
            sfText_setOutlineColor(battleText, sfBlack);
            sfText_setOutlineThickness(battleText, 2.0f);

            sfVector2f textPos = positions[i];
            textPos.x += 145;
            textPos.y += 5;
            sfText_setPosition(battleText, textPos);
            sfRenderWindow_drawText(_window, battleText, NULL);

       
            char typeInfo[50];
            sprintf(typeInfo, "Puissance: %d", currentPlayer->attacks[i].power);
            sfText_setCharacterSize(battleText, 14);
            sfText_setString(battleText, typeInfo);
            textPos.y += 25;
            sfText_setPosition(battleText, textPos);
            sfRenderWindow_drawText(_window, battleText, NULL);
        }
    }

   
    sfText_setCharacterSize(battleText, 24);
}
void displayHealthBars(sfRenderWindow* _window) {


    sfRectangleShape* playerHpBg = sfRectangleShape_create();
    sfRectangleShape_setSize(playerHpBg, (sfVector2f) { 200.0f, 15.0f });
    sfRectangleShape_setPosition(playerHpBg, (sfVector2f) { 50.0f, 350.0f });
    sfRectangleShape_setFillColor(playerHpBg, (sfColor) { 50, 50, 50, 255 });
    sfRectangleShape_setOutlineColor(playerHpBg, sfBlack);
    sfRectangleShape_setOutlineThickness(playerHpBg, 2.0f);
    sfRenderWindow_drawRectangleShape(_window, playerHpBg, NULL);

    sfRectangleShape* playerHpBar = sfRectangleShape_create();
    float playerHpPercent = (float)currentPlayer->currentHp / (float)currentPlayer->maxHp;
    sfRectangleShape_setSize(playerHpBar, (sfVector2f) { 196.0f * playerHpPercent, 11.0f });
    sfRectangleShape_setPosition(playerHpBar, (sfVector2f) { 52.0f, 352.0f });

    if (playerHpPercent > 0.5f) {
        sfRectangleShape_setFillColor(playerHpBar, (sfColor) { 76, 255, 0, 255 }); // Vert vif
    }
    else if (playerHpPercent > 0.25f) {
        sfRectangleShape_setFillColor(playerHpBar, (sfColor) { 255, 200, 0, 255 }); // Orange
    }
    else {
        sfRectangleShape_setFillColor(playerHpBar, (sfColor) { 255, 48, 48, 255 }); // Rouge
    }

    sfRenderWindow_drawRectangleShape(_window, playerHpBar, NULL);

  
    char hpText[50];
    sprintf(hpText, "%d / %d", currentPlayer->currentHp, currentPlayer->maxHp);
    sfText_setCharacterSize(battleText, 18);
    sfText_setString(battleText, hpText);
    sfText_setPosition(battleText, (sfVector2f) { 55.0f, 370.0f });
    sfText_setFillColor(battleText, sfWhite);
    sfText_setOutlineColor(battleText, sfBlack);
    sfText_setOutlineThickness(battleText, 2.0f);
    sfRenderWindow_drawText(_window, battleText, NULL);



    sfRectangleShape* enemyHpBg = sfRectangleShape_create();
    sfRectangleShape_setSize(enemyHpBg, (sfVector2f) { 200.0f, 15.0f });
    sfRectangleShape_setPosition(enemyHpBg, (sfVector2f) { 550.0f, 80.0f });
    sfRectangleShape_setFillColor(enemyHpBg, (sfColor) { 50, 50, 50, 255 });
    sfRectangleShape_setOutlineColor(enemyHpBg, sfBlack);
    sfRectangleShape_setOutlineThickness(enemyHpBg, 2.0f);
    sfRenderWindow_drawRectangleShape(_window, enemyHpBg, NULL);


    sfRectangleShape* enemyHpBar = sfRectangleShape_create();
    float enemyHpPercent = (float)currentOpponent->currentHp / (float)currentOpponent->maxHp;
    sfRectangleShape_setSize(enemyHpBar, (sfVector2f) { 196.0f * enemyHpPercent, 11.0f });
    sfRectangleShape_setPosition(enemyHpBar, (sfVector2f) { 552.0f, 82.0f });

    if (enemyHpPercent > 0.5f) {
        sfRectangleShape_setFillColor(enemyHpBar, (sfColor) { 76, 255, 0, 255 });
    }
    else if (enemyHpPercent > 0.25f) {
        sfRectangleShape_setFillColor(enemyHpBar, (sfColor) { 255, 200, 0, 255 });
    }
    else {
        sfRectangleShape_setFillColor(enemyHpBar, (sfColor) { 255, 48, 48, 255 });
    }

    sfRenderWindow_drawRectangleShape(_window, enemyHpBar, NULL);


    sprintf(hpText, "%d / %d", currentOpponent->currentHp, currentOpponent->maxHp);
    sfText_setString(battleText, hpText);
    sfText_setPosition(battleText, (sfVector2f) { 555.0f, 100.0f });
    sfRenderWindow_drawText(_window, battleText, NULL);

    sfText_setCharacterSize(battleText, 20);
    sfText_setString(battleText, currentOpponent->name);
    sfText_setPosition(battleText, (sfVector2f) { 555.0f, 55.0f });
    sfRenderWindow_drawText(_window, battleText, NULL);

    
    sfText_setCharacterSize(battleText, 24);
    sfText_setOutlineThickness(battleText, 1.0f);

    sfRectangleShape_destroy(playerHpBar);
    sfRectangleShape_destroy(playerHpBg);
    sfRectangleShape_destroy(enemyHpBar);
    sfRectangleShape_destroy(enemyHpBg);
}
void updateBattle(sfRenderWindow* _window) {
    battleTimer += GetDeltaTime();

    switch (battleState) {
    case BATTLE_INTRO:
        sprintf(battleMessage, "Vous Défiez le %s!!!", currentOpponent->name);
        if (battleTimer > 2.0f) {
            battleState = BATTLE_PLAYER_TURN;
            sprintf(battleMessage, "Que doit faire %s?", currentPlayer->name);
            battleTimer = 0.0f;
        }
        break;

    case BATTLE_PLAYER_TURN:
        if (battleTimer > 1.0f) {
            sprintf(battleMessage, "Que doit faire %s?", currentPlayer->name);
            battleTimer = 0;
        }
            handlePlayerInput(_window);
      
       
        break;

    case BATTLE_ENEMY_TURN:
        if (battleTimer > 2.0f) {
            performEnemyAttack();
           battleTimer = 0.0f;
            if (currentPlayer->currentHp <= 0) {
                battleState = BATTLE_END;
                sprintf(battleMessage, "%s est K.O.!", currentPlayer->name);
            }
            else {
              
                battleState = BATTLE_PLAYER_TURN;
          
     
                }
            
            }
        
        break;

    case BATTLE_ANIMATION:
        if (battleTimer > 2.0f) {
            if (currentOpponent->currentHp <= 0) {
                battleState = BATTLE_END;
                sprintf(battleMessage, "%s ennemi est K.O.!", currentOpponent->name);
            }
            else {
                battleState = BATTLE_ENEMY_TURN;
                sprintf(battleMessage, "%s ennemi attaque!", currentOpponent->name);
            }
            battleTimer = 0.0f;
        }
        break;

    case BATTLE_END:
        if (battleTimer > 2.0f) {
            if (currentPlayer->currentHp > 0) {
         
                state = GAME;
                currentPlayer->currentHp = currentPlayer->maxHp;
                currentOpponent->currentHp = currentOpponent->maxHp;
                battleState = BATTLE_INTRO;
            }
            else {
      
                state = GAME;
            }
        }
        break;
    }
}

void handlePlayerInput(sfRenderWindow* _window) {
    static float inputTimer = 0.0f;
    inputTimer += GetDeltaTime();

    if (inputTimer < 0.2f) return;


    if (sfKeyboard_isKeyPressed(sfKeyZ) && selectedMove > 0) {
        selectedMove--;
        inputTimer = 0.0f;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && selectedMove < 3) {
        selectedMove++;
        inputTimer = 0.0f;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && selectedMove > 1) {
        selectedMove -= 2;
        inputTimer = 0.0f;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && selectedMove < 2) {
        selectedMove += 2;
        inputTimer = 0.0f;
    }


    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        performPlayerAttack(selectedMove);
        inputTimer = 0.0f;
    }
}
void performPlayerAttack(int moveIndex) {
    Attack* attack = &currentPlayer->attacks[moveIndex];

    if (attack->id == 0) return;


    int damage = calculateDamage(currentPlayer, currentOpponent, attack);
    currentOpponent->currentHp -= damage;

    if (currentOpponent->currentHp < 0) {
        currentOpponent->currentHp = 0;
    }

  
    float effectiveness = getTypeEffectiveness(attack->type,
        currentOpponent->type[0],
        currentOpponent->type[1]);

    sprintf(battleMessage, "%s utilise %s! %d degats!",
        currentPlayer->name, attack->name, damage);

    battleState = BATTLE_ANIMATION;
    battleTimer = 0.0f;
}

void performEnemyAttack() {

    int moveIndex = rand() % 2; 

    Attack* attack = &currentOpponent->attacks[moveIndex];

    if (attack->id == 0) {
        moveIndex = 0; 
        attack = &currentOpponent->attacks[0];
    }

  
    int damage = calculateDamage(currentOpponent, currentPlayer, attack);
    currentPlayer->currentHp -= damage;

    if (currentPlayer->currentHp < 0) {
        currentPlayer->currentHp = 0;
    }

    sprintf(battleMessage, "%s ennemi utilise %s! %d degats!",
        currentOpponent->name, attack->name, damage);
}


void checkWhichSpriteToDraw(sfRenderWindow* _window) {
    if (strcmp(currentOpponent->name, mamoswineFireBat.name) == 0) {
        sfRenderWindow_drawSprite(_window, battleMamoswineFire, NULL);
    }
    else if (strcmp(currentOpponent->name, mamoswineWaterBat.name) == 0) {
        sfRenderWindow_drawSprite(_window, battleMamoswineWater, NULL);
    }
    else if (strcmp(currentOpponent->name, mamoswineGrassBat.name) == 0) {
        sfRenderWindow_drawSprite(_window, battleMamoswineGrass, NULL);
    }
    else if (strcmp(currentOpponent->name, mamoswineElectricBat.name) == 0) {
        sfRenderWindow_drawSprite(_window, battleMamoswineElectric, NULL);
    }
    else if (strcmp(currentOpponent->name, mamoswineDialgaBat.name) == 0) {
        sfRenderWindow_drawSprite(_window, battleMamoswineDialga, NULL);
    }
}
int startBattle(Pokemon* player, Pokemon* opponent) {
    currentPlayer = player;
    currentOpponent = opponent;

    state = BATTLE;
    battleState = BATTLE_INTRO;
    selectedMove = 0;
    battleTimer = 0.0f;

    sprintf(battleMessage, "Un %s sauvage apparait!", opponent->name);

    return 1; // Combat lancé
}
void setCurrentMamoswineBattle(Pokemon* opponent) {
    strncpy(currentMamoswineBattle, opponent->name, 29);
    currentMamoswineBattle[29] = '\0';
}
float getTypeEffectiveness(Types attackType, Types defenderType1, Types defenderType2) {
    if (attackType >= TYPE_COUNT) return 1.0f;

    float effectiveness = 1.0f;

    // Calculer l'efficacité contre le premier type
    if (defenderType1 != Null && defenderType1 < TYPE_COUNT) {
        switch (typeChart[attackType][defenderType1]) {
        case EFF_IMMUNE:    effectiveness *= 0.0f; break;
        case EFF_NOT_VERY:  effectiveness *= 0.5f; break;
        case EFF_NORMAL:    effectiveness *= 1.0f; break;
        case EFF_SUPER:     effectiveness *= 2.0f; break;
        }
    }

    // Calculer l'efficacité contre le second type
    if (defenderType2 != Null && defenderType2 < TYPE_COUNT) {
        switch (typeChart[attackType][defenderType2]) {
        case EFF_IMMUNE:    effectiveness *= 0.0f; break;
        case EFF_NOT_VERY:  effectiveness *= 0.5f; break;
        case EFF_NORMAL:    effectiveness *= 1.0f; break;
        case EFF_SUPER:     effectiveness *= 2.0f; break;
        }
    }

    return effectiveness;
}
const char* getTypeName(Types type) {
    switch (type) {
    case Null: return "None";
    case Normal: return "Normal";
    case Ground: return "Ground";
    case Ice: return "Ice";
    case Grass: return "Grass";
    case Fire: return "Fire";
    case Combat: return "Fighting";
    case Fairy: return "Fairy";
    case Water: return "Water";
    case Electric: return "Electric";
    case Steel: return "Steel";
    case Dragon: return "Dragon";
    case Bug: return "Bug";
    case Ghost: return "Ghost";
    case Dark: return "Dark";
    case Psy: return "Psychic";
    case Fly: return "Flying";
    case Rock: return "Rock";
    case Poison: return "Poison";
    default: return "Unknown";
    }

 
}
int calculateDamage(Pokemon* attacker, Pokemon* defender, Attack* attack) {
    int level = 100;
    float damage = 0;
    int attackStat = attacker->stats[1];
    int defenseStat = defender->stats[2];
    int attackSpecialStat = attacker->stats[3];
    int defenseSpecialStat = defender->stats[4];
    if (attack->category == physical)
    {
        damage = ((2.0f * level / 5.0f + 2.0f) * attack->power * attackStat / defenseStat) / 50.0f + 2.0f;
    }
        if (attack->category == special)
        {
             damage = ((2.0f * level / 5.0f + 2.0f) * attack->power * attackSpecialStat / defenseSpecialStat) / 50.0f + 2.0f;
        }
 


    float stab = 1.0f;
    if (attack->type == attacker->type[0] || attack->type == attacker->type[1]) {
        stab = 1.5f;
    }


    float effectiveness = getTypeEffectiveness(attack->type, defender->type[0], defender->type[1]);

    damage *= stab * effectiveness;

    if (effectiveness == 0.0f) {

    }
    else if (effectiveness < 1.0f) {

    }
    else if (effectiveness > 1.0f) {

    }

    return (int)damage;
}