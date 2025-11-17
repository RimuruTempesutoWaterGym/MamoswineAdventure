#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.h"


int main()
{
    sfVideoMode mode = { 800,600,32 };
    sfRenderWindow* window = sfRenderWindow_create(mode, "Titre", sfResize | sfClose, NULL);
    sfEvent events;


    //initTools();




    while (sfRenderWindow_isOpen(window))
    {
      //  restartClock();
        while (sfRenderWindow_pollEvent(window, &events))
        {
            if (events.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }

        }





        sfRenderWindow_clear(window, sfBlack);



        sfRenderWindow_display(window);
    }
}