/*
** EPITECH PROJECT, 2025
** find_in_file.c
** File description:
** find_str_in_file
*/
#include "../include/proto.h"

char *find_in_file(char *path, char *str)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if (file == NULL)
        return NULL;
    nread = getline(&line, &len, file);
    while (nread != -1){
        if (find_in_string(line, str) != -1)
            return line;
        nread = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    return NULL;
}
