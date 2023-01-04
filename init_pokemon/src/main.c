/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"

int main(int ac, char **av)
{
    /* init poke_data :*/
    if (ac != 2)
        return (84);
    char **poke_info = parse_file(av[1]);
    if (!poke_info)
        return (0);
    poke_data_t **poke_data = init_pokemons(poke_info);
    free_array_str2d(poke_info);
    /*******************/

    /**use poke data**/

    /**destroy_poke_data**/
    destroy_poke_data(poke_data);
    /***************************/
    return (0);
}
