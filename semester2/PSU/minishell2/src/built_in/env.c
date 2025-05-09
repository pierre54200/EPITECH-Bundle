/*
** EPITECH PROJECT, 2025
** env.c
** File description:
** env
*/

#include "proto.h"

static char **more_env(char *new, shell_t *shell)
{
    int len = my_tablen(shell->env);
    char **new_env = malloc(sizeof(char *) * (len + 2));
    int i = 0;

    if (shell->env == NULL) {
        new_env[0] = my_strdup(new);
        return new_env;
    }
    for (; i != len + 1; i++) {
        if (shell->env[i] != NULL)
            new_env[i] = my_strdup(shell->env[i]);
        else
            new_env[i] = my_strdup(new);
    }
    new_env[i] = NULL;
    free_env(shell);
    return new_env;
}

static void my_newsetenv(char **stock, shell_t *shell)
{
    char *temp;
    char *tempo;

    if (my_tablen(stock) == 2) {
        temp = my_strcot(stock[1], "=");
        shell->env = more_env(temp, shell);
        free(temp);
    }
    if (my_tablen(stock) == 3) {
        temp = my_strcot(stock[1], "=");
        tempo = my_strcot(temp, stock[2]);
        shell->env = more_env(tempo, shell);
        free(temp);
        free(tempo);
    }
    free_path(shell);
    shell->path = get_paths(shell->env);
}

static void my_alrsetenv_size_three(char **stock, shell_t *shell, int i)
{
    char *temp;
    char *tempo;

    if (my_tablen(stock) == 3) {
        temp = my_strcot(stock[1], "=");
        if (temp == NULL)
            return;
        tempo = my_strcot(temp, stock[2]);
        if (tempo == NULL) {
            free(temp);
            return;
        }
        free(shell->env[i]);
        shell->env[i] = my_strdup(tempo);
        free(temp);
        free(tempo);
    }
}

static void my_alrsetenv(char **stock, shell_t *shell, int i)
{
    char *temp;

    if (my_tablen(stock) == 2) {
        temp = my_strcot(stock[1], "=");
        if (temp == NULL)
            return;
        free(shell->env[i]);
        shell->env[i] = my_strdup(temp);
        free(temp);
    }
    my_alrsetenv_size_three(stock, shell, i);
    if (shell->env[i] == NULL)
        return;
    free_path(shell);
    shell->path = get_paths(shell->env);
}

void my_setenvbis(char **stock, shell_t *shell)
{
    int i = find_in_tab_line(shell->env, stock[1], 0);

    if (i != -1)
        my_alrsetenv(stock, shell, i);
    if (i == -1)
        my_newsetenv(stock, shell);
}

int check_setenv(char **stock)
{
    if (is_a_char(stock[1][0]) != 1) {
        my_puts("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; stock[1][i] != 0; i++) {
        if (is_a_char(stock[1][i]) == 0) {
            my_puts("setenv: Variable name must contain ");
            my_puts("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

void my_setenv(char **stock, shell_t *shell)
{
    if (my_tablen(stock) > 3) {
        my_puts("setenv: Too many arguments.\n");
        return;
    }
    if (my_tablen(stock) == 1) {
        for (int i = 0; shell->env[i] != 0; i++) {
            my_putstr(shell->env[i]);
            my_putstr("\n");
        }
        return;
    }
    if (check_setenv(stock) == 1)
        return;
    my_setenvbis(stock, shell);
}

int my_unseterror(char **stock)
{
    if (my_tablen(stock) > 2) {
        my_puts("unsetenv: Too many arguments.\n");
        return 1;
    }
    if (my_tablen(stock) < 2) {
        my_puts("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}

void my_unsetenv(char **stock, shell_t *shell)
{
    int i = 0;

    if (my_unseterror(stock) == 1)
        return;
    i = find_in_tab_line(shell->env, stock[1], 0);
    if (i < 0) {
        return;
    }
    for (int j = 0; shell->env[i][j] != 0; j++)
        shell->env[i][j] = 0;
    if (my_strcmp(stock[1], "PATH") == 0) {
        for (int i = 0; shell->path[i] != 0; i++)
            shell->path[i][0] = 'c';
    }
}
