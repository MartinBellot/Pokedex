/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** A function that allocates memory and copie the string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0'){
        str[i] = src[i];
        i++;
    }
    return str;
}
