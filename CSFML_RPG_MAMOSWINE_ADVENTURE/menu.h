#include "tools.h"


void initmenu();
void updatemenu(sfRenderWindow* _window);
void displaymenu(sfRenderWindow* _window);

typedef enum {
	NEUTRE, VALIDE,
}Coche;
Coche coche;

typedef enum {
	INGAME, PRINCIPAL,EDITING
}TypeMenu;
TypeMenu typemenu;

sfRectangleShape* creationboutton(sfRectangleShape* _nombouton, sfVector2f _taille, sfVector2f _position, sfIntRect _irect, sfTexture* _texture);

sfText* creationtexte(sfText* _text, const char* _string,sfVector2f _position, sfColor _couleur, unsigned int _size);

