/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** MY HUNTER
*/

#include "app.h"

int display_help(void)
{

    return (0);
}

int pokedex(void)
{
    app_t app = app_create("Pokedex - Searchbar", 1080, 720, 60);
    my_printf("[INFO] App created, run...\n");
    while (app_isopen(&app)) {
        app_events(&app);
        app_update(&app);
    }
    app_destroy(&app);
    return (0);
}

int main(void)
{
    pokedex();
    return (0);
}
