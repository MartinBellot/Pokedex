/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** Swaps the content of 2 int, whose addresses are given as a prmtr
*/

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
