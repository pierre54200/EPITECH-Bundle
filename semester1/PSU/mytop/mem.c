/*
** EPITECH PROJECT, 2024
** mem.c
** File description:
** mem
*/
#include "include/proto.h"

static double *clear_tab(double *tab)
{
    for (int i = 0; i != 49; i++) {
            tab[i] = 0;
    }
    return tab;
}

static char *mem(char *stock)
{
    char buffer[5000];
    int fd = open("/proc/meminfo", O_RDONLY);
    int entry = 0;
    int i = 0;

    for (int j = 0; j != 5000; j++)
        buffer[j] = 0;
    if (fd < 0)
        return stock;
    entry = read(fd, buffer, 5000);
    if (entry < 0)
        return stock;
    for (; buffer[i] != 0; i++)
        stock[i] = buffer[i];
    stock[i] = 0;
    close(fd);
    return stock;
}

static int displaymem(double *stocking)
{
    printw("\nMiB Mem : ");
    printw("%.1f total, ", stocking[0] / 1024);
    printw("%.1f free, ", stocking[1] / 1024);
    printw("%.1f used, ", (stocking[0] - stocking[2]) / 1024);
    printw("%.1f ", (stocking[3] + stocking[4] + stocking[25]) / 1024);
    printw("buff/cache");
    return 0;
}

static int displaymemswap(double *stocking)
{
    printw("\nMiB Swap: ");
    printw("%.1f total, ", stocking[14] / 1024);
    printw("%.1f free, ", stocking[15] / 1024);
    printw("%.1f used. ", (stocking[14] - stocking[15]) / 1024);
    printw("%.1f avail Mem\n", stocking[2] / 1024);
    return 0;
}

static int mem_to_mem_stat(char *stock)
{
    double stocking[50];
    int j = 0;

    clear_tab(stocking);
    for (int i = 0; j < 49; i++) {
        if (stock[i] >= '0' && stock[i] <= '9') {
            stocking[j] = 10 * stocking[j] + stock[i] - '0';
        }
        if (stock[i] == '\n')
            j++;
    }
    displaymem(stocking);
    displaymemswap(stocking);
    clear_tab(stocking);
    return 0;
}

int mem_handler(void)
{
    char stock[5000];

    mem(stock);
    mem_to_mem_stat(stock);
    return 0;
}
