/*
** EPITECH PROJECT, 2022
** B-AIA-200-BAR-2-1-n4s-alba.candelario-matas
** File description:
** insert_cmd.c
*/

#include "lib.h"

char *concat_cmd(char *s, float nb)
{
    char s_num[16];
    int nb_size = sprintf(s_num, "%.1f", nb);
    s_num[nb_size] = '\0';
    char *new_s = malloc(sizeof(char *) * (strlen(s) + nb_size + 2));
    int i = strlen(s);
    strcpy(new_s, s);
    for (int a = 0; s_num[a]; a++, i++)
        new_s[i] = s_num[a];
    new_s[i++] = '\n';
    new_s[i] = '\0';
    return (new_s);
}

void write_instruction(char *s, float nb, int need__num)
{
    if (need__num == true) {
        char *new_s = concat_cmd(s, nb);
        my_write(new_s, 1);
        my_write(new_s, 2);
    } else {
        my_write(s, 1);
        my_write(s, 2);
    }
}
