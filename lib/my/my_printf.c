/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** little functions that we can use with
*/

#include <stdarg.h>
#include "my.h"

int my_put_float(float nb);

int flags(char c, int *i, va_list list, int n)
{
    if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == '%' || c == 'f')
        *i += 1;

    switch (c) {
    case 'c': n += my_putchar(va_arg(list, int)); break;
    case 's': n += my_putstr(va_arg(list, char *)); break;
    case 'i': n += my_put_nbr(va_arg(list, int)); break;
    case 'd': n += my_put_nbr(va_arg(list, int)); break;
    case 'f': n += my_put_float(va_arg(list, double)); break;
    case '%': n += my_putchar('%'); break;
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int n = 0;

    va_start(list, format);

    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%')
            flags(format[i + 1], &i, list, n);
        else {
            my_putchar(format[i]);
            n++;
        }
    }
    va_end(list);
    return n;
}
