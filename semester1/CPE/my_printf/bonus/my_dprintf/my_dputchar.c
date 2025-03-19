/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** print char per char
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


void my_dputchar(char c, int fd)
{
    write(fd, &c, 1);
}
