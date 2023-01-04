/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "my.h"
#include "my_pokemon.h"
#include <string.h>

void game_update(game_t *game, int index)
{
    sfRenderWindow_clear(game->window, sfWhite);

    pokedex_update(&game->dex, game, index);

    sfRenderWindow_display(game->window);
}

game_t create_game(char *title)
{
    game_t game;

    game.button = init_buttons();
    game.mode = (sfVideoMode){WIDTH, HEIGHT, 32};
    game.dex = create_pokedex("./assets/Pokedex.png");
    game.window = sfRenderWindow_create(game.mode, title , sfClose, NULL);

    return game;
}

int main(void)
{
    game_t game = create_game("My_pokemon");
    int index = 1;

    while (sfRenderWindow_isOpen(game.window)){
        sfRenderWindow_setFramerateLimit(game.window, 60);
        game_events(&game, &game.button);
        game_update(&game, index);
    }

    free(game.button.but_sounds);
    free(game.button.but_change_pos);
    return (0);
}
