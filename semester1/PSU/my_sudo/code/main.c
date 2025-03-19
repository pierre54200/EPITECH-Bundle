/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "../include/proto.h"

static int h_func(void)
{
    printf("usage: ./my_sudo -h\n");
    printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    return 0;
}

int check_exe(char **argv)
{
    char *file = malloc(8 + strlen(argv[1]));
    FILE *f;

    if (argv[1][0] == '/') {
        f = fopen(argv[1], "r");
        if (f == NULL)
            return 84;
        return 0;
    }
    sprintf(file, "/bin/%s", argv[1]);
    if (file == NULL)
        return 84;
    f = fopen(file, "r");
    if (f == NULL)
        return 84;
    fclose(f);
    free(file);
    return 0;
}

static int check_eve(int ac, char **av)
{
    if (ac == 1)
        return h_func() + 85;
    if (strcmp(av[1], "-h") == 0)
        return h_func() + 1;
    if (check_exe(av) == 84 || check_command(av) == 0)
        return 85;
    if (av[1][0] == '-')
        return 85;
    return 0;
}

static char *getpasswd(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    line[strlen(line) - 1] = 0;
    return line;
}

int main(int ac, char **av)
{
    char *input;
    char *username;
    int check = check_eve(ac, av);

    if (check != 0)
        return check - 1;
    if (getuid() == 0)
        return execute(av);
    username = useri(getuid());
    for (int i = 0; i != 3; i++) {
        printf("[my_sudo] password for %s: ", username);
        input = getpasswd();
        if (check_grp(username) == 1)
            return 84;
        if (check_password(input, username) == 1)
            return execute(av);
        if (i != 2)
            printf("Sorry, try again.\n");
    }
    return printf("my_sudo: 3 incorrect password attempts.\n") + 45;
}
