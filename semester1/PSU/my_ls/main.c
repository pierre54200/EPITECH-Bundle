/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "include/my.h"
#include "include/proto.h"
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <stdlib.h>
#include <sys/stat.h>

static int my_strcmp_ls(char *s1, char *s2)
{
    int result = 0;
    int i = 0;
    char stock1[my_strlen(s1)];
    char stock2[my_strlen(s2)];

    my_strcpy(stock1, s1);
    my_strcpy(stock2, s2);
    my_strlowcase(stock1);
    my_strlowcase(stock2);
    for (; stock1[i] == stock2[i]; i++) {
        if (stock1[i] == '\0' && stock2[i] == '\0')
            return 0;
    }
    result = stock1[i] - stock2[i];
    return result;
}

static int my_strcmptime_ls(char *s1, char *s2)
{
    struct stat t1;
    struct stat t2;

    stat(s1, &t1);
    stat(s2, &t2);
    return t2.st_mtime - t1.st_mtime;
}

char **my_swap_tab(char **stock, int i)
{
    char *stocking = stock[i];

    stock[i] = stock[i + 1];
    stock[i + 1] = stocking;
    return stock;
}

static char **order_tr(char **stock, int test)
{
    int len = 0;
    int testlen = 0;

    for (; stock[len] != 0; len++);
    for (int i = 0; testlen != len * len && test > 29 && test < 40; i++) {
        if (my_strcmptime_ls(stock[i], stock[i + 1]) < 0) {
            my_swap_tab(stock, i);
        }
        if (stock[i + 2] == 0) {
            i = -1;
            testlen++;
        }
    }
    return stock;
}

static char **order_t(char **stock, int test)
{
    int len = 0;
    int testlen = 0;

    for (; stock[len] != 0; len++);
    for (int i = 0; testlen != len * len && test > 19 && test < 30; i++) {
        if (my_strcmptime_ls(stock[i], stock[i + 1]) > 0) {
            my_swap_tab(stock, i);
        }
        if (stock[i + 2] == 0) {
            i = -1;
            testlen++;
        }
    }
    order_tr(stock, test);
    return stock;
}

static char **order_r(char **stock, int test)
{
    int len = 0;
    int testlen = 0;

    for (; stock[len] != 0; len++);
    for (int i = 0; testlen != len * len && test > 9 && test < 20; i++) {
        if (my_strcmp_ls(stock[i], stock[i + 1]) < 0) {
            my_swap_tab(stock, i);
        }
        if (stock[i + 2] == 0) {
            i = -1;
            testlen++;
        }
    }
    order_t(stock, test);
    return stock;
}

char **order(char **stock, int test)
{
    int len = 0;
    int testlen = 0;

    for (; stock[len] != 0; len++);
    for (int i = 0; testlen != len * len && test < 10; i++) {
        if (my_strcmp_ls(stock[i], stock[i + 1]) > 0) {
            my_swap_tab(stock, i);
        }
        if (stock[i + 2] == 0) {
            i = -1;
            testlen++;
        }
    }
    order_r(stock, test);
    return stock;
}

static char *better_flag(char *flag2, char *flag)
{
    isaflag(flag);
    for (int i = 0; flag2[i] != 0; i++)
        flag2[i] = 0;
    for (int i = 0; flag[i] != 0 && flag[i - 1] != 'l'; i++) {
        if (flag[i] == 'l')
            my_strcat(flag2, "l");
    }
    for (int i = 0; flag[i] != 0 && flag[i - 1] != 'a'; i++) {
        if (flag[i] == 'a')
            my_strcat(flag2, "a");
    }
    for (int i = 0; flag[i] != 0 && flag[i - 1] != 'r'; i++) {
        if (flag[i] == 'r')
            my_strcat(flag2, "r");
    }
    for (int i = 0; flag[i] != 0 && flag[i - 1] != 't'; i++) {
        if (flag[i] == 't')
            my_strcat(flag2, "t");
    }
    return flag2;
}

static int ls_handler(int ac, char **av, char *flag, int result)
{
    if (ac == 1)
        return my_ls_empty(flag);
    if (ac == 2)
        return my_ls_one(av, flag, result);
    return my_ls(av, flag, result);
}

int main(int ac, char **av)
{
    char flag[20];
    char flag2[20];
    int ac_flagless = ac;
    int result = 0;

    for (int i = 0; i != 5; i++) {
        flag[i] = 0;
        flag2[i] = 0;
    }
    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-') {
            my_strcat(flag, av[i]);
            ac_flagless = ac_flagless - 1;
        }
    }
    better_flag(flag2, flag);
    result = ls_handler(ac_flagless, av, flag2, result);
    if (result > 84)
        result = 84;
    return result;
}
