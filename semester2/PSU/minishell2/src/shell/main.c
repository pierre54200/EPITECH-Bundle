/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "proto.h"

static int my_scanf(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    nread = getline(&line, &len, stdin);
    if (nread < 0) {
        free(line);
        free_everything(shell);
        exit(shell->exit);
    }
    if (my_str_isprintable(line) == 1) {
        free(line);
        return 0;
    }
    if (line[0] == '\n') {
        free(line);
        return 0;
    }
    shell->exit = 0;
    return mysh(line, shell);
}

static shell_t create_shell(shell_t shell, char **env)
{
    if (my_tablen(env) == 0) {
        shell.env = NULL;
        shell.path = NULL;
        shell.home = NULL;
        shell.exit = 0;
        shell.cd = NULL;
        return shell;
    }
    shell.test = 0;
    shell.env = my_tabdup(env);
    shell.path = get_paths(env);
    if (find_in_tab(env, "HOME", 0) != NULL)
        shell.home = my_strndup(find_in_tab(env, "HOME", 0), 5);
    else
        shell.home = NULL;
    shell.exit = 0;
    shell.cd = NULL;
    return shell;
}

int main(int ac, char **, char **env)
{
    shell_t shell = create_shell(shell, env);

    if (isatty(0) == 0) {
        while (1) {
            signal(SIGINT, &sigint);
            my_scanf(&shell);
        }
        return shell.exit;
    }
    if (ac != 1)
        return 84;
    while (loop(shell.env, &shell) == 0) {
        signal(SIGINT, &sigint);
        my_scanf(&shell);
    }
    return 0;
}
