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
#include "fprintf.h"
#include "fproto.h"

static int flag(char c)
{
    if (c == '+' || c == '#')
        return 1;
    return 0;
}

static int my_printf3(int i, va_list list, const char *format, int fd)
{
    if (format[i + 1] == 'c') {
        my_fputchar(va_arg(list, int), fd);
        return 1;
    }
    if (format[i + 1] == '%') {
        my_fputchar('%', fd);
        return 1;
    }
    if (format[i + 1] == 's')
        return my_fputstr(va_arg(list, char *), fd);
}

static int my_printf2(int i, va_list list, const char *format, int fd)
{
    s_structure_t structure;
    s_structure2_t structure2;
    char stock_flag[10];

    for (int j = 0; flag(format[i + 1]) == 1; i++){
        stock_flag[j] = format[i + 1];
        j++;
    }
    for (int j = 0; j != 6; j++){
        if (FLAGS[j].flag[0] == format[i + 1])
            return FLAGS[j].fptr(va_arg(list, int), stock_flag, fd);
    }
    for (int k = 0; k != 4; k++){
        if (FLAGS2[k].flag[0] == format[i + 1])
            return FLAGS2[k].fptr(va_arg(list, double), 6, stock_flag, fd);
    }
    return my_printf3(i, list, format, fd);
}

int my_fprintf(FILE *ffptr, const char *format, ...)
{
    va_list list;
    int nb = 0;
    int fd = fileno(ffptr);
    int size = 0;

    va_start(list, format);
    for (int i = 0; format[i] != 0; i++) {
        if (format[i] == '%'){
            size = size + my_printf2(i, list, format, fd);
            i++;
        } else {
            my_fputchar(format[i], fd);
            size++;
        }
        for (int j = i; format[j - 1] == '%' && flag(format[i]) == 1; i++);
    }
    va_end(list);
    return size;
}
