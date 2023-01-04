/*
** EPITECH PROJECT, 2023
** animation.c
** File description:
** contain all function for animation
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Cursor.h>

int anim_sprite (sfRenderWindow *window, int index)
{
    sfTexture *anim_texture = sfTexture_createFromFile("assets/artworks.png", NULL);
    sfSprite *anim = sfSprite_create();
    sfSprite_setTexture(anim, anim_texture, sfFalse);
    sfIntRect rect;
    sfClock *clock = sfClock_create();
    int i = 0;
    sfVector2f vector = {292, 234};

    rect.height = 128;
    rect.width = 128;
    sfSprite_move(anim, vector);
    index --;
    rect.left = 10 + index % 5 * 276;
    rect.top = 10 + (index - index % 5) / 5 * 138;
    while (5) {
        float time = sfClock_getElapsedTime(clock).microseconds / 1000000;
        if ( time > 0.5) {
            rect.left = 10 + index % 5 * 276;
            rect.top = 10 + (index - index % 5) / 5 * 138;
        }
        if (time > 1) {
            rect.left = 10 + index % 5 * 276 + 138;
            rect.top = 10 + (index - index % 5) / 5 * 138;
            i ++;
            sfClock_restart(clock);
        }
        if (i >= 4)
            break;
        sfSprite_setTextureRect(anim, rect);
        sfRenderWindow_drawSprite(window, anim, NULL);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
    sfSprite_destroy(anim);
}
