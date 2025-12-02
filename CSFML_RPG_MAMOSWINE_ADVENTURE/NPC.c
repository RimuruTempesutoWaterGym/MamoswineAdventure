#include"NPC.h"
#include"player.h"


sfRectangleShape* rectangleDialog;
sfVector2f rectangleDialogSize = { 250.0f,200.0f };
sfTexture* textureTextBox;
sfFont* font;
sfText* dialogNPC;
sfSprite* spCynthia;
sfTexture* textureCynthia;
sfIntRect irecttextureTextBox = { 0,0,252,46 };
sfIntRect irectCynthia = { 0,0,26,38 };
sfVector2f cynthiaPos = { 1200.0f,900.0f };
sfVector2f textBoxPos = { 0.f,0.f };
sfVector2f dialogPos = { 20.0f,20.0f };
sfVector2f dialogSize = { 1.0f,3.0f };
float NpcTextTimer;
int isShown = 0;
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
    textureTextBox = sfTexture_createFromFile(TEXTURE_PATH"text_box.png", NULL);
    sfRectangleShape_setTexture(rectangleDialog, textureTextBox, sfTrue);
    sfRectangleShape_setTextureRect(rectangleDialog, irecttextureTextBox);
    dialogNPC = creationtexte(dialogNPC, "Afin d'ouvrir les portes du temps,\ntu dois rassembler les 4 clefs elementaires.\nTu devras te confronter a plusieurs enigmes !", dialogPos, sfBlack, 16);
    sfText_setScale(dialogNPC, dialogSize);
    font = sfFont_createFromFile("..\\Ressources\\Font\\PKMN-Mystery-Dungeon.ttf");
    sfText_setFont(dialogNPC, font);
}

void updateTextBox()
{
    if (state == GAME)
    {
        NpcTextTimer += GetDeltaTime();
        collisionNPC();
        sfRectangleShape_setPosition(rectangleDialog, textBoxPos);
        sfText_setPosition(dialogNPC, dialogPos);
    }
}

void displayNPC(sfRenderWindow* _window)
{
    if (state == GAME || state == EDITOR)
    {
        sfRenderWindow_drawSprite(_window, spCynthia, NULL);
    }
}
sfFloatRect GetCollisionOfNPC()
{
    sfFloatRect cynthiafrect = sfSprite_getGlobalBounds(spCynthia);

    return  cynthiafrect;

}
void displayTextBox(sfRenderWindow* _window)
{
    if (state == GAME)
    {
   
        if (isShown)
        {
            sfRenderWindow_drawRectangleShape(_window, rectangleDialog, NULL);
            sfRenderWindow_drawText(_window, dialogNPC, NULL);
        }
    }
}

void collisionNPC()
{
    sfFloatRect playerHitbox = getCollisionOfPlayer();
    playerHitbox.top += playerHitbox.height / 3;
    playerHitbox.height /= 1.3;
    playerHitbox.width /= 1.;
    
    sfFloatRect npcHitbox = GetCollisionOfNPC();
    npcHitbox.top += npcHitbox.height / 6;
    npcHitbox.height /= 1.2;
    if (isInsidePlayer(npcHitbox, playerHitbox) && sfKeyboard_isKeyPressed(sfKeyE) && NpcTextTimer >= 0.5f && isShown == 0)
    {

        if (isShown == 0)
        {
            isShown = 1;
        }
        NpcTextTimer = 0;
     }
    else if (sfKeyboard_isKeyPressed(sfKeyE) && NpcTextTimer >= 0.5f && isShown == 1)
    {
        isShown = 0;

        NpcTextTimer = 0;
    }
}
void setNPCPosition(sfVector2f newPos) {
    cynthiaPos = newPos;
    sfSprite_setPosition(spCynthia, cynthiaPos);
}