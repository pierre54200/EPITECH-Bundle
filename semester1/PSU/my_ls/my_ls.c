/*
** EPITECH PROJECT, 2024
** my_ls.c
** File description:
** my_ls
*/

#include "include/my.h"
#include "include/proto.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <sys/stat.h>
#include <stdlib.h>

static int clear_str(char *av2)
{
    for (int i = 0; av2[i] != 0; i++) {
        av2[i] = 0;
    }
    return 0;
}

static int my_total(char **stock, char *av, char *av2, int test)
{
    struct stat s;
    int result = 0;

    for (int i = 0; stock[i] != 0; i++) {
        if (stock[i][0] != '.' || test == 3 || test == 13
        || test == 23 || test == 33) {
            my_strcat(av2, av);
            better_str(av2);
            my_strcat(av2, stock[i]);
            stat(av2, &s);
            result = result + s.st_blocks;
            clear_str(av2);
        }
    }
    return result / 2;
}

static int display_char_dir(char **stock, int test, char *av)
{
    char av2[100];

    for (int i = 0; i != 100; i++)
        av2[i] = 0;
    if (test == 2 || test == 3 || test == 12 || test == 13
    || test == 22 || test == 23 || test == 32 || test == 33)
        my_printf("total %d\n", my_total(stock, av, av2, test));
    for (int i = 0; stock[i] != 0; i++) {
        if (stock[i][0] != '.' || test == 1 || test == 3
        || test == 11 || test == 13 || test == 21 || test == 23
        || test == 31 || test == 33) {
            my_strcat(av2, av);
            better_str(av2);
            my_strcat(av2, stock[i]);
            flag_l(av2, test);
            my_printf("%s\n", stock[i]);
            clear_str(av2);
            }
    }
    return 0;
}

static int create_char_dir(char *av, DIR *dir, int test)
{
    struct dirent *entry;
    char **stock;
    int i = 0;
    struct stat s;

    stat(av, &s);
    stock = malloc(sizeof(char **) * (s.st_size + 1));
    entry = readdir(dir);
    for (; entry != 0; entry = readdir(dir)) {
        stock[i] = entry->d_name;
        i++;
    }
    stock[i] = 0;
    order(stock, test);
    display_char_dir(stock, test, av);
    free(stock);
    return 0;
}

static int my_name(char *str)
{
    int i = 0;
    char cpy[my_strlen(str) + 2];

    my_revstr(str);
    if (str[0] == '/') {
        i++;
        cpy[0] = '/';
    }
    for (; str[i] != 0 && str[i] != '/'; i++)
        cpy[i] = str[i];
    cpy[i] = 0;
    my_revstr(cpy);
    my_revstr(str);
    return my_putstr(cpy);
}

int my_ls_flagless_multi(char *av, int test)
{
    DIR *dir;

    if (av[0] == '-')
        return 0;
    dir = opendir(av);
    if (dir == 0) {
        flag_l(av, test);
        my_name(av);
        return my_printf("\n") - 1;
    }
    my_name(av);
    my_printf(":\n");
    create_char_dir(av, dir, test);
    closedir(dir);
    my_printf("\n");
    return 0;
}

int my_ls_flagless(char *av, int test)
{
    DIR *dir;

    if (av[0] == '-')
        return 0;
    dir = opendir(av);
    if (dir == 0) {
        flag_l(av, test);
        my_name(av);
        closedir(dir);
        return my_printf("\n") * 0;
    }
    create_char_dir(av, dir, test);
    closedir(dir);
    return 0;
}

int my_ls(char **av, char *flag, int result)
{
    struct stat s;

    for (int i = 1; av[i] != 0; i++) {
        stat(av[i], &s);
        if (my_octal_stock(s.st_mode) / 100 % 10 < 4 && av[i][0] != '-') {
            result = 84;
            continue;
        }
        s.st_mode = 0;
        if (flag[0] == 0)
            result = result + my_ls_flagless_multi(av[i], 0);
        if (flag[0] == 'a' && flag[1] == 0)
            result = result + my_ls_flagless_multi(av[i], 1);
        if (flag[0] == 'l' && flag[1] == 0)
            result = result + my_ls_flagless_multi(av[i], 2);
        if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 0)
            result = result + my_ls_flagless_multi(av[i], 3);
        result = result + my_ls_r(av[i], flag, result);
    }
    return result;
}

int my_ls_one(char **av, char *flag, int result)
{
    struct stat s;

    for (int i = 1; av[i] != 0; i++) {
        stat(av[i], &s);
        if (my_octal_stock(s.st_mode) / 100 % 10 < 4 && av[i][0] != '-') {
            result = 84;
            continue;
        }
        if (flag[0] == 0)
            result = result + my_ls_flagless(av[i], 0);
        if (flag[0] == 'a' && flag[1] == 0)
            result = result + my_ls_flagless(av[i], 1);
        if (flag[0] == 'l' && flag[1] != 'a' && flag[1] == 0)
            result = result + my_ls_flagless(av[i], 2);
        if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 0)
            result = result + my_ls_flagless(av[i], 3);
        result = result + my_ls_one_r(av[i], flag, result);
    }
    return result;
}
