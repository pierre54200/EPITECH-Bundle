/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** command_execution
*/

#include "shell_command.h"

const registered_command_t registered_commands[] = {
    {"bg", &builtin_command_bg},
    {"fg", &builtin_command_fg},
    {"jobs", &builtin_command_jobs},
    {"exit", &builtin_command_exit},
    {"env", &builtin_command_env},
    {"setenv", &builtin_command_setenv},
    {"unsetenv", &builtin_command_unsetenv},
    {"cd", &builtin_command_cd},
    {"alias", &builtin_command_alias},
    {"unalias", &builtin_command_unalias},
    {"color", &builtin_prompt_color},
    {"path", &builtin_path}
};

const int registered_command_count =
sizeof(registered_commands) / sizeof(registered_command_t);
