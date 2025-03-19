/*
** EPITECH PROJECT, 2024
** cat.c
** File description:
** cat in c
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <errno.h>
#include <unistd.h>

void error_dir(char *av)
{
    my_putstr("cat: ");
    my_putstr(av);
    my_putstr(": Is a directory\n");
    return;
}

void error(int save_error, char *av)
{
    if (save_error == 13) {
        my_putstr("cat: ");
        my_putstr(av);
        my_putstr(": Permission denied\n");
    }
    if (save_error == 2) {
        my_putstr("cat: ");
        my_putstr(av);
        my_putstr(": No such file or directory\n");
    }
    return;
}

void cat(int ac, char *av)
{
    int fd;
    int size = 0;
    char buffer[2];

    fd = open(av, O_RDONLY);
    if (fd == -1) {
        error(errno, av);
        return;
    }
    size = read(fd, buffer, 2);
    if (size < 0)
        error_dir(av);
    while (size >= 2) {
        write(1, buffer, 2);
        size = read(fd, buffer, 2);
    }
    if (size != 0)
        write(1, buffer, 1);
    close(fd);
    return;
}

void main(int ac, char **av)
{
    int fd;
    int size = 0;
    char buffer[20];

    while (ac == 1) {
        write(1, buffer, size);
        size = read(0, buffer, 2);
        if (size == 0)
            return;
    }
    for (int i = 1; av[i] != 0; i++)
        cat(ac, av[i]);
    return;
}
