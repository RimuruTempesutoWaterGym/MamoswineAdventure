#include "player.h"
#include "door.h"
#include "map.h"
#include "NPC.h"
#include "elemental_mammoswine.h"

//#include"camera.h"


sfSprite* spPlayer;
sfTexture* texPlayer;
float PlayerTimer = 0.0f;

float timer = 0.0f;
float timerattack = 0.0f;
float timerCdAttack = 0.0f;
int compt = -1;
int frameX = 0;
int frameY = 0;
int isAttacking = 0;
sfVector2f playerVel = { 72.0f,72.0f };
sfVector2f posMamoswine = { 1200.0f,300.0f };
sfVector2f speed;
sfBool hasMoved = sfFalse;
sfSprite* mamoswineSprite;
sfTexture* myTextureMamoswine;
sfIntRect mamoswineAnimation = { 0, 0, 48, 48 };



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
      

        //if (sfKeyboard_isKeyPressed(sfKeySpace) && posMamoswine.x > 0)
        //{
        //    frameY = 4;
        //    mamoswineAnimation.top = frameY * mamoswineAnimation.height;
        //    hasMoved = sfTrue;
        //    updateMastery(posMamoswine, mamoswineAnimation);

        //}
        speed = playerVel;
   
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
        }
        if (sfKeyboard_isKeyPressed(sfKeyF) && timerCdAttack > 2.f || isAttacking == 1 )
        {
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

    //else if (state == EDITOR)
    //{

    //}
    //updateCamera(posMamoswine, mamoswineAnimation, _window);
}


void displayPlayer(sfRenderWindow* _window)
{
    if (state == GAME || state == EDITOR)
    {
        sfRenderWindow_drawSprite(_window, mamoswineSprite, NULL);
            updateTextBox();  
    }
}
sfFloatRect getMamoswineHitboxByPos(sfFloatRect _mamoswinePos)
{
    _mamoswinePos.left += _mamoswinePos.width / 4;

    _mamoswinePos.top += _mamoswinePos.height / 4;
    _mamoswinePos.height /= 2;
    _mamoswinePos.width /= 2;
    return _mamoswinePos;
}
sfBool isPlayerOverDoor()
{
 
    if (GetCollisionOfDoor().height+ GetCollisionOfDoor().top < getCollisionOfPlayer().height + getCollisionOfPlayer().top )
    {
        return sfFalse;
    }
        return sfTrue;
}
//sfFloatRect gethitboxMamoswine(sfFloatRect _sprite, Direction _direction, sfFloatRect spriteHitbox)
//{
//    switch (_direction)
//    {
//    case Down:
//        spriteHitbox.y = (int)((_sprite.top + _sprite.height + _vitesse->y * delataTime) / TILE_WIDTH);
//        spriteHitbox.x = (int)(_sprite.left / TILE_WIDTH);
//        nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
//        nextPosInTab2.y = (int)((_sprite.top + _sprite.height + _vitesse->y * delataTime) / TILE_WIDTH);
//        return spriteHitbox;
//        break;
//    case Top:
//
//        nextPosInTab.y = (int)((_sprite.top + (_sprite.height / 2) - _vitesse->y * delataTime) / TILE_WIDTH);
//        nextPosInTab.x = (int)(_sprite.left / TILE_WIDTH);
//        nextPosInTab2.x = (_sprite.left + _sprite.width) / TILE_WIDTH;
//        nextPosInTab2.y = (int)((_sprite.top + (_sprite.height / 2) - _vitesse->y * delataTime) / TILE_WIDTH);
//
//
//        break;
//    case Right:
//        nextPosInTab.y = (int)((_sprite.top + (_sprite.height / 2)) / TILE_WIDTH);
//        nextPosInTab.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
//        nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
//        nextPosInTab2.x = (int)((_sprite.left + _sprite.width + _vitesse->x * delataTime) / TILE_WIDTH);
//
//        break;
//    case Left:
//        nextPosInTab.y = (int)((_sprite.top + (_sprite.height / 2)) / TILE_WIDTH);
//        nextPosInTab.x = (int)((_sprite.left - _vitesse->x * delataTime) / TILE_WIDTH);
//        nextPosInTab2.x = (int)((_sprite.left - _vitesse->x * delataTime) / TILE_WIDTH);
//        nextPosInTab2.y = (_sprite.top + _sprite.height) / TILE_WIDTH;
//
//
//        break;
//    }
//}

