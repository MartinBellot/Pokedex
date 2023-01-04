/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** Displays a character of a string 1 by 1
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
