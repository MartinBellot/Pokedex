/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** A function that concatenates two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int length = my_strlen(dest);

    while (src[i] != '\0'){
        dest[length + i] = src[i];
        i++;
    }
    dest[length + i] = '\0';
    return dest;
}
