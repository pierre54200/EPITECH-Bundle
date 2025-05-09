/*
** EPITECH PROJECT, 2025
** init_stdout.c
** File description:
** init_out
*/

#include "proto.h"

void init_stdout(cmd_t *cmd, char **str)
{
    int begin = 0;
    int size = 0;

    cmd->stdout = counter(*str, ">") - 1;
    if (cmd->stdout > 2 || cmd->stdout <= 0) {
        cmd->stdout_str = "/dev/stdout";
        return;
    }
    begin = first_sign(*str, '>');
    cmd->stdout_str = dup_part(*str, begin + cmd->stdout, &size, " <|");
    if (cmd->stdout_str == NULL)
        return;
    *str = del_part(*str, begin, size + cmd->stdout);
    if (str == NULL)
        return;
    if (my_strlen(cmd->stdout_str) == 0)
        cmd->stdout_str = NULL;
}
