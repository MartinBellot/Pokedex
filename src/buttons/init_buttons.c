/*
** EPITECH PROJECT, 2022
** init_buttons.c
** File description:
** init buttons
*/

#include "my.h"
#include "my_pokemon.h"

button_t init_buttons(void)
{
    button_t button;
    button.but_sounds = malloc(sizeof(int) * 10);
    button.but_change_pos = malloc(sizeof(int) * 4);

    for (int i = 0; i < 10; i++)
        button.but_sounds[i] = 0;
    for (int i = 0; i < 4; i++)
        button.but_change_pos[i] = 0;

    return button;
}
