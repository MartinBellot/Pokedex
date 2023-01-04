/*
** EPITECH PROJECT, 2023
** Texts
** File description:
** texts
*/

#include "app.h"

int text_destroy(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    return (0);
}

int text_update(text_t *text, app_t *app)
{
    sfRenderWindow_drawText(app->window, text->text, NULL);
    return (0);
}

text_t text_create(char *str, char *font_path,
int font_size, sfVector2f position, sfColor color)
{
    text_t txt;

    txt.text = sfText_create();
    txt.font = sfFont_createFromFile(font_path);
    txt.position = position;
    sfText_setPosition(txt.text, txt.position);
    sfText_setString(txt.text, str);
    sfText_setCharacterSize(txt.text, font_size);
    sfText_setFont(txt.text, txt.font);
    sfText_setColor(txt.text, color);
    return (txt);
}
