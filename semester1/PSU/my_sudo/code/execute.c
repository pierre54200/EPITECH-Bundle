/*
** EPITECH PROJECT, 2025
** execute.c
** File description:
** exe
*/

#include "../include/proto.h"
#include <pwd.h>


int check_command(char **argv)
{
    if (strcmp(argv[1], "-h") != 1
    && strcmp(argv[1], "-u") != 1
    && strcmp(argv[1], "-g") != 1
    && strcmp(argv[1], "-E") != 1
    && strcmp(argv[1], "-s") != 1)
        return 1;
    return 0;
}

int execute(char **argv)
{
    char *file = bmalloc(8 + strlen(argv[1]));

    if (file == NULL)
        return 84;
    if (argv[1][0] == '/') {
        if (execvp(argv[1], argv + 1) == -1)
            return 84;
        return 0;
    }
    sprintf(file, "/bin/%s", argv[1]);
    if (execvp(file, argv + 1) == -1)
        return 84;
    free(file);
    return 0;
}
