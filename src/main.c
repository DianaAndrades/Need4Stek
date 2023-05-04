/*
** EPITECH PROJECT, 2023
** B-AIA-200-BAR-2-1-n4s-alba.candelario-matas [WSL: Ubuntu]
** File description:
** main
*/

#include "lib.h"

int do_game_loop(car_s *car)
{
    put_instruction(START_SIMULATION, -1, false);
    put_instruction(WHEELS_DIR, 0.3, true);
    put_instruction(CAR_FORWARD, 0.2, true);
    get_info_lidar(car);

    while (car->end == false) {
        car_speed(car);
        car_wheels_direction(car, car_backward(car));
        get_info_lidar(car);
        get_curr_speed(car);
        get_curr_wheels(car);
    }
    put_instruction(STOP_SIMULATION, -1, false);
    return (0);
}

int main(int ac, char **av)
{
    car_s *car = init_car_struct();

    return (do_game_loop(car));
}
