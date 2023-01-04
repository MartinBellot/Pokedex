/*
** EPITECH PROJECT, 2022
** My swap List
** File description:
** Swap two elements in list.
*/

#include "mylist.h"
#include <stddef.h>

static linked_list_t *get_final_list(linked_list_t **list,
int i, int j, void **tmp)
{
    linked_list_t *node = *list;
    linked_list_t *final_list;

    final_list = NULL;
    for (int k = 0; node != NULL; k++) {
        if (k == i)
            my_put_in_list(&final_list, tmp[1]);
        if (k == j)
            my_put_in_list(&final_list, tmp[0]);
        if (k != j && k != i)
            my_put_in_list(&final_list, node->data);
        node = node->next;
    }
    return (final_list);
}

int my_swap_list(linked_list_t **list, unsigned int i, unsigned int j)
{
    void *tmp[2];
    linked_list_t *final_list;
    linked_list_t *node = *list;

    if (my_list_size(*list) <= 1)
        return (0);
    final_list = NULL;
    for (int k = 0; node != NULL; k++) {
        if (k == (int)i)
            tmp[0] = node->data;
        if (k == (int)j)
            tmp[1] = node->data;
        node = node->next;
    }
    final_list = get_final_list(list, i, j, tmp);
    my_rev_list(&final_list);
    *list = final_list;
    return (0);
}
