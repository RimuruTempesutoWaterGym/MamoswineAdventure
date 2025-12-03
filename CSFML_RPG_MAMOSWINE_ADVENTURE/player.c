#include "player.h"
#include "door.h"
#include "map.h"
#include "NPC.h"
#include "elemental_mammoswine.h"
#include "music.h"

// Creation personnage et specificités
sfSprite* mamoswineSprite;
sfVector2f playerVel = { 72.0f,72.0f };
sfVector2f posMamoswine = { 1200.0f,300.0f };
sfTexture* myTextureMamoswine;
sfIntRect mamoswineAnimation = { 0, 0, 48, 48 };
sfVector2f speed;

// gestion affichage des sprites
int compt = -1;
int frameX = 0;
int frameY = 0;

// gestion des fonctions utilisant du temps
float PlayerTimer = 0.0f;
float timer = 0.0f;
float timerattack = 0.0f;
float timerCdAttack = 0.0f;

// Attaque du personnage
int isAttacking = 0;


sfBool hasMoved = sfFalse;





void initplayer()
{
    mamoswineSprite = sfSprite_create();
    myTextureMamoswine = sfTexture_createFromFile(TEXTURE_PATH"Mamoswine.png", NULL);
    sfSprite_setTexture(mamoswineSprite, myTextureMamoswine, sfTrue);
    sfSprite_setTextureRect(mamoswineSprite, mamoswineAnimation);
    sfSprite_setPosition(mamoswineSprite, posMamoswine);

}
sfFloatRect getCollisionOfPlayer()
{
  return sfSprite_getGlobalBounds(mamoswineSprite);
}
void updatePlayer(sfRenderWindow* _window)
{
    
    PlayerTimer += GetDeltaTime();

    if (state == GAME)
    {
        timerCdAttack += GetDeltaTime();
        speed = playerVel;
   

        // Deplacement du personnage quand il n'attaque pas

        if(isAttacking == 0)
        {
          
            hasMoved = sfFalse;
            if (sfKeyboard_isKeyPressed(sfKeyS) && posMamoswine.y < (MAP_HEIGHT * TILE_HEIGHT) - 23) {
                frameY = Down;
                if (!collisionMapPlayer(getCollisionOfPlayer(), Down, &speed))
                {
                    posMamoswine.y += speed.y * GetDeltaTime();
                }
                mamoswineAnimation.top = frameY * mamoswineAnimation.height;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyZ) && posMamoswine.y > 0) {

                frameY = Top;

                if (!collisionMapPlayer(getCollisionOfPlayer(), Top, &speed))
                {
                    posMamoswine.y -= speed.y * GetDeltaTime();
                }
                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && posMamoswine.x < (MAP_WIDTH * TILE_WIDTH) - 17)
            {
                frameY = Right;
                if (!collisionMapPlayer(getCollisionOfPlayer(), Right, &speed))
                {
                    posMamoswine.x += speed.x * GetDeltaTime();
                }
                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && posMamoswine.x > 0)
            {
                frameY = Left;
                if (!collisionMapPlayer(getCollisionOfPlayer(), Left, &speed))
                {
                    posMamoswine.x -= speed.x * GetDeltaTime();
                }
                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ))
            {
                frameY = RightTop;

                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyZ))
            {
                frameY = TopLeft;

                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyS))
            {
                frameY = DownLeft;

                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyS))
            {
                frameY = DownRight;

                mamoswineAnimation.top = frameY * mamoswineAnimation.height + frameY;
            }
            if (sfKeyboard_isKeyPressed(sfKeyE) && timerCdAttack > 1.f) {
                ElectricTogglePlayerMap(getCollisionOfPlayer(), frameY);
                timerCdAttack = 0.f;
            }
        }
      
        // Gestion du personnage quand il attaque (il ne peut plus se déplacer)
        if (sfKeyboard_isKeyPressed(sfKeyF) && timerCdAttack > 2.f || isAttacking == 1 )
        {
           
            playSoundAttack();
            timerattack += GetDeltaTime();
            isAttacking = 1;

            bushCutPlayerMap(getCollisionOfPlayer(), frameY);
            if (timerattack <= 0.25f)
            {

                mamoswineAnimation.left = 180;

            }
            else if (timerattack > 0.25f && timerattack < 0.5f)
            {
                mamoswineAnimation.left = 180 + 49;
             
            }
           else if (timerattack >= 0.5f)
            {
                timerattack = 0;
                isAttacking = 0;
                timerCdAttack = 0.f;
                mamoswineAnimation.left = 0;
            }
        } 
        SetAllMamoswine(_window, getCollisionOfPlayer());
       
        // Gestion des changements de sprites lors des mouvements
        if (PlayerTimer > 0.3f)
        {
            if (hasMoved)
                frameX += compt;
            else
                frameX = 1;
            if (frameX == 2 || frameX == 0)
                compt *= -1;
            timer = 2;
            if(isAttacking == 0)
            {
                mamoswineAnimation.left = frameX * mamoswineAnimation.width + frameX;
            }
            PlayerTimer = 0;
        }
      
        updateView(posMamoswine, mamoswineAnimation, _window);
        sfSprite_setTextureRect(mamoswineSprite, mamoswineAnimation);
        sfSprite_setPosition(mamoswineSprite, posMamoswine);
    }
}


void displayPlayer(sfRenderWindow* _window)
{
    if (state == GAME || state == EDITOR)
    {
        sfRenderWindow_drawSprite(_window, mamoswineSprite, NULL);
            updateTextBox();  
    }
}

// gestion de la hitbox du player
sfFloatRect getMamoswineHitboxByPos(sfFloatRect _mamoswinePos)
{
    _mamoswinePos.left += _mamoswinePos.width / 4;
    _mamoswinePos.top += _mamoswinePos.height / 4;
    _mamoswinePos.height /= 2;
    _mamoswinePos.width /= 2;
    return _mamoswinePos;
}

// Point d'apparition du player
void SetPosAtRespawn()
{
    setPlayerPosition(getPlayerSpawnPoint());

}

// Gestion du personnage en fonction de la traversée de la porte de fin
// Faire en sorte qu'il traverse la porte et ne marche pas dessus
sfBool isPlayerOverDoor()
{
 
    if (GetCollisionOfDoor().height+ GetCollisionOfDoor().top < getCollisionOfPlayer().height + getCollisionOfPlayer().top )
    {
        return sfFalse;
    }
        return sfTrue;
}

// fonction pour actualiser la position du joueur
void setPlayerPosition(sfVector2f newPos) {
    posMamoswine = newPos;
    if (mamoswineSprite != NULL) {
        sfSprite_setPosition(mamoswineSprite, posMamoswine);
    }
}
