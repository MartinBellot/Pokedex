/*
** EPITECH PROJECT, 2022
** My add in sorted list
** File description:
** Add element in sorted list.
*/

#include "mylist.h"
#include <stddef.h>

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *node = *begin;
    linked_list_t *list;
    int is_place = 0;

    list = NULL;
    while (node != NULL) {
        if (cmp(node->data, data) > 0 && is_place == 0) {
            my_put_in_list(&list, data);
            is_place = 1;
        }
        my_put_in_list(&list, node->data);
        node = node->next;
    }
    if (is_place == 0)
        my_put_in_list(&list, data);
    my_rev_list(&list);
    *begin = list;
}
