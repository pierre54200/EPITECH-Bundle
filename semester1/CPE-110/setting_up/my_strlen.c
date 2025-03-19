/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int len = 0;

    for (; str[len] != 0; len++);
    return len;
}
