/*
** EPITECH PROJECT, 2022
** App
** File description:
** App gestion
*/

#include "app.h"

int app_destroy(app_t *app)
{
    searchbar_destroy(&app->searchbar);
    sfRenderWindow_destroy(app->window);
    free(app->pokemons);
    return (0);
}

int app_isopen(app_t *app)
{
    if (sfRenderWindow_isOpen(app->window))
        return (1);
    return (0);
}

int app_events(app_t *app)
{
    while (sfRenderWindow_pollEvent(app->window, &app->event)) {
        if (app->event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        searchbar_events(&app->searchbar, app);
    }
    return (0);
}

int app_update(app_t *app)
{
    sfRenderWindow_clear(app->window, sfBlack);

    searchbar_update(&app->searchbar, app);

    sfRenderWindow_display(app->window);
    return (0);
}

app_t app_create(char *title, int width, int height, int fps_limit)
{
    app_t app;

    my_printf("-------BUILD LOGS-------\n");
    app.mode = (sfVideoMode){width, height, 32};
    app.window = sfRenderWindow_create(app.mode,
    title, sfClose | sfResize, NULL);
    sfRenderWindow_setPosition(app.window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(app.window, fps_limit);
    sfRenderWindow_setTitle(app.window, title);
    my_printf("[BUILD] create Player.\n");
    app.searchbar = searchbar_create((sfVector2f){50, 30});



    char **poke_info = parse_file("pokemons.csv");
    //poke_data_t **poke_data = init_pokemons(poke_info);
    app.pokemons = init_pokemons(poke_info);
    free_array_str2d(poke_info);

    my_printf("-> %s\n", app.pokemons[1]->name);

    //for (int i = 0; i < 3; i++) {
      //  my_printf("POkE[%d] = %s\n", i, app.pokemons[i]);
    //}
    //free(app.pokemons);
    return (app);
}
