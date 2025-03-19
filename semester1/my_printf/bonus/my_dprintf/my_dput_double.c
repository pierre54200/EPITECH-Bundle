/*
** EPITECH PROJECT, 2024
** my_put_double.c
** File description:
** display a double
*/

#include <stdio.h>
#include "dproto.h"
double my_drecup_decimal(double nb, int counter, int fd)
{
    char stock[counter + 1];
    int i = 0;
    double nb2 = 0;

    for (; i != counter; i++) {
        stock[i] = nb / dpuissancedouble_10(counter - i - 1) + '0';
        nb = nb - (stock[i] - '0') * dpuissancedouble_10(counter - i - 1);
    }
    stock[i] = '\0';
    for (int j = 0; stock[j] != 0; j++)
        nb2 = nb2 * 10 + stock[j] - '0';
    return nb2;
}

int my_dput_double(double nb, int counter, int fd)
{
    int size = 0;
    char stock[counter + 1];
    int i = 0;

    if (counter == 0) {
        my_dputchar('0', fd);
        size++;
    }
    for (int j = 0; stock[j] != '\0'; j++)
        stock[j] = '0';
    for (; i != counter; i++) {
        stock[i] = nb / dpuissancedouble_10(counter - i - 1) + '0';
        nb = nb - (stock[i] - '0') * dpuissancedouble_10(counter - i - 1);
        size++;
    }
    stock[i] = '\0';
    my_dputstr(stock, fd);
    return size;
}
