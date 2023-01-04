/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** A function that concatenates n characters of the src string in final dest
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int length = my_strlen(dest);

    while (i < nb){
        dest[length + i] = src[i];
        i++;
    }
    if (my_strlen(src) < nb){
        nb = my_strlen (src);
    }
    return dest;
}
