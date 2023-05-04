/*
** EPITECH PROJECT, 2022
** B-PSU-100-BAR-1-1-myls-joan-pau.merida-ruiz
** File description:
** prototypes
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <unistd.h>
    #include "my.h"

    #define STOP_SIMULATION "STOP_SIMULATION\n"
    #define START_SIMULATION "START_SIMULATION\n"
    #define CAR_FORWARD "CAR_FORWARD:"
    #define CAR_BACKWARDS "CAR_BACKWARDS:"
    #define WHEELS_DIR "WHEELS_DIR:"
    #define GET_INFO_LIDAR "GET_INFO_LIDAR\n"
    #define GET_CURRENT_WHEELS "GET_CURRENT_WHEELS\n"
    #define GET_CURRENT_SPEED "GET_CURRENT_SPEED\n"

    // Structures
    typedef struct car_l {
        float right;
        float left;
        float middle;
        float resta;
        bool end;
        char *status;
        float wheels;
        float speed;
        float curr_speed;
    } car_s;

    // Structure Initialization
    car_s *init_car_struct(void);

    // Parsing
    void print_nb(float nb);
    void my_print_array(char **arr);
    void my_print_nb_str(float *str);
    void my_write(char *s, int i);
    char **put_instruction(char *instruct, float nb, int need__num);
    void write_instruction(char *s, float nb, int need__num);
    void get_info_lidar(car_s *car);
    void get_curr_wheels(car_s *car);
    void get_curr_speed(car_s *car);

    // Algorithm
    float car_backward(car_s *car);
    void car_speed(car_s *car);
    void car_wheels_direction(car_s *car, float prev_direcc);


#endif
