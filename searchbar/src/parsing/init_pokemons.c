/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_pokemon
*/
#include "parsing.h"

void init_pokemon(poke_data_t **poke_data, char **poke_info, int i)
{
    char **line_info = get_line_info(poke_info[i + 1]);
    poke_data[i]->pokedex_nb = my_strdup(line_info[0]);
    poke_data[i]->name = my_strdup(line_info[1]);
    poke_data[i]->japanese = my_strdup(line_info[2]);
    poke_data[i]->type1 = my_strdup(line_info[3]);
    poke_data[i]->type2 = my_strdup(line_info[4]);
    poke_data[i]->classification = my_strdup(line_info[5]);
    poke_data[i]->attack = my_strdup(line_info[6]);
    poke_data[i]->defense = my_strdup(line_info[7]);
    poke_data[i]->hp = my_strdup(line_info[8]);
    poke_data[i]->sp_attack = my_strdup(line_info[9]);
    poke_data[i]->sp_defense = my_strdup(line_info[10]);
    poke_data[i]->speed = my_strdup(line_info[11]);
    poke_data[i]->weight_kg = my_strdup(line_info[12]);
    poke_data[i]->height_m = my_strdup(line_info[13]);
    poke_data[i]->generation = my_strdup(line_info[14]);
    poke_data[i]->is_legendary = my_strdup(line_info[15]);
    free_array_str2d(line_info);
    return;
}

poke_data_t **init_pokemons(char **poke_info)
{
    int nb_poke = 151;
    int i = 0;
    if (!poke_info)
        return (NULL);
    poke_data_t **poke_data = malloc(sizeof(poke_data_t *) * (nb_poke + 1));
    while (i < nb_poke) {
        poke_data[i] = malloc(sizeof(poke_data_t));
        init_pokemon(poke_data, poke_info, i);
        i++;
    }
    poke_data[nb_poke] = NULL;
    return (poke_data);
}
