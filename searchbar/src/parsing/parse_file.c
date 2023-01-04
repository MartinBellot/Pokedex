/*
** EPITECH PROJECT, 2022
** src
** File description:
** parse_file
*/
#include "parsing.h"

char **parse_file(const char *file)
{
    if (!file)
        return (NULL);
    char *file_1d = file_to_str_getline(file);
    if (!file_1d)
        return (NULL);
    char **file_2d = str1d_to_str2d(file_1d);
    free (file_1d);
    if (!file_2d)
        return (NULL);
    return (file_2d);
}
