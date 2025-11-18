#include"NPC.h"


sfSprite* spCynthia;
sfTexture* textureCynthia;
sfIntRect irectCynthia = { 0,0,26,38 };
sfVector2f cynthiaPos = { 500.0f,40.0f };

void initNPC()
{
    spCynthia = sfSprite_create();
    textureCynthia = sfTexture_createFromFile(TEXTURE_PATH"cynthia.png", NULL);
    sfSprite_setTexture(spCynthia, textureCynthia, sfTrue);
    sfSprite_setTextureRect(spCynthia, irectCynthia);
}

void update()
{
    if (sfKeyboard_isKeyPressed(sfKeyH))
    {
        printf("working\n");
    }
}

void displayNPC(sfRenderWindow* _window)
{
    sfRenderWindow_drawSprite(_window, spCynthia, NULL);
}
