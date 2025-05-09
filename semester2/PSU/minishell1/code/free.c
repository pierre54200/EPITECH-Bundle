/*
** EPITECH PROJECT, 2025
** free.c
** File description:
** free
*/

#include "../include/proto.h"

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
    for (int i = 0; shell->path[i] != 0; i++)
        free(shell->path[i]);
    free(shell->path);
}

void free_stock(char **stock)
{
    int i = 0;

    for (; stock[i] != NULL; i++)
        free(stock[i]);
    free(stock);
}
