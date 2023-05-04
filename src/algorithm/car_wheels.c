/*
** EPITECH PROJECT, 2023
** car_wheels
** File description:
** function utils to manage car wheel's direction
*/

#include "lib.h"

int check_prev_dir(car_s *car, float prev_direcc)
{
    if (prev_direcc != 84) {
        if (prev_direcc < 0) {
            put_instruction(WHEELS_DIR, -1, true);
            return 1;
        }
        if (prev_direcc > 0) {
            put_instruction(WHEELS_DIR, 1, true);
            return 1;
        }
        if (car->right > car->left)
            put_instruction(WHEELS_DIR, -1, true);
        else
            put_instruction(WHEELS_DIR, 1, true);
        car_speed(car);
        return 1;
    }
    return (0);
}

void car_wheels_direction(car_s *car, float prev_direcc)
{
    float direction[4] = {0.3, 0.25, 0.2, 0.1};
    float distance[4] = {400, 320, 280, 250};

    if (check_prev_dir(car, prev_direcc) == 1)
        return;
    for (int i = 0; i < 4; i++) {
        if (car->middle >= 600 && car->wheels != 0) {
            put_instruction(WHEELS_DIR, 0, true);
            return;
        }
        if (car->right < car->left && car->resta <= (-1) * distance[i]) {
            put_instruction(WHEELS_DIR, direction[i], true);
            return;
        }
        if (car->right > car->left && car->resta >= distance[i]) {
            put_instruction(WHEELS_DIR, (-1) * direction[i], true);
            return;
        }
    }
    put_instruction(WHEELS_DIR, 0.0, true);
}
