/*
** EPITECH PROJECT, 2023
** Utils functions
** File description:
** utils
*/

#include "app.h"

int rectangleshape_is_hover(sfRenderWindow *window,
sfRectangleShape *rectangle)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f rectpos = sfRectangleShape_getPosition(rectangle);

    if (mpos.x >= rectpos.x
    && mpos.x <= rectpos.x + sfRectangleShape_getSize(rectangle).x
    && mpos.y >= rectpos.y
    && mpos.y <= rectpos.y + sfRectangleShape_getSize(rectangle).y)
        return (1);
    return (0);
}
