/*
** EPITECH PROJECT, 2024
** flag_r.c
** File description:
** falg_r
*/
#include "include/my.h"
#include "include/proto.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <sys/stat.h>
#include <stdlib.h>

int my_ls_empty_r(char *flag)
{
    if (flag[0] == 'r' && flag[1] == 0)
        return my_ls_flagless(".", 10);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 0)
        return my_ls_flagless(".", 11);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 0)
        return my_ls_flagless(".", 13);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 0)
        return my_ls_flagless(".", 12);
    return my_ls_empty_t(flag);
}

int my_ls_r(char *av, char *flag, int result)
{
    if (flag[0] == 'r' && flag[1] == 0)
        result = result + my_ls_flagless_multi(av, 10);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 0)
        result = result + my_ls_flagless_multi(av, 11);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 0)
        result = result + my_ls_flagless_multi(av, 13);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 0)
        result = result + my_ls_flagless_multi(av, 12);
    result = my_ls_t(av, flag, result);
    return result;
}

int my_ls_one_r(char *av, char *flag, int result)
{
    if (flag[0] == 'r' && flag[1] == 0)
        result = result + my_ls_flagless(av, 10);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 0)
        result = result + my_ls_flagless(av, 11);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 0)
        result = result + my_ls_flagless(av, 13);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 0)
        result = result + my_ls_flagless(av, 12);
    result = my_ls_one_t(av, flag, result);
    return result;
}
