#include "player.h"
#include "map.h"
//#include"camera.h"

#define MAP_HEIGHT 20
#define MAP_WIDTH 40
#define TILE_WIDTH 24
#define TILE_HEIGHT 24

sfSprite* spPlayer;
sfTexture* texPlayer;
sfIntRect irectPlayer = { 0,0,17,23 };
float PlayerTimer = 0.0f;
float timer = 0.0f;
float timerattack = 0.0f;
int compt = -1;
sfVector2f playerPos = { 400, 300 };
int frameX = 0;
int frameY = 0;
int isAttacking = 0;
sfVector2f playerVel = { 60.0f,60.0f };
sfVector2f posLink = { 500.0f,40.0f };
sfVector2f speed;
sfBool hasMoved = sfFalse;
sfSprite* linkSprite;
sfTexture* myTextureLink;
sfIntRect linkAnimation = { 0, 0, 48, 48 };



void initplayer()
{
    linkSprite = sfSprite_create();
    myTextureLink = sfTexture_createFromFile(TEXTURE_PATH"Mamoswine.png", NULL);
    sfSprite_setTexture(linkSprite, myTextureLink, sfTrue);
    sfSprite_setTextureRect(linkSprite, linkAnimation);

}
void updatePlayer()
{

    PlayerTimer += GetDeltaTime();

    //if (state == GAME)
    {
        //  initcamera();
        sfFloatRect playerfrect = sfSprite_getGlobalBounds(linkSprite);

        //if (sfKeyboard_isKeyPressed(sfKeySpace) && posLink.x > 0)
        //{
        //    frameY = 4;
        //    linkAnimation.top = frameY * linkAnimation.height;
        //    hasMoved = sfTrue;
        //    updateMastery(posLink, linkAnimation);

        //}

        speed = playerVel;
        if (isAttacking == 1)
        {
            hasMoved = sfFalse;
            if (sfKeyboard_isKeyPressed(sfKeyS) && posLink.y < (MAP_HEIGHT * TILE_HEIGHT) - 23 && timer <= 0) {
                frameY = Down;
                if (!collisionMapPlayer(playerfrect, Down, speed))
                {
                    posLink.y += speed.y * GetDeltaTime();
                }
                linkAnimation.top = frameY * linkAnimation.height;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyZ) && posLink.y > 0) {

                frameY = Top;

                if (!collisionMapPlayer(playerfrect, Top, speed))
                {
                    posLink.y -= speed.y * GetDeltaTime();
                }
                linkAnimation.top = frameY * linkAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && posLink.x < (MAP_WIDTH * TILE_WIDTH) - 17 && timer <= 0)
            {
                frameY = Right;
                if (!collisionMapPlayer(playerfrect, Right, speed))
                {
                    posLink.x += speed.x * GetDeltaTime();
                }
                linkAnimation.top = frameY * linkAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && posLink.x > 0 && timer <= 0)
            {
                frameY = Left;
                if (!collisionMapPlayer(playerfrect, Left, speed))
                {
                    posLink.x -= speed.x * GetDeltaTime();
                }
                linkAnimation.top = frameY * linkAnimation.height + frameY;
                hasMoved = sfTrue;
            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyZ) && timer <= 0)
            {
                frameY = RightTop;

                linkAnimation.top = frameY * linkAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyZ) && timer <= 0)
            {
                frameY = TopLeft;

                linkAnimation.top = frameY * linkAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyD) && sfKeyboard_isKeyPressed(sfKeyS) && timer <= 0)
            {
                frameY = DownLeft;

                linkAnimation.top = frameY * linkAnimation.height + frameY;

            }
            if (sfKeyboard_isKeyPressed(sfKeyQ) && sfKeyboard_isKeyPressed(sfKeyS) && timer <= 0)
            {
                frameY = DownRight;

                linkAnimation.top = frameY * linkAnimation.height + frameY;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyF) && timer <= 0)
        {
            isAttacking = 1;
            printf("%f", timer);
            system("cls");
            frameX = 0;
            if (timerattack <= 1)
            {

                linkAnimation.left = frameX * linkAnimation.height + 180;

            }
            else if (timerattack >= 2)
            {
                linkAnimation.left = frameX * linkAnimation.height + 180 + 49;
                if (timerattack > 3)
                {
                    timerattack = 0;
                    isAttacking = 0;
                }
            }
        }

        if (PlayerTimer > 0.3f)
        {
            if (hasMoved)
                frameX += compt;
            else
                frameX = 1;
            if (frameX == 2 || frameX == 0)
                compt *= -1;
            timer = 2;
            linkAnimation.left = frameX * linkAnimation.width + frameX;
            PlayerTimer = 0;
        }
        if (timer > 0)
        {
            timer -= 0.1;
            timerattack += 0.1;
        }

        sfSprite_setTextureRect(linkSprite, linkAnimation);
        sfSprite_setPosition(linkSprite, posLink);
    }
    //else if (state == EDITOR)
    //{

    //}
    //updateCamera(posLink, linkAnimation, _window);
}


void displayPlayer(sfRenderWindow* _window)
{

    sfRenderWindow_drawSprite(_window, linkSprite, NULL);
}
