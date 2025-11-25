#include"NPC.h"


sfRectangleShape* rectangleDialog;
sfVector2f rectangleDialogSize = { 250.0f,46.0f };
sfTexture* textureTextBox;
sfFont* font;
sfText* dialogNPC;
sfSprite* spCynthia;
sfTexture* textureCynthia;
sfIntRect irecttextureTextBox = { 0,0,252,46 };
sfIntRect irectCynthia = { 0,0,26,38 };
sfVector2f cynthiaPos = { 20.0f,30.0f };
sfVector2f textBoxPos = { 20.0f,20.0f };
sfVector2f dialogPos = { 28.0f,20.0f };
sfVector2f dialogSize = { 0.7f,0.7f };

void initNPC()
{
    dialogNPC = sfText_create();
    spCynthia = sfSprite_create();
    textureCynthia = sfTexture_createFromFile(TEXTURE_PATH"cynthia.png", NULL);
    sfSprite_setTexture(spCynthia, textureCynthia, sfTrue);
    sfSprite_setPosition(spCynthia, cynthiaPos);
    sfSprite_setTextureRect(spCynthia, irectCynthia);
}
void initTextBox()
{
    rectangleDialog = sfRectangleShape_create();
    sfRectangleShape_setSize(rectangleDialog, rectangleDialogSize);
    textureTextBox = sfTexture_createFromFile("..\\Ressources\\Textures\\text_box.png", NULL);
    sfRectangleShape_setTexture(rectangleDialog, textureTextBox, sfTrue);
    sfRectangleShape_setTextureRect(rectangleDialog, irecttextureTextBox);
    font = sfFont_createFromFile("..\\Ressources\\Font\\PKMN-Mystery-Dungeon.ttf");
    sfText_setColor(dialogNPC, sfBlack);
    sfText_setString(dialogNPC, "working\nyes it is");
    sfText_setScale(dialogNPC, dialogSize);
    sfText_setFont(dialogNPC, font);

}

void updateTextBox()
{
    if (state == GAME)
    {
    }
}

void displayNPC(sfRenderWindow* _window)
{
    if (state == GAME)
    {
        sfRenderWindow_drawSprite(_window, spCynthia, NULL);
    }
}

void displayTextBox(sfRenderWindow* _window, sfVector2f playerPos, sfIntRect playerHitbox)
{
    if (state == GAME)
    {
        sfRectangleShape_setPosition(rectangleDialog, textBoxPos);
        sfText_setPosition(dialogNPC, dialogPos);
        sfRenderWindow_drawRectangleShape(_window, rectangleDialog, NULL);
        sfRenderWindow_drawText(_window, dialogNPC, NULL);
    }
}

sfBool collisionNPC(sfVector2f _playerPos)
{
    sfBool collision = sfFalse;
    sfFloatRect cynthiafrect = sfSprite_getGlobalBounds(spCynthia);
    if (isInsideMouse(_playerPos, cynthiafrect))
    {
        collision = sfTrue;
        return collision;
    }
    return collision;
}
