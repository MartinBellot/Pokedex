/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "my.h"
#include "my_pokemon.h"
#include <string.h>

int get_score(long score)
{
    int n = 0;

    while (score > 0) {
        score = score / 10;
        n++;
    }
    return n;
}

char *transform_score_to_text(int score)
{
    int number = 0;
    int num = get_score(score);
    char *str = malloc(sizeof(char) * (num+ 1));
    int i = 0;

    str[num] = '\0';
    if (score < 0) {
        str[i] = '-';
        score = score * -1;
        i++;
    }
    for (; score > 0; num--) {
        number = score % 10;
        str[num - 1] = (number + 48);
        score = score / 10;
    }
    return str;
}

void dec_path(char *nb_pokemon, char *dec, char *ogg, char *result)
{
    my_strcat(dec, nb_pokemon);
    my_strcat(dec, ogg);
    my_strcat(result, dec);
    my_printf("%s\n", result);
}

void cents_path(char *nb_pokemon, char *num, char *ogg, char *result)
{
    my_strcat(num, nb_pokemon);
    my_strcat(num, ogg);
    my_strcat(result, num);
    my_printf("%s\n", result);
}

music_t generate_sound(char *nb_pokemon, music_t mus)
{
    int nbr_pokemon = my_getnbr(nb_pokemon);
    char result[16] = "pokemon";
    char unit[16] = "00";
    char dec[16] = "0";
    char ogg[16] = ".ogg";
    char num[16] = "";

    if (nbr_pokemon > 999)
        return mus;
    if (nbr_pokemon < 10){
        my_strcat(unit, nb_pokemon);
        my_strcat(unit, ogg);
        my_strcat(result, unit);
        my_printf("%s\n", result);
    }
    if (nbr_pokemon > 9 && nbr_pokemon < 100){
        dec_path(nb_pokemon, dec, ogg, result);
    }
    if (nbr_pokemon > 99){
        cents_path(nb_pokemon, num, ogg, result);
    }
    return mus;
}
