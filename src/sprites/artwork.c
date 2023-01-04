/*
** EPITECH PROJECT, 2023
** artwork
** File description:
** Display the artwork of the selected pokemon
*/

#include <SFML/Graphics.h>

void display_artwork(int index, sfRenderWindow *window)
{
    int pos[2];
    sfIntRect rect = {0, 0, 128, 128};
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vector = {292, 234};

    index--;
    pos[0] = 10 + index % 5 * 276;
    pos[1] = 10 + (index - index % 5) / 5 * 138;
    rect.left = pos[0];
    rect.top = pos[1];
    texture = sfTexture_createFromFile("assets/artworks.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_move(sprite, vector);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
