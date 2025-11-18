#include"NPC.h"


sfRectangleShape* rectangleDialog;
sfVector2f rectangleDialogPos = { 2.0f,30.0f };
sfVector2f rectangleDialogSize = { 25.0f,4.6f };
sfTexture* textureTextBox;
sfFont* font;
sfText* dialogNPC;
sfSprite* spCynthia;
sfTexture* textureCynthia;
sfIntRect irectTextBox = { 0,0,178,60 };
sfIntRect irectCynthia = { 0,0,26,38 };
sfVector2f cynthiaPos = { 500.0f,40.0f };
sfVector2f dialogPos = { 2.0f,30.0f };

void initNPC()
{        
    dialogNPC = sfText_create();
    spCynthia = sfSprite_create();
    textureCynthia = sfTexture_createFromFile(TEXTURE_PATH"cynthia.png", NULL);
    sfSprite_setTexture(spCynthia, textureCynthia, sfTrue);
    sfSprite_setTextureRect(spCynthia, irectCynthia);

    rectangleDialog = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangleDialog, rectangleDialogSize);
    sfRectangleShape_setPosition(rectangleDialog, rectangleDialogPos);
    textureTextBox = sfTexture_createFromFile("..\\Ressources\\Textures\\text_box.png", NULL);
    sfRectangleShape_setTexture(rectangleDialog, textureTextBox, sfTrue);
}

void updateNPC()
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && state == GAME)
    {
        sfText_setString(dialogNPC, "working");
        sfText_setPosition(dialogNPC, dialogPos);
        font = sfFont_createFromFile("..\\Ressources\\Font\\Minecraft.ttf");
        sfText_setFont(dialogNPC, font);
    }
}

void displayNPC(sfRenderWindow* _window)
{
    sfRenderWindow_drawRectangleShape(_window, rectangleDialog, NULL);
    sfRenderWindow_drawSprite(_window, spCynthia, NULL);
    sfRenderWindow_drawText(_window, dialogNPC, NULL);
}
