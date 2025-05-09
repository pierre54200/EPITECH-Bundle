/*
** EPITECH PROJECT, 2025
** fridge.c
** File description:
** fridge.c
*/

#include "../proto.h"
#include <string.h>

static int nbofspace(const char *buffer)
{
    int nb = 1;

    for (int i = 0; buffer[i] != 0; i++) {
        if (buffer[i] == ' ')
            nb++;
    }
    return nb;
}

static fridge_t init_fridge(void)
{
    fridge_t fridge;

    fridge.tomato = 50;
    fridge.dough = 50;
    fridge.onion = 50;
    fridge.pasta = 50;
    fridge.olive = 50;
    fridge.pepper = 50;
    fridge.ham = 50;
    fridge.cheese = 50;
    return fridge;
}

static int tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i;
}

static void treat_command(char **cmd, fridge_t *fridge)
{
    if (tablen(cmd) == 2 && strcmp("disp", cmd[0]) == 0
        && strcmp("fridge", cmd[1]) == 0) {
        disp_fridge(fridge);
        return;
    }
    if (tablen(cmd) == 3 && strcmp("addToFridge", cmd[0]) == 0) {
        add_to_fridge(cmd, fridge);
        return;
    }
    if (tablen(cmd) == 2 && strcmp("make", cmd[0]) == 0) {
        make_command(fridge, cmd[1]);
        return;
    }
    printf("\'");
    for (int i = 0; cmd[i + 1] != 0; i++)
        printf("%s ", cmd[i]);
    printf("%s", cmd[tablen(cmd) - 1]);
    printf("\': Invalid operation\n");
}

static char **split_cmd(char *str)
{
    char **stock = malloc((nbofspace(str) + 1) * sizeof(char *));
    char *token = NULL;
    int i = 0;

    if (stock == NULL)
        return NULL;
    for (int j = 0; j != nbofspace(str) + 1; j++)
        stock[j] = 0;
    for (; str != NULL; i++) {
        token = strsep(&str, " ");
        stock[i] = strdup(token);
    }
    return stock;
}

static int getcmd(fridge_t *fridge)
{
    char *buffer = NULL;
    size_t size = 2;
    ssize_t nread = 0;
    char **cmd = NULL;

    while (1) {
        nread = getline(&buffer, &size, stdin);
        if (nread < 0)
            break;
        buffer[strlen(buffer) - 1] = 0;
        if (strcmp("exit", buffer) == 0)
            break;
        cmd = split_cmd(buffer);
        treat_command(cmd, fridge);
        for (int i = 0; cmd[i] != NULL; i++)
            free(cmd[i]);
        free(cmd);
    }
    free(buffer);
    return 0;
}

int fridge(void)
{
    fridge_t fridge = init_fridge();

    getcmd(&fridge);
    save_file(&fridge);
    return 0;
}
