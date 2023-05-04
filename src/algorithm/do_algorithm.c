/*
** EPITECH PROJECT, 2022
** B-AIA-200-BAR-2-1-n4s-alba.candelario-matas
** File description:
** do_algorithm.c
*/

#include "lib.h"

void cond_max_vel(int i)
{
    if (i == 0)
        put_instruction(WHEELS_DIR, 0, true);
}

void car_speed(car_s *car)
{
    float velocity[6] = {1, 0.55, 0.45, 0.35, 0.25, 0};
    float distance[6] = {1500, 750, 500, 350, 250, 150};

    for (int i = 0; distance[i]; i++) {
        if (car->middle >= distance[i]) {
            cond_max_vel(i);
            car->speed = velocity[i];
            break;
        }
        if (car->middle < distance[5]) {
            car->speed = 0;
            break;
        }
    }
    if (car->speed != 0 && car->curr_speed != car->speed)
        put_instruction(CAR_FORWARD, car->speed, true);
}

void cond_backward(car_s *car)
{
    if (car->right > car->left)
        put_instruction(WHEELS_DIR, 1, true);
    else
        put_instruction(WHEELS_DIR, -1, true);
}

float car_backward(car_s *car)
{
    float prev_direcc = car->wheels;

    if (car->speed != 0)
        return (84);
    while (car->middle < 350) {
        if (car->wheels < 0)
            put_instruction(WHEELS_DIR, 1, true);
        if (car->wheels > 0)
            put_instruction(WHEELS_DIR, -1, true);
        if (car->wheels == 0)
            cond_backward(car);
        put_instruction(CAR_BACKWARDS, 0.5, true);
        get_info_lidar(car);
    }
    return (prev_direcc);
}
