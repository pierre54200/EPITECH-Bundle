/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** command_cd
*/

#include "minishell.h"
#include "env.h"
#include "string_utils.h"
#include "shell_command.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <linux/limits.h>
#include <errno.h>
#include "shell_command.h"

static int update_current_path(shell_context_t *context, const char *new_path)
{
    char buffer[PATH_MAX + 1] = { 0 };
    char *message = 0;

    getcwd(buffer, PATH_MAX);
    if (chdir(new_path) != 0) {
        message = strerror(errno);
        fprintf(stderr, "%s: %s.\n", new_path, message);
        return 1;
    }
    env_set(context, "OLDPWD", buffer);
    return 0;
}

static int home_command_cd(shell_context_t *context)
{
    char *home_path = env_get(context, "HOME");

    if (home_path == NULL) {
        fprintf(stderr, "mysh: cd: HOME not set\n");
        return 1;
    }
    return update_current_path(context, home_path);
}

static int minus_command_cd(shell_context_t *context)
{
    char *oldpath = env_get(context, "OLDPWD");

    if (oldpath == NULL) {
        fprintf(stderr, "mysh: cd: OLDPWD not set\n");
        return 1;
    }
    return update_current_path(context, oldpath);
}

int builtin_command_cd(int argc, char **argv, shell_context_t *context)
{
    if (argc > 2) {
        fprintf(stderr, "cd: Too many arguments.\n");
        return 1;
    }
    if (argc == 1 || strcmp(argv[1], "~") == 0)
        return home_command_cd(context);
    if (strcmp(argv[1], "-") == 0)
        return minus_command_cd(context);
    return update_current_path(context, argv[1]);
}
