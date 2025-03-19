/*
** EPITECH PROJECT, 2024
** my_put_double.c
** File description:
** display a double
*/

#include <stdio.h>
#include "proto.h"
double my_recup_decimal(double nb, int counter)
{
    char stock[counter + 1];
    int i = 0;
    double nb2 = 0;

    for (; i != counter; i++) {
        stock[i] = nb / puissancedouble_10(counter - i - 1) + '0';
        nb = nb - (stock[i] - '0') * puissancedouble_10(counter - i - 1);
    }
    stock[i] = '\0';
    for (int j = 0; stock[j] != 0; j++)
        nb2 = nb2 * 10 + stock[j] - '0';
    return nb2;
}

int my_put_double(double nb, int counter)
{
    int size = 0;
    char stock[counter + 1];
    int i = 0;

    if (counter == 0) {
        my_putchar('0');
        size++;
    }
    for (int j = 0; stock[j] != '\0'; j++)
        stock[j] = '0';
    for (; i != counter; i++) {
        stock[i] = nb / puissancedouble_10(counter - i - 1) + '0';
        nb = nb - (stock[i] - '0') * puissancedouble_10(counter - i - 1);
        size++;
    }
    stock[i] = '\0';
    my_putstr(stock);
    return size;
}
