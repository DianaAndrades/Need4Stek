/*
** EPITECH PROJECT, 2022
** MINISHELL_2
** File description:
** my_print_utils.c
*/

#include "lib.h"

void my_write(char *s, int i)
{
    write(i, s, my_strlen(s));
}

void my_print_array(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        write(2, arr[i], my_strlen(arr[i]));
        write(2, "\n", 1);
    }
}

void my_print_nb_str(float *str)
{
    for (int i = 0; str[i]; i++) {
        char buff[16];
        int len = sprintf(buff, "%.1f", str[i]);
        write(2, buff, len);
        write(2, "\n", 1);
    }
}

void print_nb(float nb)
{
    int len = 0;
    char buff[16];
    len = sprintf(buff, "%.1f", nb);
    write(2, buff, len);
    write(2, "\n", 1);
}
