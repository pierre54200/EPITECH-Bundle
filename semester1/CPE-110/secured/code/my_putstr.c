/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** putstr
*/

#include "../include/hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int puissance_10(int i)
{
    int result = 1;

    if (i == 0)
        return 1;
    for (; i != 0; i--)
        result = result * 10;
    return (result);
}

int counter(int counter)
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
    size = size + counter(nb);
    i = i + counter(nb);
    for (; i >= 0; i--) {
        stock = nb / puissance_10(i);
        nb = nb - stock * puissance_10(i);
        my_putchar('0' + stock);
    }
    return size + 1;
}

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}
