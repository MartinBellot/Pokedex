/*
** EPITECH PROJECT, 2022
** handle_buttons.c
** File description:
** handle_buttons.c
*/

#include "my.h"
#include "my_pokemon.h"

void detect_change_button(button_t *but, sfVector2i pos)
{
    if (pos.x >= 429 && pos.x <= 447 &&
        pos.y >= 429 && pos.y <= 452)
        but->but_change_pos[0] = 1;
    if (pos.x >= 447 && pos.x <= 469 &&
        pos.y >= 452 && pos.y <= 469)
        but->but_change_pos[1] = 1;
    if (pos.x >= 430 && pos.x <= 448 &&
        pos.y >= 476 && pos.y <= 496)
        but->but_change_pos[2] = 1;
    if (pos.x >= 403 && pos.x <= 427 &&
        pos.y >= 427 && pos.y <= 470)
        but->but_change_pos[3] = 1;
}

void detect_animation_button(button_t *but, sfVector2i pos)
{
    if (pos.x >= 240 && pos.x <= 261 &&
        pos.y >= 423 && pos.y <= 451)
        but->but_animation = 1;
}

void detect_sound_buttons(button_t *but, sfVector2i pos)
{
    if (pos.x >= 590 && pos.x <= 618 &&
        pos.y >= 340 && pos.y <= 361)
        but->but_sounds[0] = 1;
    if (pos.x >= 624 && pos.x <= 653 &&
        pos.y >= 340 && pos.y <= 361)
        but->but_sounds[1] = 1;
    if (pos.x >= 658 && pos.x <= 686 &&
        pos.y >= 340 && pos.y <= 361)
        but->but_sounds[2] = 1;
    if (pos.x >= 692 && pos.x <= 721 &&
        pos.y >= 340 && pos.y <= 361)
        but->but_sounds[3] = 1;
    if (pos.x >= 726 && pos.x <= 755 &&
        pos.y >= 340 && pos.y <= 361)
        but->but_sounds[4] = 1;
}

void detect_buttons(game_t *game, button_t *but)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (game->event.type == sfEvtMouseButtonPressed){
        detect_change_button(but, pos);
        detect_animation_button(but, pos);
        detect_sound_buttons(but, pos);
    }
}

void reset_buttons(button_t *but)
{
    but->but_animation = 0;
    but->but_reseatch = 0;

    for (int i = 0; i < 10; i++)
        but->but_sounds[i] = 0;
    for (int i = 0; i < 4; i++)
        but->but_change_pos[i] = 0;
}
