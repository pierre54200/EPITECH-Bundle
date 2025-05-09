/*
** EPITECH PROJECT, 2025
** find_in_env.c
** File description:
** find_in_env
*/

#include "prompt.h"
#include "string_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "env.h"
#include <stdio.h>
#include <string.h>

char *find_in_env(shell_context_t *context, const char *str)
{
    shell_context_t temp = *context;

    if (temp.env == NULL || str == NULL)
        return NULL;
    while (temp.env != NULL) {
        if (strcmp(temp.env->key, str) == 0)
            return temp.env->value;
        temp.env = temp.env->next;
    }
    return NULL;
}
