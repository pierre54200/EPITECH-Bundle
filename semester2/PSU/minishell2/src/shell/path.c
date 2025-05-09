/*
** EPITECH PROJECT, 2025
** path.c
** File description:
** path
*/

#include "proto.h"

static char **get_paths_bis(char *path, char **stock_path)
{
    int j = 0;

    if (stock_path == NULL)
        return NULL;
    for (int i = 5; path[i] != 0; i++) {
        if (path[i - 1] == ':' || path[i - 1] == '=') {
            stock_path[j] = my_strntdup(path, i, ':');
            j++;
        }
    }
    stock_path[j] = 0;
    return stock_path;
}

char **get_paths(char **env)
{
    int len = 0;
    char *path = find_in_tab(env, "PATH", 0);
    char **stock_path;

    if (path == NULL)
        return NULL;
    for (int i = 0; path[i] != 0; i++) {
        if (path[i] == ':')
            len++;
    }
    stock_path = malloc(sizeof(char *) * (len + 2));
    if (stock_path == NULL)
        return NULL;
    get_paths_bis(path, stock_path);
    return stock_path;
}
