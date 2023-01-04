/*
** EPITECH PROJECT, 2022
** src
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include "../lib/w_csfml/include/w_csfml.h"
    #include <string.h>

/* struct poke data */
typedef struct poke_data_s {
    char *pokedex_nb;
    char *name;
    char *japanese;
    char *type1;
    char *type2;
    char *classification;
    char *attack;
    char *defense;
    char *hp;
    char *sp_attack;
    char *sp_defense;
    char *speed;
    char *weight_kg;
    char *height_m;
    char *generation;
    char *is_legendary;

} poke_data_t;

/* parse_file */
char **parse_file(const char *file);

/* init_pokemons */
poke_data_t **init_pokemons(char **poke_info);

/* get_line_info */
char **get_line_info(char *line_info);
unsigned int count_element(char *line_info);

/* destroy_poke_data */
void destroy_poke_data(poke_data_t **poke_data);

#endif /* SRC_H_ */
