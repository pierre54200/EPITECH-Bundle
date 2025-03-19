/*
** EPITECH PROJECT, 2024
** my_unsigned_decimal
** File description:
** convert into unsigned decimal
*/
#include "fproto.h"

int my_funsigned_decimal(int nb, char *flag, int fd)
{
    if (nb < 0)
        return 0;
    return (my_fput_nbr(nb, fd));
}
