/*
** EPITECH PROJECT, 2023
** B-AIA-200-BAR-2-1-n4s-alba.candelario-matas [WSL: Ubuntu]
** File description:
** main
*/

#include "lib.h"

void print_laserscar(car_s *car)
{
    my_write("\n\n", 2);

    my_write("right----> ", 2);
    print_nb(car->right);

    my_write("middle----> ", 2);
    print_nb(car->middle);

    my_write("left----> ", 2);
    print_nb(car->left);

    my_write("resta----> ", 2);
    print_nb(car->resta);
}

char **put_instruction(char *instruct, float nb, int need__num)
{
    char *input = NULL;
    size_t size = 0;
    char **arr = NULL;

    write_instruction(instruct, nb, need__num);
    if (getline(&input, &size, stdin) == -1)
        return (NULL);
    input[strlen(input) - 1] = '\0';
    arr = my_get_array(input, ':');
    free(input);
    return (arr);
}

void get_info_lidar(car_s *car)
{
    char **arr = put_instruction(GET_INFO_LIDAR, -1, false);

    if (arr[35]) {
        car->right = atof(arr[34]);
        car->middle = atof(arr[16]);
        car->left = atof(arr[3]);
        car->resta = car->right - car->left;
        car->status = my_strdup(arr[35]);
        if (car->status && strcmp(car->status, "Track Cleared") == 0)
            car->end = true;
        print_laserscar(car);
    }
    free(arr);
}

void get_curr_wheels(car_s *car)
{
    char **arr = put_instruction(GET_CURRENT_WHEELS, -1, false);

    car->wheels = atof(arr[3]);
    my_write("whells---> ", 2);
    print_nb(car->wheels);
    free(arr);
}

void get_curr_speed(car_s *car)
{
    char **arr = put_instruction(GET_CURRENT_SPEED, -1, false);

    car->curr_speed = atof(arr[3]);
    free(arr);
}
