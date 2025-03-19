/*
** EPITECH PROJECT, 2024
** my_print_digits.c
** File description:
** task03
*/

int my_print_digits(void)
{
    int digit = '0';

    while (digit <= '9') {
        my_putchar(digit);
        digit = digit + 1;
    }
    return (0);
}
