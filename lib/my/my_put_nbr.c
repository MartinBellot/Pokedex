/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my put numbr
*/

int my_putchar(char c);
int my_putstr(char const *str);

int my_put_nbr(int nb)
{
    int number = 1;
    int n = 0;

    if (nb == -2147483648){
        my_putstr("-2147483648");
    } else{
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        while ((nb / number) >= 10){
            number = number * 10;
        }
        while (number > 0){
            my_putchar((nb / number) % 10 + '0');
            number = number / 10;
            n++;
        }
    }
    return n;
}
