/*
** EPITECH PROJECT, 2022
** unit_tests
** File description:
** test the program
*/

#include "lib.h"
#include <criterion/criterion.h>
#include <criterion/types.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//////////////////////////////////////////////////////////////
///////////////          strlen_suite          ///////////////
//////////////////////////////////////////////////////////////

Test(strlen_suite, strlen)
{
    char *str = "hello world";

    cr_assert(my_strlen(str) == 11);

    /////////Frees/////////
    cr_free(str);
}

Test(strlen_suite, strlen2)
{
    char *str = "Help me please";

    cr_assert(my_strlen(str) == 14);

    /////////Frees/////////
    cr_free(str);
}

//////////////////////////////////////////////////////////////
///////////////          strcmp_suite          ///////////////
//////////////////////////////////////////////////////////////

Test(strcmp_suite, strcat)
{
    char *str1 = my_strdup("hello");
    char *str2 = my_strdup(" world");
    char *str3 = my_strcat(str1, str2);

    cr_assert(str3, "hello world");

    /////////Frees/////////
    cr_free(str1);
    cr_free(str2);
    cr_free(str3);
}

Test(strcmp_suite, strcat2)
{
    char *str1 = my_strdup("hello");
    char *str2 = my_strdup(" world");
    char *str3 = my_strcat(str1, str2);

    cr_assert_str_eq(str3, "hello world");

    /////////Frees/////////
    cr_free(str1);
    cr_free(str2);
    cr_free(str3);
}

//////////////////////////////////////////////////////////////
///////////////        write_instruction       ///////////////
//////////////////////////////////////////////////////////////

Test(write_instruction_suite, stop_simulation)
{
    char *expected_output = my_strdup("STOP_SIMULATION\n");

    cr_redirect_stdout();
    write_instruction(STOP_SIMULATION, -1, false);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, start_simulation)
{
    char *expected_output = my_strdup("START_SIMULATION\n");

    cr_redirect_stdout();
    write_instruction(START_SIMULATION, -1, false);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_forward_value_1_0)
{
    char *expected_output = my_strdup("CAR_FORWARD:1.0\n");

    cr_redirect_stdout();
    write_instruction(CAR_FORWARD, 1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_forward_value_0_1)
{
    char *expected_output = my_strdup("CAR_FORWARD:0.1\n");

    cr_redirect_stdout();
    write_instruction(CAR_FORWARD, 0.1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_forward_value_0_5)
{
    char *expected_output = my_strdup("CAR_FORWARD:0.5\n");

    cr_redirect_stdout();
    write_instruction(CAR_FORWARD, 0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_forward_value_minus_0_5)
{
    char *expected_output = my_strdup("CAR_FORWARD:-0.5\n");

    cr_redirect_stdout();
    write_instruction(CAR_FORWARD, -0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_backwards_value_1_0)
{
    char *expected_output = my_strdup("CAR_BACKWARDS:1.0\n");

    cr_redirect_stdout();
    write_instruction(CAR_BACKWARDS, 1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_backwards_value_0_1)
{
    char *expected_output = my_strdup("CAR_BACKWARDS:0.1\n");

    cr_redirect_stdout();
    write_instruction(CAR_BACKWARDS, 0.1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_backwards_value_0_5)
{
    char *expected_output = my_strdup("CAR_BACKWARDS:0.5\n");

    cr_redirect_stdout();
    write_instruction(CAR_BACKWARDS, 0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, car_backwards_value_minus_0_5)
{
    char *expected_output = my_strdup("CAR_BACKWARDS:-0.5\n");

    cr_redirect_stdout();
    write_instruction(CAR_BACKWARDS, -0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, wheels_dir_value_1_0)
{
    char *expected_output = my_strdup("WHEELS_DIR:1.0\n");

    cr_redirect_stdout();
    write_instruction(WHEELS_DIR, 1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, wheels_dir_value_0_1)
{
    char *expected_output = my_strdup("WHEELS_DIR:0.1\n");

    cr_redirect_stdout();
    write_instruction(WHEELS_DIR, 0.1, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, wheels_dir_value_0_5)
{
    char *expected_output = my_strdup("WHEELS_DIR:0.5\n");

    cr_redirect_stdout();
    write_instruction(WHEELS_DIR, 0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, wheels_dir_value_0)
{
    char *expected_output = my_strdup("WHEELS_DIR:0.0\n");

    cr_redirect_stdout();
    write_instruction(WHEELS_DIR, 0, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, wheels_dir_value_minus_0_5)
{
    char *expected_output = my_strdup("WHEELS_DIR:-0.5\n");

    cr_redirect_stdout();
    write_instruction(WHEELS_DIR, -0.5, true);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, get_info_lidar)
{
    char *expected_output = my_strdup("GET_INFO_LIDAR\n");

    cr_redirect_stdout();
    write_instruction(GET_INFO_LIDAR, -1, false);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, get_current_wheels)
{
    char *expected_output = my_strdup("GET_CURRENT_WHEELS\n");

    cr_redirect_stdout();
    write_instruction(GET_CURRENT_WHEELS, -1, false);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

Test(write_instruction_suite, get_current_speed)
{
    char *expected_output = my_strdup("GET_CURRENT_SPEED\n");

    cr_redirect_stdout();
    write_instruction(GET_CURRENT_SPEED, -1, false);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

//////////////////////////////////////////////////////////////
///////////////         init_car_struct        ///////////////
//////////////////////////////////////////////////////////////

Test(init_car_suite, not_null)
{
    car_s *car = init_car_struct();

    cr_assert_not_null(car);

    /////////Frees/////////
    cr_free(car);
}

//////////////////////////////////////////////////////////////
///////////////            my_write            ///////////////
//////////////////////////////////////////////////////////////

Test(my_write_suite, theo_is_cringe)
{
    char *expected_output = my_strdup("theo is cringe\n");

    cr_redirect_stdout();
    my_write("theo is cringe\n", 1);

    cr_assert_stdout_eq_str(expected_output);

    /////////Frees/////////
    cr_free(expected_output);
}

//////////////////////////////////////////////////////////////
///////////////         my_print_array         ///////////////
//////////////////////////////////////////////////////////////

Test(my_print_array_suite, arr)
{
    char *arr[6] = {"hello", "hello", "hello", "hello", "hello", NULL};
    char *expected_output = my_strdup("hello\nhello\nhello\nhello\nhello\n");

    cr_redirect_stderr();
    my_print_array(arr);

    cr_assert_stderr_eq_str(expected_output);
    // Free memory
    cr_free(expected_output);
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    cr_free(arr);
}

//////////////////////////////////////////////////////////////
///////////////         my_print_nb_str        ///////////////
//////////////////////////////////////////////////////////////

Test(my_print_nb_str_suite, positive_numbers)
{
    float nums[6] = {3.14, 2.0, 1.5, 0.1, 100.0};
    char *expected_output = my_strdup("3.1\n2.0\n1.5\n0.1\n100.0\n");

    cr_redirect_stderr();
    my_print_nb_str(nums);

    cr_assert_stderr_eq_str(expected_output);

    // Free memory
    cr_free(expected_output);
    cr_free(nums);
}

Test(my_print_nb_str_suite, negative_numbers)
{
    float nums[6] = {-3.14, -2.0, -1.5, -0.1, -100.0};
    char *expected_output = my_strdup("-3.1\n-2.0\n-1.5\n-0.1\n-100.0\n");

    cr_redirect_stderr();
    my_print_nb_str(nums);

    cr_assert_stderr_eq_str(expected_output);

    // Free memory
    cr_free(expected_output);
    cr_free(nums);
}

//////////////////////////////////////////////////////////////
///////////////            print_nb            ///////////////
//////////////////////////////////////////////////////////////

Test(print_nb_suite, negative_numbers)
{
    float num = -3.14;
    char *expected_output = my_strdup("-3.1\n");

    cr_redirect_stderr();
    print_nb(num);

    cr_assert_stderr_eq_str(expected_output);

    // Free memory
    cr_free(expected_output);
}

Test(print_nb_suite, positive_numbers)
{
    float num = 3.14;
    char *expected_output = my_strdup("3.1\n");

    cr_redirect_stderr();
    print_nb(num);

    cr_assert_stderr_eq_str(expected_output);

    // Free memory
    cr_free(expected_output);
}

Test(print_nb_suite, zero)
{
    float num = 0;
    char *expected_output = my_strdup("0.0\n");

    cr_redirect_stderr();
    print_nb(num);

    cr_assert_stderr_eq_str(expected_output);

    // Free memory
    cr_free(expected_output);
}