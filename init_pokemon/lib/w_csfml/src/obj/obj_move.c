/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_move
*/
#include "../../include/w_csfml.h"

void obj_move(object_t *obj, sfVector2f move)
{
    sfSprite_move(obj->sprite, move);
    if (obj->hitbox_r)
        sfRectangleShape_move(obj->hitbox_r, move);
    if (obj->hitbox_c)
        sfCircleShape_move(obj->hitbox_c, move);
}

/* origin = origin's position of obj */
void obj_move_to(object_t *obj, w_clock_t *w_clock,
                sfVector2f origin, sfVector2f dest)
{
    sfVector2f actual_pos = sfSprite_getPosition(obj->sprite);
    if (fabs(actual_pos.x - obj->dep.x) >= fabs(obj->arr.x - obj->dep.x) &&
    fabs(actual_pos.y - obj->dep.y) >= fabs(obj->arr.y - obj->dep.y)) {
        obj->has_landed = TRUE;
        return;
    }
    float dx = dest.x - origin.x;
    float dy = dest.y - origin.y;
    int steps = (int)ceil(fmax(fabs(dx), fabs(dy)) / obj->speed);
    if (w_clock->second + (w_clock->minute * 60) >= obj->delay) {
        obj->has_took_off = TRUE;
        if (w_clock->microsecond > 999999) {
            sfVector2f displacement = (sfVector2f){dx / steps, dy / steps};
            obj_move(obj, displacement);
        }
    }
}
