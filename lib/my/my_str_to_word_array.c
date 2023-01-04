/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** A function that splits into words
*/

#include <stddef.h>
#include <stdlib.h>

int my_putstr(char const *str);
int my_strlen(char const *str);
int my_show_word_array(char * const * tab);

int my_cols_counter(char const *str)
{
    int i = 0;
    int word = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++){
        word++;
    }
    return word;
}

static int count_lines(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            n++;
    }
    return (n);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count_lines(str) + 1));
    int cols = 0;
    int j = 0;

    for (; i < count_lines(str); i++){
        cols = 0;
        cols = my_cols_counter(str);
        array[i] = malloc(sizeof(char) * (cols + 1));
        array[i][cols] = '\0';
        for (; str[j] != '\n'; j++){
            array[i][k] = str[j];
            k++;
        }
        j++;
        k = 0;
    }
    array[count_lines(str)] = NULL;
    return (array);
}
