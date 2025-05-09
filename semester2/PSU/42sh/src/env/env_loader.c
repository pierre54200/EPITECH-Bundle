/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** env_loader
*/

#include "env.h"
#include "minishell.h"
#include "string_utils.h"

#include <stdlib.h>
#include <string.h>

static int add_next(shell_context_t *context, char *env)
{
    env_t *head = malloc(sizeof(env_t));
    char *value_ptr = NULL;

    if (head == NULL)
        return 84;
    env = MY_STRDUPA(env);
    value_ptr = strstr(env, "=");
    *value_ptr = 0;
    head->key = strdup(env);
    head->value = strdup(value_ptr + 1);
    head->next = context->env;
    context->env = head;
    if (head->key == NULL || head->value == NULL)
        return 84;
    return 0;
}

int env_load(shell_context_t *context, char **env)
{
    if (env == NULL) {
        return 0;
    }
    for (; (*env) != NULL; env++) {
        if (add_next(context, *env) != 0) {
            env_free(context);
            return 84;
        }
    }
    return 0;
}
