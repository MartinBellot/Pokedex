/*
** EPITECH PROJECT, 2022
** My params to list
** File description:
** Create list from command line arguments.
*/

#include "mylist.h"
#include <stddef.h>

int my_put_in_list(linked_list_t **list, void *data);

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;

    list = NULL;
    for (int i = 0; i < ac; i++)
        my_put_in_list(&list, av[i]);
    return (list);
}
