/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** returns the first argument raised to the power p
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;
    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    if (p > 0)
        res = nb * my_compute_power_rec(nb, p - 1);
    return res;
}
