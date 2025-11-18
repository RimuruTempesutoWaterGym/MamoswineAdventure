#include"NPC.h"


sfSprite* spCynthia;
sfTexture* texCynthia;
sfIntRect irectCynthia = { 0,0,24,38 };
sfVector2f cynthiaPos = { 100, 100 };

void initNPC()
{
    spCynthia = sfSprite_create();
    texCynthia = sfTexture_createFromFile(TEXTURE_PATH"cynthia.png", NULL);
    sfSprite_setTexture(spCynthia, texCynthia, sfTrue);
    sfSprite_setTextureRect(spCynthia, irectCynthia);
}

void update()
{
    if (sfKeyboard_isKeyPressed(sfKeyH))
    {
        printf("working\n");
    }
}
