/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** prompt
*/

#ifndef PROMPT_H_
    #define PROMPT_H_

    #define AC_GREEN "\033[1;32m"
    #define AC_BLUE "\033[1;34m"
    #define AC_NORMAL "\x1b[m"
    #define AC_RED "\033[1;31m"
    #define AC_YELLOW "\033[1;33m"
    #define TIME 10

    #include "my_common.h"
    #include <stdbool.h>

char *prompt_ask_user(shell_context_t *context);
char *prompt_get_input(bool should_clean, bool should_show_exit_message);

/*******************/
/*    FORMATTER    */
/*******************/

void prompt_show_formatted(shell_context_t *context, char *prompt);

typedef struct {
    char *placeholder;
    char *(*parser)(shell_context_t *context);
} prompt_format_t;

extern const prompt_format_t prompt_formatter[];
extern const int prompt_formatter_count;

char *prompt_username_formatter(shell_context_t *context);
char *prompt_exitcode_formatter(shell_context_t *context);
char *prompt_path_formatter(shell_context_t *context);
char *prompt_time_formatter(shell_context_t *context);
char *prompt_timer_formatter(shell_context_t *context);
char *prompt_git_formatter(shell_context_t *context);
#endif /* !PROMPT_H_ */
