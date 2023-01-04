/*
** EPITECH PROJECT, 2022
** My rev list
** File description:
** Reverse list
*/

#include "mylist.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;
    linked_list_t *list;

    list = NULL;
    while (tmp != NULL) {
        my_put_in_list(&list, tmp->data);
        tmp = tmp->next;
    }
    *begin = list;
}
