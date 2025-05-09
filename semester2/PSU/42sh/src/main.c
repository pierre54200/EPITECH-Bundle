/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** main
*/

#include "minishell.h"
#include "env.h"
#include "string_utils.h"
#include "prompt.h"
#include <string.h>
#include "alias.h"

#include <stdio.h>
#include <stdlib.h>

static void init_shell(shell_context_t *c)
{
    c->time = 0;
    c->timer = 0;
    c->prompt_format = "[%exitcode] %time %user:%current_path %git %for ";
    c->time_color = strdup(AC_NORMAL);
    c->timer_color = strdup(AC_NORMAL);
    c->user_color = strdup(AC_GREEN);
    c->git_color = strdup(AC_YELLOW);
    c->path_color = strdup(AC_BLUE);
    c->whole_path = false;
    c->is_wait = true;
    c->jobs = (job_t *) 0;
}

static void free_color(shell_context_t *context)
{
    free(context->time_color);
    free(context->timer_color);
    free(context->user_color);
    free(context->git_color);
    free(context->path_color);
}

int main(int, const char *const *, char **env)
{
    shell_context_t context = { 0 };
    int shell_exitcode = 0;

    init_shell(&context);
    if (env_load(&context, env) != 0) {
        fprintf(stderr, "Unable to load env!\n");
        return 84;
    }
    shell_exitcode = shell(&context);
    alias_destroy(context.aliases);
    clear_jobs(context.jobs);
    env_free(&context);
    free_color(&context);
    return shell_exitcode;
}
