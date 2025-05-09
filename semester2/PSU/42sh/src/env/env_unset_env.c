/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env_get_env
*/

#include "env.h"
#include "minishell.h"
#include "string_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void free_env_entry(env_t *env)
{
    if (env->value != NULL) {
        free(env->value);
    }
    if (env->key != NULL) {
        free(env->key);
    }
}

static void update_head(
    shell_context_t *context,
    env_t *previous, env_t *env)
{
    if (previous != NULL) {
        previous->next = env->next;
    } else {
        context->env = env->next;
    }
}

int env_unset(shell_context_t *context, const char *key)
{
    env_t *env = context->env;
    env_t *previous = NULL;

    for (; env != NULL; env = env->next) {
        if (strcmp(key, env->key) != 0) {
            previous = env;
            continue;
        }
        free_env_entry(env);
        update_head(context, previous, env);
        free(env);
        return 0;
    }
    return 1;
}
