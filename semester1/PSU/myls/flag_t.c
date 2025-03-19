/*
** EPITECH PROJECT, 2024
** flag_t.c
** File description:
** flag_t
*/

#include "include/my.h"
#include "include/proto.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include "include/ls.h"
#include <sys/stat.h>
#include <stdlib.h>

int my_ls_empty_t(char *flag)
{
    if (flag[0] == 'r' && flag[1] == 't')
        return my_ls_flagless(".", 30);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 't')
        return my_ls_flagless(".", 31);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 't')
        return my_ls_flagless(".", 33);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 't')
        return my_ls_flagless(".", 32);
    if (flag[0] == 't')
        return my_ls_flagless(".", 20);
    if (flag[0] == 'a' && flag[1] == 't')
        return my_ls_flagless(".", 21);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 't')
        return my_ls_flagless(".", 23);
    if (flag[0] == 'l' && flag[1] == 't')
        return my_ls_flagless(".", 22);
    return 0;
}

int my_ls_t(char *av, char *flag, int result)
{
    if (flag[0] == 'r' && flag[1] == 't')
        result = result + my_ls_flagless_multi(av, 30);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 't')
        result = result + my_ls_flagless_multi(av, 31);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 't')
        result = result + my_ls_flagless_multi(av, 33);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 't')
        result = result + my_ls_flagless_multi(av, 32);
    if (flag[0] == 't')
        result = result + my_ls_flagless_multi(av, 20);
    if (flag[0] == 'a' && flag[1] == 't')
        result = result + my_ls_flagless_multi(av, 21);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 't')
        result = result + my_ls_flagless_multi(av, 23);
    if (flag[0] == 'l' && flag[1] == 't')
        result = result + my_ls_flagless_multi(av, 22);
    return result;
}

int my_ls_one_t(char *av, char *flag, int result)
{
    if (flag[0] == 'r' && flag[1] == 't')
        result = result + my_ls_flagless(av, 30);
    if (flag[0] == 'a' && flag[1] == 'r' && flag[2] == 't')
        result = result + my_ls_flagless(av, 31);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 'r' && flag[3] == 't')
        result = result + my_ls_flagless(av, 33);
    if (flag[0] == 'l' && flag[1] == 'r' && flag[2] == 't')
        result = result + my_ls_flagless(av, 32);
    if (flag[0] == 't')
        result = result + my_ls_flagless(av, 20);
    if (flag[0] == 'a' && flag[1] == 't')
        result = result + my_ls_flagless(av, 21);
    if (flag[0] == 'l' && flag[1] == 'a' && flag[2] == 't')
        result = result + my_ls_flagless(av, 23);
    if (flag[0] == 'l' && flag[1] == 't')
        result = result + my_ls_flagless(av, 22);
    return result;
}
