/*
** EPITECH PROJECT, 2024
** task.c
** File description:
** task
*/

#include "include/proto.h"

static int *print_stock(int *stock)
{
    printw("%d running, ", stock[0]);
    stock[0] = 0;
    printw("%d sleeping, ", stock[1]);
    stock[1] = 0;
    printw("%d stopped, ", stock[2]);
    stock[2] = 0;
    printw("%d zombie", stock[3]);
    stock[3] = 0;
    return stock;
}

static int *value_task(int *stock, int c)
{
    if (c == 'R')
        stock[0]++;
    if (c == 'D' || c == 'I' || c == 'S')
        stock[1]++;
    if (c == 'T')
        stock[2]++;
    if (c == 'Z')
        stock[3]++;
    return stock;
}

static char *buffering(struct dirent *entry, char *buffer)
{
    char path[20];
    int fd = 0;
    int enter = 0;

    snprintf(path, 40, "/proc/%ld/status", strtol(entry->d_name, NULL, 10));
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return buffer;
    enter = read(fd, buffer, 100);
    if (enter < 0)
        return buffer;
    close(fd);
    return buffer;
}

static int *nbr_task_plus(struct dirent *entry, int *stock)
{
    char buffer[100];
    int i = 0;
    int test = 0;
    int j = 0;

    buffering(entry, buffer);
    for (; test != 2; i++) {
        if (buffer[i] == '\n')
            test++;
        if (test < 1)
            j = i;
    }
    value_task(stock, buffer[j + 9]);
    value_task(stock, buffer[i + 7]);
    return stock;
}

static int nbr_task(void)
{
    DIR *proc = opendir("/proc");
    struct dirent *entry;
    int count = 0;
    int stock[4] = {0, 0, 0, 0};

    if (proc == NULL) {
        perror("opendir(""/proc"")");
        return 84;
    }
    entry = readdir(proc);
    for (; entry != 0; entry = readdir(proc)) {
        if (isdigit(*entry->d_name) == 0)
            continue;
        nbr_task_plus(entry, stock);
        count++;
    }
    closedir(proc);
    printw("Tasks: %d total, ", count);
    print_stock(stock);
    return 0;
}

int task(void)
{
    nbr_task();
    return 0;
}
