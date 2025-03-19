/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** task07
*/
#include "fproto.h"

int fpuissance_10(int i)
{
    int result = 1;

    if (i == 0)
        return 1;
    for (; i != 0; i--)
        result = result * 10;
    return (result);
}

int fcounter(int counter)
{
    int i = 0;

    for (; counter >= 10; i++)
        counter = counter / 10;
    return i;
}

int my_fput_nbr(int nb, int fd)
{
    int i = 0;
    int stock = 0;
    int size = 0;

    if (nb < 0) {
        my_fputchar('-', fd);
        nb = nb * (-1);
        size++;
        if (nb == 0)
            nb = 2147483648;
    }
    size = size + fcounter(nb);
    i = i + fcounter(nb);
    for (; i >= 0; i--) {
        stock = nb / fpuissance_10(i);
        nb = nb - stock * fpuissance_10(i);
        my_fputchar('0' + stock, fd);
    }
    return size + 1;
}

int my_fput_nbr2(int nb, char *flag, int fd)
{
    int i = 0;
    int size = 0;

    if (flag[0] != '\0')
        size = size + fflag_handler_double(flag, nb, 0, fd);
    if (nb < 0) {
        my_fputchar('-', fd);
        nb = nb * (-1);
        size++;
        if (nb == 0)
            nb = 2147483648;
    }
    size = size + fcounter(nb);
    i = i + fcounter(nb);
    for (int stock = 0; i >= 0; i--) {
        stock = nb / fpuissance_10(i);
        nb = nb - stock * fpuissance_10(i);
        my_fputchar('0' + stock, fd);
    }
    return size + 1;
}
