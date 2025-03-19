/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** mini printf
*/

#include "include/my.h"
#include <stdarg.h>
static int diplay2(const char *format, int i)
{
    int nb = 0;

    if (format[i] == '\\' || (format[i] == '%' && format[i + 1] == '%'))
        my_putchar(format[i + 1]);
    if (format[i] != '%' && format[i] != '\\' && format[i - 1] != '%')
        my_putchar(format[i]);
    return nb;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int nb = 0;

    va_start(list, format);
    for (int i = 0; format[i] != 0; i++) {
        if (format[i] == '%')
            i++;
        if (format[i - 1] == '%' && format[i] == 'c')
            my_putchar(va_arg(list, int));
        if (format[i - 1] == '%' && format[i] == 's')
            nb = nb + my_putstr(va_arg(list, char *));
        if (format[i - 1] == '%' && (format[i] == 'i' || format[i] == 'd'))
            nb = nb + my_put_nbr(va_arg(list, int));
        nb = nb + diplay2(format, i);
        nb++;
    }
    va_end(list);
    return nb;
}
