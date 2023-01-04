/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** Displays N if the integer passed as a parameter is - or P if its + or =
*/

void my_putchar(char c);

int my_isneg(int n)
{
    int N;
    int P;
    N = 78;
    P = 80;

    if (n >= 0){
        my_putchar(P);
    } else if (n < 0) {
        my_putchar(N);
    }
}
