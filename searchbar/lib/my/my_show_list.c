/*
** EPITECH PROJECT, 2022
** My show list
** File description:
** Show list
*/

#include "my.h"
#include <stddef.h>

int my_show_list(linked_list_t *list)
{
    linked_list_t *node = list;

    while (node != NULL) {
        my_putstr(node->data);
        node = node->next;
    }
    return (0);
}
