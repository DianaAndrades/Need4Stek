/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-joan-pau.merida-ruiz
** File description:
** init_structs
*/

#include "lib.h"

car_s *init_car_struct(void)
{
    car_s *car = malloc(sizeof(car_s));

    if (car == NULL)
        return (NULL);
    car->status = NULL;
    car->end = false;
    car->left = -1;
    car->right = -1;
    car->middle = -1;
    car->resta = 0;
    car->wheels = -1;
    car->speed = -1;
    car->curr_speed = -1;
    return (car);
}
