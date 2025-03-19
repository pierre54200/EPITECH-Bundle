/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/
#include "../include/proto.h"

static int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len = len + 1;
    }
    return (len);
}

static int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return len;
}

static int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    result = s1[i] - s2[i];
    return result;
}

static int header(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTION] path_to_script\n");
    my_putstr("\tpath_to_script\tThe path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h\t\tprint the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t'L' key\t\tenable/disable hitboxes and areas.\n");
    my_putstr("\t'S' key\t\tenable/disable sprites.\n");
    my_putstr("\t'Q' key\t\tQuit\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return header();
    return check_file_exist(av[1]);
}
