/*
** EPITECH PROJECT, 2024
** setting_up.c
** File description:
** setting_up
*/
#include "setting.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

static int lenght(char *stock)
{
    int i = 0;

    for (; stock[i] != 0 && stock[i] != '\n'; i++);
    return i;
}

static int k_zero(char av, int k)
{
    if (av == 0)
        return 0;
    return k;
}

static char *auto_map(int result, char *av, char *stock)
{
    int k = 0;
    int line = 0;
    int j = 0;

    for (int i = 0; line + 1 <= result; line++) {
        for (; j != result; j++) {
            k = k_zero(av[k], k);
            stock[i + j] = av[k];
            k++;
        }
        i = i + j;
        j = 0;
        stock[i] = '\n';
        i++;
    }
    return stock;
}

static int check_first_line(char *buffer)
{
    int result = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] < '0' || buffer[i] > '9')
            exit(84);
        result = 10 * result + buffer[i] - '0';
    }
    return result;
}

static char *rest_of_file(char *buffer, int nb)
{
    int i = 0;
    int j = 0;
    int nb_test = 0;

    for (; buffer[i - 1] != '\n'; i++);
    for (; buffer[i + j] != 0; j++) {
        if (buffer[i + j] != '\n' && buffer[i + j] != '.'
        && buffer[i + j] != 'o')
            exit(84);
        if (buffer[i + j] == '\n')
            nb_test++;
        buffer[j] = buffer[i + j];
    }
    buffer[j] = 0;
    if (nb_test != nb)
        exit(84);
    return buffer;
}

static int check_file(char *av)
{
    int fd = open(av, O_RDONLY);
    char *buffer;
    int entry = 1;
    struct stat s;
    int size = 0;

    if (fd == -1)
        return 84;
    if (stat(av, &s) == -1)
        return 84;
    buffer = malloc(sizeof(char *) * (s.st_size + 1));
    while (entry != 0)
        entry = read(fd, buffer, s.st_size);
    if (entry < 0)
        return 84;
    size = check_first_line(buffer);
    rest_of_file(buffer, size);
    set_up(buffer, size, lenght(buffer), 0);
    free(buffer);
    return 0;
}

static int check_patern(char **av)
{
    int result = 0;
    char *stock;

    for (int i = 0; av[1][i] != 0; i++) {
        if (av[1][i] < '0' || av[1][i] > '9')
            exit(84);
        result = 10 * result + av[1][i] - '0';
    }
    stock = malloc(sizeof(char *) * ((result + 1) * (result + 1)));
    for (int i = 0; av[2][i] != 0; i++) {
        if (av[2][i] != '.' && av[2][i] != 'o')
            exit(84);
    }
    auto_map(result, av[2], stock);
    set_up(stock, result, result, 0);
    free(stock);
    return 0;
}

int setting_up(int ac, char **av)
{
    if (ac == 2)
        return check_file(av[1]);
    if (ac == 3)
        return check_patern(av);
    if (ac > 3 || ac == 1)
        return 84;
    return 0;
}
