/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "include/proto.h"
#include "include/shell.h"

int main(void)
{
    data_t *data = NULL;
    int result = 0;

    result = workshop_shell(&data);
    free(data);
    return result;
}
