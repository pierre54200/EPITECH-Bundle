/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env_get_env
*/

#include "env.h"
#include "string_utils.h"
#include "minishell.h"

#include <string.h>

char *env_get(shell_context_t *context, const char *key)
{
    env_t *env = context->env;

    for (; env; env = env->next) {
        if (strcmp(key, env->key) != 0)
            continue;
        return env->value;
    }
    return NULL;
}
