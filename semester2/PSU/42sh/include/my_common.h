/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** my_common
*/

#ifndef MY_COMMON_H
    #define MY_COMMON_H

    #include <unistd.h>
    #include <stdlib.h>

    #define STDIN_FD 0
    #define STDOUT_FD 1
    #define STDERR_FD 2

    #define IF_IS_TTY(x) ((isatty(STDOUT_FD) && isatty(STDERR_FD)) ? x : 0)

    #define DO_IF(c, t) ((c) ? (t) : 0)

    #define FREE_IF(c, p) ((c) ? free(p) : 0)
    #define FREE_IF_NOT(c, p) ((c) ? 0 : free(p))

typedef unsigned char exitcode_t;

typedef struct shell_context shell_context_t;
typedef struct env env_t;
typedef struct ast ast_t;
typedef struct aliases aliases_t;

#endif /* !MY_COMMON_H */
