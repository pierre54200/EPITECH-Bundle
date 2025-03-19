/*
** EPITECH PROJECT, 2025
** my_get_nbr.c
** File description:
** get_nbr
*/

int my_get_nbr(const char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb = nb * 10;
        nb = nb + str[i] - '0';
    }
    return nb;
}
