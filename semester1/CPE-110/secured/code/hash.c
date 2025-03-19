/*
** EPITECH PROJECT, 2025
** hash.c
** File description:
** hash
*/

#include "../include/hashtable.h"

int hash(char *key, int len)
{
    int sum = 0;
    int mul = 1;
    int lon = 0;

    if (key == NULL || len <= 0)
        return 84;
    for (; key[lon]; lon++);
    if (lon == 0)
        return 84;
    for (int i = 0; i != 1000; i++){
        mul = (i % 4 == 0) ? 1 : mul * 1000 * lon * len;
        sum += (key[i % lon] % (i + 1)) * mul + key[i % lon] * (i % lon);
    }
    if (sum < 0)
        sum = -sum;
    return sum;
}
