/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "proto.h"

int my_putstr(char *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}

int my_putnstr(char *str, int n)
{
    int len = my_strlen(str) - n;
    char src[len];
    int j = 0;

    for (int i = n; str[i] != 0; i++) {
        src[j] = str[i];
        j++;
    }
    write(1, src, len);
    return len;
}

int my_puttostr(char *str, int n, char c)
{
    for (int i = n; str[i] != 0 && str[i] != c; i++)
        write(1, &str[i], 1);
    return 0;
}

int my_puts(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return len;
}
