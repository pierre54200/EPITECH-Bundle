/*
** EPITECH PROJECT, 2025
** loop.c
** File description:
** loop
*/

#include "proto.h"

static int is_in_usr(char *str, char *name)
{
    char home[7] = "/home/";
    int i = 0;
    int j = 8;
    int test = 0;

    for (; str[i] == home[i]; i++);
    if (home[i] == 0)
        test = 1;
    for (; test == 1 && str[i] == name[j]; i++)
        j++;
    if (name[j + 1] == 0)
        return i;
    return -1;
}

static void actualdir(char *name)
{
    char *buff = bmalloc(sizeof(char) * 1000);
    size_t size = 1000;
    int i = -1;

    getcwd(buff, size);
    i = is_in_usr(buff, name);
    if (i != -1) {
        my_putstr("~");
        my_putnstr(buff, i);
    } else
        my_putstr(buff);
    free(buff);
}

static void yepper(shell_t *shell)
{
    if (shell->exit != 0) {
        my_putstr("🔴 ");
        my_putstr(AC_RED);
        my_putstr("[");
        my_put_nbr(shell->exit);
        my_putstr("] ");
    } else {
        my_putstr("🟢 ");
        my_putstr(AC_GREEN);
        my_putstr("[");
        my_put_nbr(shell->exit);
        my_putstr("] ");
    }
}

int loop(char **env, shell_t *shell)
{
    char *name = find_in_tab(env, "LOGNAME", 0);
    char *log = find_in_tab(env, "SESSION_MANAGER", 0);

    if (name != NULL) {
        yepper(shell);
        my_putstr(AC_GREEN);
        my_putnstr(name, 8);
        my_putstr("@");
        my_puttostr(log, 22, ':');
        my_putstr(AC_NORMAL);
        my_putstr(":");
        my_putstr(AC_BLUE);
        actualdir(name);
        my_putstr(AC_NORMAL);
        my_putstr("$> ");
        return 0;
    }
    my_putstr("$> ");
    return 0;
}
