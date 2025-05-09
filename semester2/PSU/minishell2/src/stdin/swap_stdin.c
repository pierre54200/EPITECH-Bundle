/*
** EPITECH PROJECT, 2025
** swap_stdin.c
** File description:
** stdin
*/

#include "proto.h"

static int my_fdstr(int fd, char *str)
{
    return write(fd, str, my_strlen(str));
}

static int get_stdin_bis(int fd, char *limit)
{
    size_t size = 0;
    ssize_t nread = 0;
    char *buffer = NULL;

    nread = getline(&buffer, &size, stdin);
    if (nread == -1)
        return 0;
    if (my_strcmp(buffer, limit) == 0)
        return -1;
    my_fdstr(fd, buffer);
    free(buffer);
    return 1;
}

static int get_stdin(list_node_t *list)
{
    int fd[2];
    int i = 0;
    char *limit = my_strcat(list->cmd->stdin_str, "\n");

    if (limit == NULL)
        return 84;
    pipe(fd);
    while (1) {
        my_putstr("? ");
        i = get_stdin_bis(fd[1], limit);
        if ((i == 0))
            return 0;
        if (i == -1)
            break;
    }
    free(limit);
    close(fd[1]);
    return fd[0];
}

int swap_stdin(list_node_t *list, int *des, int *fd)
{
    if (list->cmd->stdin > 2 || list->cmd->stdin_str == NULL)
        return 0;
    *des = dup(STDIN_FILENO);
    if (list->cmd->stdin == 2)
        *fd = get_stdin(list);
    if (list->cmd->stdin == 1)
        *fd = open(list->cmd->stdin_str, O_RDONLY, 0666);
    if (list->cmd->stdin == 0)
        *fd = *des;
    dup2(*fd, STDIN_FILENO);
    return 1;
}
