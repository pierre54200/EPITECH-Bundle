/*
** EPITECH PROJECT, 2025
** free.c
** File description:
** free
*/

#include "proto.h"

void free_everything(shell_t *shell)
{
    for (int i = 0; shell->env[i] != 0; i++)
        free(shell->env[i]);
    for (int i = 0; shell->path[i] != 0; i++)
        free(shell->path[i]);
    free(shell->env);
    free(shell->path);
    free(shell->home);
    free(shell->cd);
}

void free_env(shell_t *shell)
{
    for (int i = 0; shell->env[i] != 0; i++)
        free(shell->env[i]);
    free(shell->env);
}

void free_path(shell_t *shell)
{
    if (shell->path == NULL)
        return;
    for (int i = 0; shell->path[i] != 0; i++)
        free(shell->path[i]);
    free(shell->path);
}

void free_cmd(shell_t *shell)
{
    list_node_t *temp;

    while (shell->cmd->first != NULL) {
        temp = shell->cmd->first;
        shell->cmd->first = shell->cmd->first->next;
        free(temp);
    }
    free(shell->cmd);
}

void free_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++)
        free(tab[i]);
    free(tab);
}
