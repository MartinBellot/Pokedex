/*
** EPITECH PROJECT, 2022
** My str UPCASE
** File description:
** Puts every letter in uppercase
*/

char *my_strdup(char const *src);

int is_digit_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

char *my_strupcase(char *str)
{
    char *nstr = my_strdup(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_digit_lowercase(str[i]))
            nstr[i] -= 32;
    }
    return (nstr);
}
