/*
** EPITECH PROJECT, 2022
** pokedex.c
** File description:
** pokedex creation
*/

#include "my.h"
#include "my_pokemon.h"

void game_events(game_t *game, button_t *but)
{
    reset_buttons(but);

    while (sfRenderWindow_pollEvent(game->window, &(game->event))){
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        detect_buttons(game, but);
    }
}
