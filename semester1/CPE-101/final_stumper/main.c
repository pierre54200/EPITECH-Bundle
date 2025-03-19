/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include <unistd.h>
#include "rush3.h"
int main(void)
{
    char buff[4096 + 1];
    int offset = 0;

    for (int len = 1; len > 0; offset = offset + len) {
        if (offset > 4096) {
            rush3_error(buff);
            return 84;
        }
        len = read(0, buff + offset, 2 * 4096 - offset);
    }
    buff[offset] = '\0';
    rush3(buff);
    return 0;
}
