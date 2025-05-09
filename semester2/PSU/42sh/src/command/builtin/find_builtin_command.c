/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** find_command
*/

#include "shell_command.h"
#include "string_utils.h"
#include <stdio.h>
#include <string.h>

registered_command_t find_builtin_command(const char *name)
{
    registered_command_t command = { 0 };

    for (int i = 0; i < registered_command_count; i++) {
        command = registered_commands[i];
        if (strcmp(command.command, name) == 0) {
            return command;
        }
    }
    return (registered_command_t) { 0 };
}
