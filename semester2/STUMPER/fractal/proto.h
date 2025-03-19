/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** proto
*/

#include <unistd.h>
#include <stdio.h>

#ifndef PROTO_H
    #define PROTO_H
int my_strlen(const char *str);
int my_putstr(const char *str);
int my_strcmp(const char *s1, const char *s2);
int my_get_nbr(const char *str);
int my_puts(const char *str);
void fractal(int nb, char **av);
int my_putchar(char c);
int nbr_of_line(const char *av);
#endif // PROTO_H //
