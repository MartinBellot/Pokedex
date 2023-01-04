/*
** EPITECH PROJECT, 2022
** structure of my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H
    #define MY_RADAR_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define WIDTH 1080
    #define HEIGHT 720
    #define uint unsigned int

typedef struct buttons_s {

    int *but_sounds;
    int *but_change_pos;
    int but_animation;
    int but_reseatch;

} button_t;

typedef struct pokedex_s {

    sfTexture *texture_pokedex;
    sfSprite *sprite_pokedex;

} pokedex_t;

typedef struct game_s {

    sfVector2f pos;
    sfClock *movement_clock;
    sfClock *clock;
    sfClock *tm_clock;
    sfClock *scs_clock;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;

    pokedex_t dex;
    button_t button;

} game_t;


/*----------------[POKEDEX]----------------*/
pokedex_t create_pokedex(char *path);
void pokedex_update(pokedex_t *dex, game_t *game, int index);
void display_artwork(int index, sfRenderWindow *window);
int anim_sprite (sfRenderWindow *window, int index);

/*----------------[EVENTS]----------------*/
void game_events(game_t *game, button_t *but);

/*----------------[BUTTONS]----------------*/
button_t init_buttons(void);
void detect_change_button(button_t *but, sfVector2i pos);
void detect_animation_button(button_t *but, sfVector2i pos);
void detect_sound_buttons(button_t *but, sfVector2i pos);
void detect_buttons(game_t *game, button_t *but);
void reset_buttons(button_t *but);

#endif /* MY_RADAR_H */
