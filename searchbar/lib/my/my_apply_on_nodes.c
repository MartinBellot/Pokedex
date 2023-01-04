/*
** EPITECH PROJECT, 2022
** My apply on nodes
** File description:
** Apply function on all nodes.
*/

#include "mylist.h"
#include <stddef.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        f(tmp->data);
        tmp = tmp->next;
    }
    return (0);
}
