/*
** EPITECH PROJECT, 2022
** concat_params.c
** File description:
** A function that turns the cmd argumentds into a single string
*/

#include <stdlib.h>

int my_putstr(char const *str);

void my_putchar(char c);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

int my_counter(int argc, char **argv)
{
    int i = 0;
    int n = 0;

    while (argv[i] != NULL){
        n = n + my_strlen(argv[i]);
        i++;
    } return n;
}

char *concat_params(int argc, char**argv)
{
    int i = 0;
    int j = 0;
    char *result;
    int size = my_counter(argc, argv);
    char *str = malloc(sizeof(char) * (size + argc));

    while (argv[i] != NULL){
        result = my_strcat(str, argv[i]);
        my_strcat(str, "\n");
        i++;
    } return str;
}
