/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** myenv
*/

#ifndef MYENV_H
    #define MYENV_H

    #include "my_common.h"
    #include <stdint.h>

typedef struct env {
    char *key;
    char *value;
    struct env *next;
} env_t;

int env_load(shell_context_t *context, char **env);
void env_free(shell_context_t *context);

char *env_get(shell_context_t *context, const char *key);
int env_set(shell_context_t *context, const char *key, const char *value);
int env_unset(shell_context_t *context, const char *key);

char **env_as_array(env_t *env);
char *find_in_env(shell_context_t *context, const char *str);
#endif /* !MYENV_H_ */
