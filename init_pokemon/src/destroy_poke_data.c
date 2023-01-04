/*
** EPITECH PROJECT, 2022
** src
** File description:
** destroy_poke
*/
#include "src.h"

void destroy_poke_data(poke_data_t **poke_data)
{
    for (int i = 0; poke_data[i] != NULL; i++) {
        free(poke_data[i]->pokedex_nb);
        free(poke_data[i]->name);
        free(poke_data[i]->japanese);
        free(poke_data[i]->type1);
        free(poke_data[i]->type2);
        free(poke_data[i]->classification);
        free(poke_data[i]->attack);
        free(poke_data[i]->defense);
        free(poke_data[i]->sp_attack);
        free(poke_data[i]->sp_defense);
        free(poke_data[i]->speed);
        free(poke_data[i]->weight_kg);
        free(poke_data[i]->height_m);
        free(poke_data[i]->generation);
        free(poke_data[i]->is_legendary);
        free(poke_data[i]);
    }
    free (poke_data);
}