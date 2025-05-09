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

static int add_new(env_t **head, const char *key, const char *value)
{
    env_t *new_head = malloc(sizeof(env_t));

    if (head == NULL)
        return 84;
    new_head->key = strdup(key);
    new_head->value = strdup(value);
    new_head->next = *head;
    (*head) = new_head;
    return 0;
}

int env_set(shell_context_t *context, const char *key, const char *value)
{
    env_t *env = context->env;

    for (; env != NULL; env = env->next) {
        if (strcmp(key, env->key) != 0)
            continue;
        if (env->value != NULL)
            free(env->value);
        env->value = strdup(value);
        return env->value != NULL;
    }
    add_new(&context->env, key, value);
    return 1;
}
