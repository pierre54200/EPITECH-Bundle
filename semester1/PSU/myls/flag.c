/*
** EPITECH PROJECT, 2024
** flag.c
** File description:
** flag.c
*/
#include "include/my.h"
#include "include/proto.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>

int my_octal_stock(int nb)
{
    char stock[15];
    int nb2 = 0;
    int size = 0;

    for (int i = 0; nb > 0; i++) {
        nb2 = nb % 8;
        stock[i] = nb2 + '0';
        nb = nb / 8;
        size++;
    }
    my_revstr(stock);
    return my_getnbr(stock);
}

static int my_type(const char *str)
{
    struct stat s;

    stat(str, &s);
    switch (s.st_mode & S_IFMT) {
    case S_IFBLK:
    return my_printf("b");
    case S_IFCHR:
    return my_printf("c");
    case S_IFDIR:
    return my_printf("d");
    case S_IFLNK:
    return my_printf("l");
    case S_IFREG:
    return my_printf("-");
    }
    return 0;
}

static int my_permission2(const int nb, const int i)
{
    if ((nb % puissance_10(i)) / puissance_10(i - 1) == 4)
        my_printf("%s", "r--");
    if ((nb % puissance_10(i)) / puissance_10(i - 1) == 3)
        my_printf("%s", "-wx");
    if ((nb % puissance_10(i)) / puissance_10(i - 1) == 2)
        my_printf("%s", "-w-");
    if ((nb % puissance_10(i)) / puissance_10(i - 1) == 1)
        my_printf("%s", "--x");
    if ((nb % puissance_10(i)) / puissance_10(i - 1) == 0)
        my_printf("%s", "---");
    return 0;
}

static int my_permission(const char *str)
{
    struct stat s;
    int nb = 0;

    stat(str, &s);
    nb = my_octal_stock(s.st_mode);
    for (int i = 3; i != 0; i--) {
        if ((nb % puissance_10(i)) / puissance_10(i - 1) == 7)
            my_printf("%s", "rwx");
        if ((nb % puissance_10(i)) / puissance_10(i - 1) == 6)
            my_printf("%s", "rw-");
        if ((nb % puissance_10(i)) / puissance_10(i - 1) == 5)
            my_printf("%s", "r-x");
        my_permission2(nb, i);
    }
    return 0;
}

static int my_link(const char *str)
{
    struct stat s;

    stat(str, &s);
    my_printf(" %d", s.st_nlink);
    return 0;
}

static int my_owner(const char *str, int test)
{
    struct stat s;

    if (test == 1)
        return 0;
    stat(str, &s);
    my_printf(" %s", getpwuid(s.st_uid)->pw_name);
    my_printf(" %s", getgrgid(s.st_gid)->gr_name);
    return 0;
}

static int my_size(const char *str)
{
    struct stat s;

    stat(str, &s);
    my_printf(" %d", s.st_size);
    return 0;
}

static int my_date(const char *str)
{
    struct stat s;
    int test = 0;

    stat(str, &s);
    ctime(&s.st_mtime);
    for (int i = 3; test < 2 && ctime(&s.st_mtime)[i] != 0; i++){
        my_printf("%c", ctime(&s.st_mtime)[i]);
        if (ctime(&s.st_mtime)[i + 1] == ':')
            test++;
    }
    return 0;
}

int flag_l(const char *stock, const int test)
{
    if (test == 2 || test == 3 || test == 12 || test == 13
    || test == 22 || test == 23 || test == 32 || test == 33) {
        my_type(stock);
        my_permission(stock);
        my_link(stock);
        my_owner(stock, 0);
        my_size(stock);
        my_date(stock);
        my_printf(" ");
    }
    return 0;
}
