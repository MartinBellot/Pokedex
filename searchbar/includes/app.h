/*
** EPITECH PROJECT, 2023
** App
** File description:
** app
*/

#ifndef APP_H_
#define APP_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "my.h"
    #include <stdlib.h>

typedef struct poke_data_s {
    char *name;
} poke_data_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    int font_size;
    sfColor color;
    sfVector2f position;
} text_t;

typedef struct textbox_s {
    int i_text;
    char *text;
    text_t text_display;
    sfRectangleShape *rect;
    sfSprite *icon;
    sfTexture *texture;
    int is_focus;
} textbox_t;

typedef struct search_element_s {
    sfRectangleShape *rect;
    text_t text;
} search_element_t;

typedef struct searchbar_s {
    textbox_t txtbox;
    search_element_t *elements;
} searchbar_t;

typedef struct app_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    searchbar_t searchbar;
    poke_data_t *pokemons;
} app_t;

int rectangleshape_is_hover(sfRenderWindow *window,
sfRectangleShape *rectangle);

text_t text_create(char *str, char *font_path,
int font_size, sfVector2f position, sfColor color);
int text_update(text_t *text, app_t *app);
int text_destroy(text_t *text);

textbox_t textbox_create(sfVector2f pos);
int textbox_update(textbox_t *txtbox, app_t *app);
int textbox_destroy(textbox_t *txtbox);
int textbox_events(textbox_t *txtbox, app_t *app);

searchbar_t searchbar_create(sfVector2f pos);
int searchbar_update(searchbar_t *searchbar, app_t *app);
int searchbar_destroy(searchbar_t *searchbar);
int searchbar_events(searchbar_t *searchbar, app_t *app);

app_t app_create(char *title, int width, int height, int fps_limit);
int app_update(app_t *app);
int app_destroy(app_t *app);
int app_isopen(app_t *app);
int app_events(app_t *app);

#endif /* !APP_H_ */
