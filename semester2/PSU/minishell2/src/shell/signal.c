/*
** EPITECH PROJECT, 2025
** signal.c
** File description:
** signal
*/

#include "proto.h"

void sigint(int)
{
    my_putstr("\n$>");
    return;
}

void sigfault(int)
{
    return;
}
