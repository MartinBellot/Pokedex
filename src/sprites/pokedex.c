/*
** EPITECH PROJECT, 2022
** pokedex.c
** File description:
** pokedex creation
*/

#include "my.h"
#include "my_pokemon.h"

void pokedex_update(pokedex_t *dex, game_t *game)
{
    sfRenderWindow_drawSprite(game->window, dex->sprite_pokedex, NULL);

    return;
}

pokedex_t create_pokedex(char *path)
{
    pokedex_t poke;
    sfVector2f pos = {200, 100};
    poke.texture_pokedex = sfTexture_createFromFile(path, NULL);
    poke.sprite_pokedex = sfSprite_create();

    sfSprite_setTexture(poke.sprite_pokedex, poke.texture_pokedex, sfTrue);
    sfSprite_setPosition(poke.sprite_pokedex, pos);

    return poke;
}
