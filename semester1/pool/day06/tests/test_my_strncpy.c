/*
** EPITECH PROJECT, 2024
** test_my_strncpy
** File description:
** test strncpy
*/

#include <criterion/criterion.h>

Test(my_strncpy, copy_five_character_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_seven_character_in_empty_array)
{
    char dest[7] = {0};

    my_strncpy(dest, "Hi", 7);
    cr_assert_str_eq(dest, "Hi");
}

Test(my_strncpy, copy_zero_character_in_empty_array)
{
    char dest[7] = {0};

    my_strncpy(dest, "Hi", 0);
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_zero_character_in_an_array)
{
    char dest[7] = "Hello";

    my_strncpy(dest, "Hi", 0);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_two_character_in_an_array)
{
    char dest[7] = "Hello";

    my_strncpy(dest, "Hi", 2);
    cr_assert_str_eq(dest, "Hillo");
}
