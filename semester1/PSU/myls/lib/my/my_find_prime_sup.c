/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** task07
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    for (; my_is_prime(nb) == 0; nb++);
    return (nb);
}
