/*
** EPITECH PROJECT, 2025
** grp.c
** File description:
** grp
*/

#include "../include/proto.h"

int check_grp(char *username)
{
    char *line = find_in_file("/etc/group", "sudo");

    if (line != NULL) {
        if (find_in_string(line, username) == -1) {
            printf("%s is not in the sudoers file.\n", username);
            return 1;
        }
    }
    return 0;
}
