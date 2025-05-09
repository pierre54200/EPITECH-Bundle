/*
** EPITECH PROJECT, 2025
** cd.c
** File description:
** cd
*/

#include "../../include/proto.h"

static void last_dir(shell_t *shell)
{
    char *buff = bmalloc(sizeof(char) * 1000);
    size_t size = 1000;

    getcwd(buff, size);
    shell->cd = my_strdup(buff);
    free(buff);
}

static int permission_denied(char *path, shell_t *shell)
{
    if (access(path, F_OK) == 0 && access(path, X_OK) != 0) {
        my_puts(path);
        my_puts(": Permission denied.\n");
        shell->exit = 2;
        return 1;
    }
    return 0;
}

static int check_dir(char *path, shell_t *shell)
{
    DIR *dir;

    dir = opendir(path);
    if (dir == NULL) {
        if (permission_denied(path, shell) == 1)
            return 1;
        if (access(path, X_OK) == 0) {
            my_puts(path);
            my_puts(": Not a directory.\n");
            shell->exit = 2;
            return 1;
            }
        my_puts(path);
        my_puts(": No such file or directory.\n");
        shell->exit = 2;
        return 1;
    }
    closedir(dir);
    return 0;
}

int cd_dash(char *stock, shell_t *shell)
{
    char *cd = shell->cd;

    if (stock[0] == '-') {
        if (shell->cd == NULL)
            return 1;
        last_dir(shell);
        chdir(cd);
        return 1;
    }
    return 0;
}

void cd_two(char **stock, shell_t *shell)
{
    char *buff = bmalloc(sizeof(char) * 1000);
    size_t size = 1000;

    getcwd(buff, size);
    my_strcat(my_strcat(buff, "/"), stock[1]);
    if (check_dir(buff, shell) == 1)
        return;
    last_dir(shell);
    chdir(buff);
    free(buff);
}

void cd_one(char **stock, shell_t *shell)
{
    if (stock[1][0] == '/') {
        if (check_dir(stock[1], shell) == 1)
            return;
        last_dir(shell);
        chdir(stock[1]);
        return;
    }
    if (cd_dash(stock[1], shell) == 1)
        return;
    if (check_dir(stock[1], shell) == 1)
        return;
    cd_two(stock, shell);
}

void cd_empty(shell_t *shell)
{
    last_dir(shell);
    chdir(shell->home);
}

void cd_caster(char **stock, shell_t *shell)
{
    if (my_tablen(stock) > 2) {
        my_puts("cd: Too many arguments.\n");
        shell->exit = 2;
    }
    if (my_tablen(stock) == 1)
        cd_empty(shell);
    if (my_tablen(stock) == 2)
        cd_one(stock, shell);
    free_stock(stock);
}
