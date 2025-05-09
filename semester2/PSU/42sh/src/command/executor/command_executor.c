/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** command_executor
*/

#include "shell_command.h"
#include "env.h"
#include "string_utils.h"
#include "my_common.h"

#include <linux/limits.h>
#include <sys/wait.h>
#include <alloca.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int is_executable(const char *path)
{
    struct stat buffer;

    if (stat(path, &buffer) != 0) {
        return 1;
    }
    if (S_ISDIR(buffer.st_mode) || access(path, X_OK) != 0) {
        fprintf(stderr, "%s: Permission denied.\n", path);
        return 2;
    }
    return 0;
}

static int resolve_path(
    const char *path, env_t *env, char *buffer)
{
    char *env_dup = NULL;
    char *token = NULL;

    while (env != NULL && strcmp(env->key, "PATH") != 0)
        env = env->next;
    if (env == NULL)
        return 1;
    env_dup = MY_STRDUPA(env->value);
    for (token = strtok(env_dup, ":"); token; token = strtok(NULL, ":")) {
        strcat(buffer, token);
        strcat(buffer, "/");
        strcat(buffer, path);
        if (is_executable(buffer) == 0)
            return 0;
        memset(buffer, 0, strlen(buffer) - 1);
    }
    return 1;
}

static void handle_error(int error_no, const char *path)
{
    if (error_no == ENOEXEC) {
        fprintf(stderr, "%s: Exec format error. "
            "Binary file not executable.\n", path);
    }
}

static int handle_signal(int status)
{
    int sig = WTERMSIG(status);
    const char *msg = NULL;

    if (sig == SIGSEGV)
        msg = "Segmentation fault";
    else if (sig == SIGFPE)
        msg = "Floating exception";
    else
        msg = "error signal";
    if (WCOREDUMP(status))
        fprintf(stderr, "%s (core dumped)\n", msg);
    else
        fprintf(stderr, "%s\n", msg);
    return 128 + sig;
}

static int set_path_buffer(const char *path, env_t *env, char *buffer)
{
    int path_executable = 0;

    if (strstr(path, "/") == NULL && strstr(path, ".") == NULL) {
        if (resolve_path(path, env, buffer) != 0)
            fprintf(stderr, "%s: Command not found.\n", path);
    } else {
        path_executable = is_executable(path);
        DO_IF(path_executable == 0, strcpy(buffer, path));
        DO_IF(path_executable != 2 && path_executable != 0,
            fprintf(stderr, "%s: Command not found.\n", path));
    }
    if (buffer[0] == 0) {
        return 1;
    }
    return 0;
}

int my_execve(const char *path, char **argv, shell_context_t *context)
{
    char buffer[PATH_MAX + 1] = { 0 };
    int fpid = 0;
    int status = 0;

    if (set_path_buffer(path, context->env, buffer) != 0)
        return 1;
    fpid = fork();
    if (fpid < 0) {
        return -1;
    } else if (fpid == 0) {
        execve(buffer, argv, env_as_array(context->env));
        handle_error(errno, buffer);
        exit(1);
    }
    waitpid(fpid, &status, 0);
    return WIFSIGNALED(status) ? handle_signal(status) : WEXITSTATUS(status);
}
