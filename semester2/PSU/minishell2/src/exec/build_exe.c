/*
** EPITECH PROJECT, 2025
** build_exe.c
** File description:
** build
*/

#include "proto.h"

static void exiting(char **stock)
{
    if (my_strcmp(stock[0], "exit") == 0 && ((my_tablen(stock) == 1) ||
    (my_tablen(stock) == 2 && is_a_nbr(stock[1]) == 1)))
        my_putstr("exit\n");
    if (my_strcmp(stock[0], "exit") == 0 && my_tablen(stock) == 1)
        exit(0);
    if (my_strcmp(stock[0], "exit") == 0 && my_tablen(stock) == 2
    && is_a_nbr(stock[1]) == 1)
        exit(my_getnbr(stock[1]));
    if (my_strcmp(stock[0], "exit") == 0 && my_tablen(stock) > 2)
        my_putstr("exit : Expression Syntax.\n");
}

static int build_exe_bis(char **stock, shell_t *shell)
{
    if (my_tablen(stock) != 1 && shell->cmd->first->cmd->pipe == 0) {
        shell->exit = 2;
        return 1;
    }
    for (int i = 0; shell->env != NULL && shell->env[i] != 0; i++) {
        if (shell->env[i][0] != 0) {
            my_putstr(shell->env[i]);
            my_putstr("\n");
        }
    }
    return 1;
}

int build_exe(char **stock, shell_t *shell)
{
    exiting(stock);
    if (my_strcmp(stock[0], "cd") == 0) {
        cd_caster(stock, shell);
        return 1;
    }
    if (my_strcmp(stock[0], "setenv") == 0) {
        my_setenv(stock, shell);
        return 1;
    }
    if (my_strcmp(stock[0], "unsetenv") == 0) {
        my_unsetenv(stock, shell);
        return 1;
    }
    if (my_strcmp(stock[0], "env") == 0) {
        build_exe_bis(stock, shell);
        return 1;
    }
    return 0;
}
