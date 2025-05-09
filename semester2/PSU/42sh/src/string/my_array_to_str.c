/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** Transform char ** to char *
*/

#include "string_utils.h"

#include <string.h>
#include <stdlib.h>

/* Return 1 for space */
static int count_all_str(char **warray)
{
    int sum = 0;

    for (int i = 0; warray[i]; i++) {
        sum += strlen(warray[i]) + 1;
    }
    return sum;
}

char *my_array_to_str(char **warray)
{
    int count = count_all_str(warray);
    char *str = malloc(sizeof(char) * (count + 1));

    for (int i = 0; warray[i]; i++) {
        if (!i) {
            strcpy(str, warray[i]);
        } else {
            strcat(str, warray[i]);
        }
        strcat(str, " ");
    }
    str[count] = '\0';
    return str;
}
