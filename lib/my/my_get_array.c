/*
** EPITECH PROJECT, 2023
** get_array
** File description:
** create arr of 2 dim given a separator
*/

#include "stdlib.h"

int my_strlen(char const *str);
int my_arrlen(char **str);
char *my_malloc_ini(int nb);

int get_max_col(char **map)
{
    int count = 0;
    int ret = my_strlen(map[count]);

    while (count < my_arrlen(map) - 1) {
        if (my_strlen(map[count]) < my_strlen(map[count + 1]))
            ret = my_strlen(map[count + 1]);
        count++;
    }
    return (ret);
}

int get_col_len(char *map_one_dim, int count_m, char separator)
{
    int len = 0;

    while (map_one_dim[count_m] != separator
    && map_one_dim[count_m] != '\0') {
        len++;
        count_m++;
    }
    return (len);
}

int get_rows(char *map_one_dim, char separator)
{
    int i = 0;
    int rows = 0;

    if (map_one_dim == NULL)
        return (0);
    while (map_one_dim[i]) {
        if ((map_one_dim[i] != separator && map_one_dim[i] != '\0')
        && (map_one_dim[i + 1] == separator || map_one_dim[i + 1] == '\0'))
            rows++;
        i++;
    }
    return (rows);
}

char **my_get_array(char *map_one_dim, char separator)
{
    int count_map = 0; int count_rows = 0; int count_col = 0;
    char **map = malloc(sizeof(char *) * (get_rows(map_one_dim,
    separator) + 1));
    while (count_rows < get_rows(map_one_dim, separator)) {
        while (map_one_dim[count_map] == separator ||
        map_one_dim[count_map] == '\0')
            count_map++;
        map[count_rows] = my_malloc_ini(get_col_len(map_one_dim,
        count_map, separator));
        while (map_one_dim[count_map] != separator
        && map_one_dim[count_map] != '\0') {
            map[count_rows][count_col] = map_one_dim[count_map];
            count_col++;
            count_map++;
        }
        count_rows++;
        count_col = 0;
    }
    map[count_rows] = NULL;
    return (map);
}
