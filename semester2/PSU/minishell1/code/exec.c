/*
** EPITECH PROJECT, 2025
** exec.c
** File description:
** exec
*/

#include "../include/proto.h"


static void format_error(char *av, shell_t *shell)
{
    DIR *dir = opendir(av);

    if (dir != NULL) {
        closedir(dir);
        return;
    }
    closedir(dir);
    my_puts(av);
    my_puts(": Exec format error. Wrong Architecture.\n");
    shell->exit = 2;
    exit(2);
}

void exec_path(char **av, shell_t *shell)
{
    DIR *dir;
    char *path;

    for (int i = 0; shell->path[i] != 0; i++) {
        dir = opendir(shell->path[i]);
        if (dir != NULL) {
            path = my_strcat(my_strcat(shell->path[i], "/"), av[0]);
            execve(path, av, shell->env);
        }
    }
}

void error_exe(int waitime, shell_t *shell)
{
    if (WIFSIGNALED(waitime)) {
        if (WTERMSIG(waitime) == SIGFPE)
            my_puts("Floting exception");
        if (WTERMSIG(waitime) == SIGSEGV)
            my_puts("Segmentation fault");
        if (WCOREDUMP(waitime)) {
            my_puts(" (core dumped)");
        } else
            write(2, "1\n", 2);
        shell->exit = 2;
        my_puts("\n");
        return;
    }
    if (waitime != 0)
        shell->exit = 2;
}

void execute_in_child(char **av, shell_t *shell)
{
    if (av[0][0] == '/') {
        execve(av[0], av, shell->env);
    } else {
        execve(av[0], av, shell->env);
        exec_path(av, shell);
    }
    if (access(av[0], F_OK) == 0) {
        format_error(av[0], shell);
        my_puts(av[0]);
        my_puts(": Permission denied.\n");
        shell->exit = 2;
        exit(2);
    }
    my_puts(av[0]);
    my_puts(": Command not found.\n");
    shell->exit = 2;
    exit(2);
}

int exec(char **av, shell_t *shell)
{
    pid_t pid = fork();
    int waitime;

    if (pid < 0)
        return 0;
    if (pid == 0) {
        execute_in_child(av, shell);
    }
    if (pid > 0) {
        wait(&waitime);
        error_exe(waitime, shell);
    }
    return 0;
}
