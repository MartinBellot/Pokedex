/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** returns the square root of the number given as argument
*/

int my_compute_square_root(int nb)
{
    int i;
    int nb2 = 1;

    if (nb <= 0)
        return 0;
    if (nb == 1)
        return (1);
    while (i < nb){
        nb2++;
        i = nb2 * nb2;
    }
    if (i > nb)
    return (0);
    return (nb2);
}
