/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** mimics printf
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"
#include "proto.h"

static int flag(char c)
{
    if (c == '+' || c == '#' || c >= '0' && c <= '9' || c == ' ' || c == '.')
        return 1;
    return 0;
}

static int change_nbvir(char *flag)
{
    int nbvir = 0;
    int test = 0;

    for (int i = 0; flag[i] != 0; i++) {
        if (flag[i] == '.')
            test++;
        if (flag[i] >= '0' && flag[i] <= '9' && test != 0) {
            nbvir = 10 * nbvir + flag[i] - '0';
        }
    }
    if (nbvir == 0 && test == 0)
        nbvir = 6;
    return nbvir;
}

static int my_printf_flag(int i, va_list list, const char *format)
{
    s_structure_t structure;
    char stock_flag[10];
    int nbvir = 6;

    for (int i = 0; i != 10; i++)
        stock_flag[i] = 0;
    for (int j = 0; flag(format[i + 1]) == 1; i++){
        stock_flag[j] = format[i + 1];
        j++;
    }
    nbvir = change_nbvir(stock_flag);
    for (int j = 0; j != 15; j++){
        if (FLAGS[j].flag[0] == format[i + 1])
            return FLAGS[j].fptr(list, nbvir, stock_flag);
    }
    if (format[i + 1] == '%') {
        my_putchar('%');
        return 1;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int size = 0;

    va_start(list, format);
    for (int i = 0; format[i] != 0; i++) {
        if (format[i] == '%'){
            size = size + my_printf_flag(i, list, format);
            i++;
        } else {
            my_putchar(format[i]);
            size++;
        }
        for (int j = i; format[j - 1] == '%' && flag(format[i]) == 1; i++);
    }
    va_end(list);
    return size;
}
