/*
** EPITECH PROJECT, 2024
** test_my_revstr
** File description:
** test my_revstr
*/
#include <criterion/criterion.h>

Test(my_revstr, reverse_a_string)
{
    char str[] = "Hello";

    my_revstr(str);
    cr_assert_str_eq(str,"olleH");
}

Test(my_revstr, reverse_a_empty_string)
{
    char str[] = "";

    my_revstr(str);
    cr_assert_str_eq(str,"");
}

Test(my_revstr, reverse_a_longer_string)
{
    char str[] = "Hello Hi";

    my_revstr(str);
    cr_assert_str_eq(str,"iH olleH");
}
