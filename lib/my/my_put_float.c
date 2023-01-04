/*
** EPITECH PROJECT, 2022
** My print float
** File description:
** Print FLOATS
*/

#include "my.h"

int my_count_digits(int nb)
{
    int n = 0;

    while (nb > 0) {
        n++;
        nb = nb / 10;
    }
    return (n);
}

int round_value(float nb)
{
    int n = nb;
    float decimal_part = (nb - n) * 101;
    int n2 = decimal_part;

    if (n2 >= 51)
        return (n + 1);
    return (n);
}

int my_put_float_long(double nb, int nb_after_comma)
{
    double decimal_part;
    int n = 0;

    if (nb_after_comma == 0) {
        n += my_put_nbr(round_value(nb));
        return (n);
    }
    n += my_put_nbr((int)nb);
    decimal_part = (nb - (int)nb);
    for (int i = 0; i < nb_after_comma; i++)
        decimal_part *= 10;
    n += my_putchar('.');
    n += my_put_nbr(round_value(decimal_part));
    for (int i = 0; i < nb_after_comma
    - my_count_digits(decimal_part); i++)
        n += my_putchar('0');
    return (0);
}

int my_put_float(float nb)
{
    int nb_after_comma = 2;
    float decimal_part = 0;
    int n = 0;

    if (nb_after_comma == 0) {
        n += my_put_nbr(round_value(nb));
        return (n);
    }
    n += my_put_nbr((int)nb);
    decimal_part = (nb - (int)nb);
    for (int i = 0; i < nb_after_comma; i++)
        decimal_part *= 10;
    n += my_putchar('.');
    n += my_put_nbr(round_value(decimal_part));
    for (int i = 0; i < nb_after_comma
    - my_count_digits(decimal_part); i++)
        n += my_putchar('0');
    return (n);
}
