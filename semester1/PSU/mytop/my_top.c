/*
** EPITECH PROJECT, 2024
** my_top.c
** File description:
** top
*/
#include "include/proto.h"

static int timer(void)
{
    time_t timestamp = time(NULL);
    struct tm *time = localtime(&timestamp);
    char buffer[20];

    strftime(buffer, 20, "%H:%M:%S", time);
    printw("top - %s up ", buffer);
    return 0;
}

static int sleep_time(int clock, WINDOW *win)
{
    int key = 0;

    clock = clock;
    for (; clock != 0; clock--) {
        nodelay(win, true);
        key = getch();
        if (key == 'q') {
            endwin();
            exit(0);
        }
        if (key != 'q' && key != -1) {
            clear();
            continue;
        }
        sleep(1);
    }
    return 0;
}

static int uptime_day(int hour)
{
    int hour2 = hour;
    int day = -1;

    for (; hour2 > 0; day++)
        hour2 = hour2 - 24;
    if (day > 0)
        printw("%d days, ", day);
    return 0;
}

static int uptime(void)
{
    int fd = open("/proc/uptime", O_RDONLY);
    char buffer[10];
    int entry = read(fd, buffer, 10);
    int min = my_getnbr(buffer) / 60;
    int hour = -1;

    if (fd < 0)
        return 84;
    if (entry < 0)
        return 84;
    for (int min2 = min; min2 > 0; hour++)
        min2 = min2 - 60;
    uptime_day(hour);
    if (hour == 0)
        printw("%d min, ", min);
    if (hour != 0 && min % 60 < 10)
        printw("%d:0%d, ", hour, min % 60);
    if (hour != 0 && min % 60 >= 10)
        printw("%d:%d, ", hour, min % 60);
    return close(fd) * 0;
}

static int user(void)
{
    printw("0 user, ");
    return 0;
}

static int date(void)
{
    int result = 0;

    result += timer();
    result += uptime();
    result += user();
    result += my_getloadavg();
    result += task();
    return result;
}

int my_top(int clock, int counter)
{
    WINDOW *win;
    double cpu[10];

    win = initscr();
    while (counter != 0) {
        date();
        cpu_usage(cpu);
        mem_handler();
        task_manager();
        refresh();
        sleep_time(clock, win);
        clear();
        counter--;
    }
    endwin();
    return 0;
}
