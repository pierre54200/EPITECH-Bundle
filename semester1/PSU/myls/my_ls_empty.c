/*
** EPITECH PROJECT, 2024
** my_ls_empty.c
** File description:
** my_ls_empty.c
*/

#include "include/my.h"
#include "include/proto.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <sys/stat.h>
#include <stdlib.h>

int better_str(char *av2)
{
    if (av2[my_strlen(av2)] != '/')
        my_strcat(av2, "/");
    return 0;
}

void isaflag(char *flag)
{
    for (int i = 0; flag[i] != 0; i++)
        if (flag[i] != 'a' && flag[i] != 'l' && flag[i] != 'R'
        && flag[i] != 'd' && flag[i] != 'r'
        && flag[i] != 't' && flag[i] != '-')
            exit(84);
    return;
}

int my_ls_empty(char *flag)
{
    int result = 0;

    if (flag[0] == 0)
        return my_ls_flagless(".", 0);
    if (flag[0] == 'a' && flag[1] != 'r' && flag[1] != 't')
        return my_ls_flagless(".", 1);
    if (flag[0] == 'l' && flag[1] != 'a' && flag[1] != 'r' && flag[1] != 't')
        return my_ls_flagless(".", 2);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] != 'r' && flag[2] != 't')
        return my_ls_flagless(".", 3);
    result = my_ls_empty_r(flag);
    return result;
}
