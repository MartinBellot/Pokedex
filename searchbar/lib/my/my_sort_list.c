/*
** EPITECH PROJECT, 2022
** Sort in ascending order with cmp function.
** File description:
** Sort linked lists.
*/

#include "mylist.h"
#include <stddef.h>

static int compare_and_swap(linked_list_t *node,
linked_list_t *temp, int (*cmp)())
{
    void *m;

    if (cmp(node->data, temp->data) > 0) {
        m = node->data;
        node->data = temp->data;
        temp->data = m;
    }
    return (0);
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *node = *begin;
    linked_list_t *temp = NULL;

    while (node != NULL) {
        temp = node->next;
        while (temp != NULL) {
            compare_and_swap(node, temp, cmp);
            temp = temp->next;
        }
        node = node->next;
    }
}
