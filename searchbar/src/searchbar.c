/*
** EPITECH PROJECT, 2023
** SearchBar
** File description:
** Search Bar
*/

#include "app.h"
#include <stdio.h>

int searchbar_destroy(searchbar_t *searchbar)
{
    for (int i = 0; i < 9; i++) {
        sfRectangleShape_destroy(searchbar->elements[i].rect);
        text_destroy(&searchbar->elements[i].text);
    }
    textbox_destroy(&searchbar->txtbox);
    free(searchbar->elements);
    return (0);
}

int searchbar_events(searchbar_t *searchbar, app_t *app)
{

    textbox_events(&searchbar->txtbox, app);


    return (0);
}

int is_in_array(char **array, int size, char *str)
{
    for (int i = 0; i < size; i++) {
        if (my_strcmp(array[i], str) == 0)
            return (1);
    }
    return (0);
}

int text_in_word(char *text, char *word)
{
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == text[j])
            j += 1;
        else 
            j = 0;
        if (j == my_strlen(text))
            return (1);
    }
    return (0);
}

int find_elements(char *text, app_t *app, searchbar_t *searchbar)
{
    char **array = malloc(sizeof(char *) * 100);
    int n = 0;
    char *text_nonsensitive;
    char *pokemon_nonsensitive;

    for (int i = 0; i < 3; i++) {
        text_nonsensitive = my_strupcase(text);
        pokemon_nonsensitive = my_strupcase(text);
        if (text_in_word(my_strupcase(text), my_strupcase(app->pokemons[i].name)) && my_strlen(text) > 1) {
            if (is_in_array(array, n, app->pokemons[i].name) == 0) {
                array[n] = my_strdup(app->pokemons[i].name);
                n += 1;
            }
        }
        free(text_nonsensitive);
        free(pokemon_nonsensitive);
    }
    array[n] = NULL;
    for (int i = 0; i < 9; i++) {
        if (i < n)
            sfText_setString(searchbar->elements[i].text.text, array[i]);
        else
            sfText_setString(searchbar->elements[i].text.text, "none");

    }
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return (0);
}

int searchbar_update(searchbar_t *searchbar, app_t *app)
{
    if (searchbar->txtbox.is_focus) {
        for (int i = 0; i < 9; i++) {
            if (my_strcmp(sfText_getString(searchbar->elements[i].text.text), "none") != 0) {
                sfRenderWindow_drawRectangleShape(app->window, searchbar->elements[i].rect, NULL);
                text_update(&searchbar->elements[i].text, app);
            }
        }
        find_elements(searchbar->txtbox.text, app, searchbar);
    }
    textbox_update(&searchbar->txtbox, app);

    return (0);
}

searchbar_t searchbar_create(sfVector2f pos)
{
    searchbar_t searchbar;

    searchbar.txtbox = textbox_create(pos);
    searchbar.elements = malloc(sizeof(search_element_t) * 10);

    sfVector2f elem_pos = {pos.x, pos.y + 45};
    for (int i = 0; i < 9; i++) {
        searchbar.elements[i].rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(searchbar.elements[i].rect, elem_pos);
        sfRectangleShape_setSize(searchbar.elements[i].rect, (sfVector2f){400, 40});
        sfRectangleShape_setFillColor(searchbar.elements[i].rect, sfWhite);
        searchbar.elements[i].text = text_create("none", "assets/Consolas.ttf", 32, elem_pos, sfBlack);
        elem_pos.y += 45;
    }
    return (searchbar);
}