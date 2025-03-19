/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** task02
*/
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int len = 0;
    char *str;

    for (int j = 0; argv[j] != '\0'; j++)
        len = len + my_strlen(argv[j]);
    str = malloc(sizeof(char) * (len + argc + 1));
    for (int j = 0; j != len + argc + 1; j++)
        str[j] = '\0';
    for (; argv[i + 1] != '\0'; i++) {
        my_strcat(str, argv[i]);
        my_strcat(str, "\n");
    }
    my_strcat(str, argv[i]);
    my_strcat(str, "\0");
    return str;
}
