/*
** EPITECH PROJECT, 2024
** my_unsigned_decimal
** File description:
** convert into unsigned decimal
*/
#include "dproto.h"

int my_dunsigned_decimal(int nb, char *flag, int fd)
{
    if (nb < 0)
        return 0;
    return (my_dput_nbr(nb, fd));
}
