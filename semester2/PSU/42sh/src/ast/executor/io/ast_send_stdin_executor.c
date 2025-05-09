/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_send_stdin_executor
*/

#include "ast.h"
#include "prompt.h"
#include "string_utils.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

static void execute_process(int pipefd[2], ast_t *self)
{
    close(pipefd[1]);
    if (dup2(pipefd[0], STDIN_FD) == -1)
        exit(84);
    close(pipefd[0]);
    exit(ast_exec(self->right));
}

static bool is_eof_token(char *input, char *eof_token)
{
    char *c_input = MY_STRDUPA(input);

    if (c_input[0] != '\0' && c_input[strlen(c_input) - 1] == '\n') {
        c_input[strlen(c_input) - 1] = 0;
    }
    return strcmp(c_input, eof_token) == 0;
}

static char *get_input(char *eof_token)
{
    char *input = strdup("");
    char *tmp = NULL;

    while (1) {
        fprintf(stderr, "? ");
        tmp = prompt_get_input(false, false);
        if (tmp == NULL || is_eof_token(tmp, eof_token)) {
            break;
        }
        input = realloc(input, strlen(input) + strlen(tmp) + 1);
        strcat(input, tmp);
        free(tmp);
    }
    free(tmp);
    return input;
}

static void send_input(int pipefd[2], char *input)
{
    close(pipefd[0]);
    write(pipefd[1], input, strlen(input));
    free(input);
    close(pipefd[1]);
}

static int handle_fork(int pipefd[2], ast_t *self, char *input)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        return 84;
    } else if (pid == 0) {
        execute_process(pipefd, self);
    }
    send_input(pipefd, input);
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}

exitcode_t ast_send_stdin_executor(ast_t *self)
{
    char *input = NULL;
    int pipefd[2] = { 0 };

    if (pipe(pipefd) == -1)
        return 84;
    input = get_input(NODE_TOKEN(self->left).token_literal.value[0]);
    if (input == NULL) {
        close(pipefd[0]);
        close(pipefd[1]);
        return 84;
    }
    return handle_fork(pipefd, self, input);
}
