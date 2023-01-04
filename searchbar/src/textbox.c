/*
** EPITECH PROJECT, 2023
** Search
** File description:
** SearchBAR
*/

#include "app.h"

int textbox_destroy(textbox_t *txtbox)
{
    free(txtbox->text);
    text_destroy(&txtbox->text_display);
    sfSprite_destroy(txtbox->icon);
    sfTexture_destroy(txtbox->texture);
    sfRectangleShape_destroy(txtbox->rect);
    return (0);
}

#include <stdio.h>

int textbox_events(textbox_t *txtbox, app_t *app)
{
    if (app->event.type == sfEvtTextEntered) {
        //printf("TEXT ENTERED ->\n");
        if (app->event.text.unicode < 128 && txtbox->is_focus) {
            if (app->event.text.unicode == 8 && txtbox->i_text >= 0) { // TOUCHE ESPACE
                txtbox->text[txtbox->i_text] = '\0';
                txtbox->i_text -= 1;
            } else {
                txtbox->i_text += 1;
                txtbox->text[txtbox->i_text] = app->event.text.unicode;
                txtbox->text[txtbox->i_text + 1] = '\0';
            }    
            //printf("Unicode valud: %d\n",app->event.text.unicode);
            //printf("%s\n", txtbox->text);
            sfText_setString(txtbox->text_display.text, txtbox->text);
        }
    }
    return (0);
}

int textbox_update(textbox_t *txtbox, app_t *app)
{
    if (rectangleshape_is_hover(app->window, txtbox->rect)) {
        sfRectangleShape_setFillColor(txtbox->rect, (sfColor){255, 240, 240, 255});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            txtbox->is_focus = 1;
    } else {
        sfRectangleShape_setFillColor(txtbox->rect, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            txtbox->is_focus = 0;
    }
    sfRenderWindow_drawRectangleShape(app->window, txtbox->rect, NULL);
    sfRenderWindow_drawSprite(app->window, txtbox->icon, NULL);
    text_update(&txtbox->text_display, app);


    return (0);
}

textbox_t textbox_create(sfVector2f pos)
{
    textbox_t txtbox;

    txtbox.text = malloc(sizeof(char) * 100);
    txtbox.i_text = -1;
    txtbox.text_display = text_create("", "assets/Consolas.ttf", 35, pos, sfBlack);

    txtbox.rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(txtbox.rect, pos);
    sfRectangleShape_setSize(txtbox.rect, (sfVector2f){400, 40});
    sfRectangleShape_setFillColor(txtbox.rect, sfWhite);

    txtbox.icon = sfSprite_create();
    txtbox.texture = sfTexture_createFromFile("assets/icon_search.png", NULL);
    sfSprite_setTexture(txtbox.icon, txtbox.texture, sfFalse);
    sfSprite_setScale(txtbox.icon, (sfVector2f){0.03, 0.03});
    sfSprite_setPosition(txtbox.icon, (sfVector2f){pos.x + 350, pos.y + 5});
    txtbox.is_focus = 0;
    return (txtbox);
}
