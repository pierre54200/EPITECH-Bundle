/*
** EPITECH PROJECT, 2024
** proto.h
** File description:
** proto
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PROTO_H
    #define PROTO_H

enum type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
};

enum sorting {
    ID,
    NAME,
    TYPE,
    R
};

typedef struct data {
    int value;
    char *type;
    char *name;
    struct data *prec;
} data_t;

int is_a_sort(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_tablen(char **tab);
int my_put_nbr(int nb);
char *my_strdup(const char *src);
int my_getnbr(char const *str);
void sort_diff(data_t **sorted, int sorting, int reverse);
#endif /* PROTO_H */
