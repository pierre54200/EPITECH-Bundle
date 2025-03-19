/*
** EPITECH PROJECT, 2024
** rush3.c
** File description:
** rush3
*/
#include <unistd.h>
#include "rush3.h"
int rush3_error(char *buff)
{
    int h = 0;
    int l = 0;
    int test = 0;

    for (int i = 0; buff[i] != 0; i++) {
        for (; buff[i] != '\n' && test == 0; i++)
            l++;
        test++;
        if (buff[i] == '\n')
            h++;
    }
    if (l == 1 || h == 1) {
        rush3(buff);
        return 0;
    }
    write(2, "none\n", 5);
    return 84;
}

static int rush3_display_nb(int h, int l)
{
    if (h > 2048)
        h = 2048;
    if (l > 2048)
        l = 2048;
    my_put_nbr(l);
    my_putchar(' ');
    my_put_nbr(h);
    return 0;
}

static int rush3_b(int h, int l)
{
    for (int i = 3; i <= 4; i++) {
        my_putstr("[rush1-");
        my_put_nbr(i);
        my_putstr("] ");
        rush3_display_nb(h, l);
        my_putstr(" || ");
    }
    return 0;
}

static int rush3_display_content(char *buff, int h, int l)
{
    if (buff[0] == 'o')
        my_putstr("[rush1-1] ");
    if (buff[0] == '/' || buff[0] == '*')
        my_putstr("[rush1-2] ");
    if (buff[0] == 'A' && buff[l - 1] == 'A')
        my_putstr("[rush1-3] ");
    if (buff[0] == 'A' && buff[l - 1] == 'C' && buff[l * h + h - 2] == 'C')
        my_putstr("[rush1-4] ");
    if (buff[0] == 'A' && buff[l - 1] == 'C' && buff[l * h + h - 2] == 'A')
        my_putstr("[rush1-5] ");
    if (buff[0] == 'B') {
        rush3_b(h, l);
        my_putstr("[rush1-5] ");
        rush3_display_nb(h, l);
        return 0;
    }
    rush3_display_nb(h, l);
    return 0;
}

int rush3(char *buff)
{
    int h = 0;
    int l = 0;
    int test = 0;

    for (int i = 0; buff[i] != 0; i++) {
        for (; buff[i] != '\n' && test == 0; i++)
            l++;
        test++;
        if (buff[i] == '\n')
            h++;
    }
    if ((l == 0 || h == 0) || (l * h) > 4096 && (l != 1 || h != 1)) {
        write(2, "none\n", 5);
        return 84;
    }
    rush3_display_content(buff, h, l);
    my_putchar('\n');
    return 0;
}
