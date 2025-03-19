/*
** EPITECH PROJECT, 2024
** task_manager.c
** File description:
** task_manage
*/

#include "include/proto.h"
#include <pwd.h>

static int first_line(void)
{
    printw("\n   ");
    printw("PID ");
    printw("S  ");
    printw("PR  ");
    printw("NI    ");
    printw("VIRT    ");
    printw("RES  ");
    printw("%%CPU ");
    printw("%%MEM ");
    printw("COMMAND\n");
    return 0;
}

static double *buffering_stock(char *b, double *stock)
{
    int test = 0;
    int j = 0;
    int sign = 1;

    for (int i = 0; b[i] != 0; i++) {
        if (b[i] == '(' && b[i] == ')')
            test++;
        if (test == 1)
            continue;
        if (b[i] == ' ') {
            stock[j] = sign * stock[j];
            j++;
            sign = 1;
        }
        if (b[i] == '-')
            sign = -1;
        if ((b[i] >= '0' && b[i] <= '9') || (b[i] >= 'A' && b[i] <= 'Z'))
            stock[j] = 10 * stock[j] + b[i] - '0';
    }
    return stock;
}

static double *buffering(struct dirent *entry, char *buffer, double *stock)
{
    char path[20];
    int fd = 0;
    int enter = 0;

    snprintf(path, 40, "/proc/%ld/stat", strtol(entry->d_name, NULL, 10));
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return stock;
    enter = read(fd, buffer, 300);
    if (enter < 0)
        return stock;
    buffering_stock(buffer, stock);
    close(fd);
    return stock;
}

static int user(double *stock, char *buffer)
{
    int test = 0;
    int c = stock[2];

    printw("%6.0f", stock[0]);
    printw(" %c", c + '0');
    if (stock[17] <= -100)
        printw("   rt");
    else
        printw(" %3.0f", stock[17]);
    printw(" %3.0f ", stock[18]);
    printw("%7.0f ", stock[22] / 1024);
    printw("%6.0f", stock[23] * 4);
    printw(" 0.0  0.0 ");
    for (int i = 0; buffer[i] != ')'; i++) {
        if (buffer[i] == '(')
            test++;
        if (test == 1 && buffer[i] != '(')
            printw("%c", buffer[i]);
    }
    return printw("\n");
}

static int task2(struct dirent *entry)
{
    char buffer[300];
    double stock[52];

    for (int i = 0; i != 300; i++)
        buffer[i] = 0;
    for (int i = 0; i != 52; i++)
        stock[i] = 0;
    buffering(entry, buffer, stock);
    user(stock, buffer);
    return 0;
}

static int tasks(void)
{
    DIR *proc = opendir("/proc");
    struct dirent *entry;

    if (proc == NULL) {
        perror("opendir(""/proc"")");
        return 84;
    }
    entry = readdir(proc);
    for (; entry != 0; entry = readdir(proc)) {
        if (isdigit(*entry->d_name) == 0)
            continue;
        task2(entry);
    }
    closedir(proc);
    return 0;
}

int task_manager(void)
{
    first_line();
    tasks();
    return 0;
}
