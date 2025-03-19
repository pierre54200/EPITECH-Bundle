/*
** EPITECH PROJECT, 2024
** cpu.c
** File description:
** cpu
*/

#include "include/proto.h"

static double *clear_tab(double *tab)
{
    for (int i = 0; i != 10; i++) {
            tab[i] = 0;
    }
    return tab;
}

static char *cpu(char *stock)
{
    char buffer[100];
    int fd = open("/proc/stat", O_RDONLY);
    int entry = 0;
    int i = 0;

    if (fd < 0)
        return stock;
    entry = read(fd, buffer, 100);
    if (entry < 0)
        return stock;
    for (; buffer[i] != '\n'; i++)
        stock[i] = buffer[i];
    stock[i] = 0;
    close(fd);
    return stock;
}

static double abso(double nb)
{
    if (nb < 0)
        return (-1) * nb;
    return nb;
}

static double *display_cpu(double *s, double *c)
{
    double total = s[8];

    printw("\n%%Cpu(s): %.1f us, ", abso(s[0] - c[0]) / (total - c[8]) * 100);
    printw("%.1f sy, ", abso(s[2] - c[2]) / (total - c[8]) * 100);
    printw("%.1f ni, ", abso(s[1] - c[1]) / (total - c[8]) * 100);
    printw("%.1f id, ", abso(s[3] - c[3]) / (total - c[8]) * 100);
    printw("%.1f wa, ", abso(s[4] - c[4]) / (total - c[8]) * 100);
    printw("%.1f hi, ", abso(s[5] - c[5]) / (total - c[8]) * 100);
    printw("%.1f si, ", abso(s[6] - c[6]) / (total - c[8]) * 100);
    printw("%.1f st", abso(s[7] - c[7]) / (total - c[8]) * 100);
    c[0] = s[0];
    c[1] = s[1];
    c[2] = s[2];
    c[3] = s[3];
    c[4] = s[4];
    c[5] = s[5];
    c[6] = s[6];
    c[7] = s[7];
    c[8] = s[8];
    return c;
}

static double *cpu_to_cpu_stat(char *stock, double *cpu_stock)
{
    double stocking[10];
    int j = 0;
    int test = 0;
    double result = 0;

    clear_tab(stocking);
    for (int i = 0; j < 8; i++) {
        if (stock[i] >= '0' && stock[i] <= '9') {
            stocking[j] = 10 * stocking[j] + stock[i] - '0';
            test++;
        }
        if (((stock[i] == ' ') || stock[i] == '\n') && test > 0)
            j++;
    }
    for (int i = 0; i != 8; i++)
        result = result + stocking[i];
    stocking[8] = result - stocking[8];
    display_cpu(stocking, cpu_stock);
    clear_tab(stocking);
    return cpu_stock;
}

double *cpu_usage(double *cpu_stock)
{
    char stock[100];

    cpu(stock);
    cpu_stock = cpu_to_cpu_stat(stock, cpu_stock);
    return cpu_stock;
}
