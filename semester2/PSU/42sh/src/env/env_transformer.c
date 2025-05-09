/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** env_loader
*/

#include "env.h"
#include "string_utils.h"
#include "minishell.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static size_t get_env_len(env_t *env)
{
    return strlen(env->key) +
            strlen("=") +
            strlen(env->value);
}

static uint32_t count_total_env(env_t *env)
{
    uint32_t count = 0;

    for (; env != NULL; count++) {
        env = env->next;
    }
    return count;
}

static void destroy_env_array(char **env)
{
    if (env == NULL) {
        return;
    }
    for (uint32_t i = 0; env[i] != NULL; i++) {
        free(env[i]);
    }
    free(env);
}

static char *build_current_env(env_t *env)
{
    size_t env_len = get_env_len(env);
    char *new_env = malloc(sizeof(char) * (env_len + 1));

    if (new_env == NULL)
        return NULL;
    new_env[0] = '\0';
    strcat(new_env, env->key);
    strcat(new_env, "=");
    strcat(new_env, env->value);
    return new_env;
}

static char **build_env(
    env_t *env, uint32_t env_size, char **env_buffer)
{
    char *new_env = NULL;

    for (uint32_t i = 0; i < env_size && env != NULL; i++) {
        new_env = build_current_env(env);
        if (new_env == NULL) {
            destroy_env_array(env_buffer);
            return NULL;
        }
        env_buffer[i] = new_env;
        env = env->next;
    }
    return env_buffer;
}

char **env_as_array(env_t *env)
{
    uint32_t env_size = count_total_env(env);
    char **env_buffer = NULL;

    if (env_size == 0)
        return NULL;
    env_buffer = malloc(sizeof(char *) * (env_size + 1));
    if (env_buffer == NULL)
        return NULL;
    for (uint32_t i = 0; i <= env_size; i++) {
        env_buffer[i] = NULL;
    }
    return build_env(env, env_size, env_buffer);
}
