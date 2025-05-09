/*
** EPITECH PROJECT, 2025
** prompt_git_formatter.c
** File description:
** git formatter
*/

#include "minishell.h"
#include "prompt.h"
#include <libgen.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/limits.h>

static char *git_branch_formatter(void)
{
    FILE *file = fopen("./.git/HEAD", "r");
    char *line = NULL;
    char *git = NULL;
    ssize_t nread = 0;
    size_t read = 0;

    if (file == NULL)
        return NULL;
    nread = getline(&line, &read, file);
    fclose(file);
    if (nread <= 0)
        return NULL;
    git = strstr(line, "heads") + 6;
    git[strlen(git) - 1] = 0;
    git = strdup(git);
    free(line);
    return git;
}

char *prompt_git_formatter(shell_context_t *context)
{
    char *branch = NULL;
    char *git = git_branch_formatter();

    if (git == NULL)
        return strdup("");
    if (git != NULL)
        asprintf(&branch, "%s-> ⎇ %s%s", context->git_color, git, AC_NORMAL);
    free(git);
    return branch;
}
