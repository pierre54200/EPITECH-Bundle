/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
#include "include/proto.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}

static int counter(int counter)
{
    int i = 0;

    for (; counter >= 10; i++)
        counter = counter / 10;
    return i;
}

static int puissance_10(int i)
{
    int result = 1;

    if (i == 0)
        return 1;
    for (; i != 0; i--)
        result = result * 10;
    return (result);
}

int my_put_nbr(int nb)
{
    int i = 0;
    int stock = 0;
    int size = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        size++;
        if (nb == 0)
            nb = 2147483648;
    }
    size = size + counter(nb);
    i = i + counter(nb);
    for (; i >= 0; i--) {
        stock = nb / puissance_10(i);
        nb = nb - stock * puissance_10(i);
        my_putchar('0' + stock);
    }
    return size + 1;
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(const char *src)
{
    char *dst = malloc(my_strlen(src) + 1);

    if (dst == NULL)
    return NULL;
    my_strcpy(dst, src);
    return dst;
}
