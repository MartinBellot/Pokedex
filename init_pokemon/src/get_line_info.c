/*
** EPITECH PROJECT, 2022
** src
** File description:
** get_line_info
*/
#include "src.h"

unsigned int count_element(char *line_info)
{
    unsigned count = 0;
    int has_changed = FALSE;
    for (int i = 0; line_info[i] != '\0'; i++) {
        if (line_info[i] == ';')
            has_changed = TRUE;
        if (has_changed == TRUE && line_info[i] != ';') {
            count++;
            has_changed = FALSE;
        }
    }
    return (count);
}

unsigned int word_size_str(char *line_info)
{
    unsigned int i = 0;
    while (line_info[i] != ';' && line_info[i] != '\0')
        i++;
    return (i);
}

void fill_array_info(char **info, int j, char *line_info, int *i)
{
    int k = 0;
    info[j] = malloc(sizeof(char) * (word_size_str(&(line_info[*i])) + 1));
    while (line_info[*i] != '\0' && line_info[*i] != ';') {
        info[j][k] = line_info[*i];
        k++;
        (*i)++;
    }
    info[j][k] = '\0';
}

char **get_line_info(char *line_info)
{
    int i = 0;
    int j = 0;
    char **info = malloc(sizeof(char *) * (17));
    while (line_info[i] != '\0') {
        if (line_info[i] != ';') {
            fill_array_info(info, j, line_info, &i);
            j++;
        }
        while (line_info[i] != '\0' && line_info[i] == ';') {
            if (line_info[i] == ';' && line_info[i + 1] == ';') {
            info[j] = my_strdup("N/A");
            j++;
        }
            i++;
        }
    }
    info[16] = NULL;
    return (info);
}
