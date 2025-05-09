/*
** EPITECH PROJECT, 2025
** init_stdin.c
** File description:
** init_in
*/

#include "proto.h"

void init_stdin(cmd_t *cmd, char **str)
{
    int begin = 0;
    int size = 0;

    cmd->stdin = counter(*str, "<") - 1;
    if (cmd->stdin > 2 || cmd->stdin <= 0) {
        cmd->stdin_str = "/dev/stdin";
        return;
    }
    begin = first_sign(*str, '<');
    cmd->stdin_str = dup_part(*str, begin + cmd->stdin, &size, " >|");
    *str = del_part(*str, begin, size + cmd->stdin);
    if (my_strlen(cmd->stdin_str) == 0)
        cmd->stdin_str = NULL;
}
