/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt_formatter
*/

#include "prompt.h"

const prompt_format_t prompt_formatter[] = {
    {"user", &prompt_username_formatter},
    {"exitcode", &prompt_exitcode_formatter},
    {"current_path", &prompt_path_formatter},
    {"time", &prompt_time_formatter},
    {"for", &prompt_timer_formatter},
    {"git", &prompt_git_formatter}
};

const int prompt_formatter_count =
sizeof(prompt_formatter) / sizeof(prompt_format_t);
