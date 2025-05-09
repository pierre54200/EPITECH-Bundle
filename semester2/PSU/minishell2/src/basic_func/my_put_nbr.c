/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** task07
*/
#include "proto.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

static int puissance_10(int i)
{
    int result = 1;

    if (i == 0)
        return 1;
    for (; i != 0; i--)
        result = result * 10;
    return (result);
}

static int count(int counter)
{
    int i = 0;

    for (; counter >= 10; i++)
        counter = counter / 10;
    return i;
}

int my_put_nbr(int nb)
{
    int i = 0;
    int stock = 0;
    int size = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        size++;
        if (nb == 0)
            nb = 2147483648;
    }
    size = size + count(nb);
    i = i + count(nb);
    for (; i >= 0; i--) {
        stock = nb / puissance_10(i);
        nb = nb - stock * puissance_10(i);
        my_putchar('0' + stock);
    }
    return size + 1;
}
