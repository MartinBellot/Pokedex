/*
** EPITECH PROJECT, 2022
** My apply on matching nodes
** File description:
** Apply function on all matching nodes.
*/

#include "mylist.h"
#include <stddef.h>

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        if (cmp(tmp->data, data_ref) == 0)
            f(tmp->data);
        tmp = tmp->next;
    }
    return (0);
}
