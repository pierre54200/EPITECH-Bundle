/*
** EPITECH PROJECT, 2024
** my_getloadavg.c
** File description:
** loadavg
*/

#include "include/proto.h"

int my_getloadavg(void)
{
    double loadavg[3];
    char buffer[14];
    char *stop;
    int fd = open("/proc/loadavg", O_RDONLY);

    for (int i = 0; i != 3; i++) {
        read(fd, buffer, 5);
        loadavg[i] = strtod(buffer, &stop);
    }
    printw("load average: ");
    printw("%.2f, %.2f, %.2f\n", loadavg[0], loadavg[1], loadavg[2]);
    close(fd);
    return 0;
}
