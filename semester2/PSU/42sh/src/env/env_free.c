/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** env_loader
*/

#include "env.h"
#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>

static void env_free_entry(env_t *env)
{
    free(env->key);
    free(env->value);
    free(env);
}

void env_free(shell_context_t *context)
{
    env_t *env = context->env;
    env_t *previous_env = NULL;

    while (env != NULL) {
        previous_env = env;
        env = env->next;
        env_free_entry(previous_env);
    }
}
