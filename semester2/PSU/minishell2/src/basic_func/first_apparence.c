/*
** EPITECH PROJECT, 2025
** first.c
** File description:
** first
*/

int first_sign(char *str, char want)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == want)
            return i;
    }
    return -1;
}
