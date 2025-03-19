/*
** EPITECH PROJECT, 2024
** my_print_comb.c
** File description:
** task05
*/


#include <unistd.h>

int ascending_order(char a, char b, char c, int i)
{
    if (a > b && b > c) {
        my_putchar(c);
        my_putchar(b);
        my_putchar(a);
        if (i < 789) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
    return (0);
}

int my_print_comb(void)
{
    int hundred = '0';
    int dozen = '0';
    int digit = '0';
    int i = 0;

    while (i < 789) {
        i = i + 1;
        if (digit == '9') {
            digit = '0';
            dozen = dozen + 1;
        } else {
            digit = digit + 1;
        }
            if (dozen > '9') {
                dozen = '0';
                hundred = hundred + 1;
            }
    ascending_order(digit, dozen, hundred, i);
    }
    return (0);
}
