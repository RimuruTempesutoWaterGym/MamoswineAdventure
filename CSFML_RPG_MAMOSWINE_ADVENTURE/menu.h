#include "tools.h"


void initmenu();
void updatemenu(sfRenderWindow* _window);
void displaymenu(sfRenderWindow* _window);

typedef enum {
	NEUTRE, VALIDE,
}Coche;
Coche coche;
