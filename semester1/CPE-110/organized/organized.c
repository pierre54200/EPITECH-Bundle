/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** orga
*/
#include "include/proto.h"
#include "include/shell.h"

int is_a_sort(char *str)
{
    if (my_strcmp(str, "ID") == 0)
        return 0;
    if (my_strcmp(str, "NAME") == 0)
        return 1;
    if (my_strcmp(str, "TYPE") == 0)
        return 2;
    return -1;
}

static int is_a_nbr(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

static int is_a_type(char *arg)
{
    if (my_strcmp(arg, "WIRE") == 0)
        return WIRE;
    if (my_strcmp(arg, "ACTUATOR") == 0)
        return ACTUATOR;
    if (my_strcmp(arg, "DEVICE") == 0)
        return DEVICE;
    if (my_strcmp(arg, "PROCESSOR") == 0)
        return PROCESSOR;
    if (my_strcmp(arg, "SENSOR") == 0)
        return SENSOR;
    return -1;
}

data_t *new_node(int value, char *type, char *name)
{
    data_t *new_node = malloc(sizeof(data_t));

    if (new_node == NULL)
        return NULL;
    new_node->value = value;
    new_node->type = my_strdup(type);
    new_node->name = my_strdup(name);
    new_node->prec = NULL;
    return new_node;
}

static void put_value(int nb)
{
    my_put_nbr(nb);
    my_putstr(" - \"");
    return;
}

int add(void *data, char **args)
{
    data_t **current = data;
    data_t *new;
    static int value = 0;

    if (my_tablen(args) % 2 == 1)
        return 84;
    for (int i = 0; args[i] != 0; i = i + 2) {
        if (is_a_type(args[i]) == -1)
            return 84;
        new = new_node(value, args[i], args[i + 1]);
        my_putstr(args[i]);
        my_putstr(" n°");
        put_value(value);
        value++;
        my_putstr(args[i + 1]);
        my_putstr("\" added.\n");
        new->prec = *current;
        *current = new;
    }
    return 0;
}

static void message_del(data_t *current)
{
    my_putstr(current->type);
    my_putstr(" n°");
    my_put_nbr(current->value);
    my_putstr(" - \"");
    my_putstr(current->name);
    my_putstr("\" deleted");
    my_putstr(".\n");
    return;
}

static void remove_l(data_t **data, int value)
{
    data_t *current = *data;

    if (value < 0 || *data == NULL)
        return;
    if (current->value == value) {
        message_del(current);
        *data = current->prec;
        return;
    }
    while (current->prec != NULL) {
        if (current->prec->value == value) {
            message_del(current->prec);
            current->prec = current->prec->prec;
            return;
        }
        current = current->prec;
    }
    if (current == NULL)
        return;
    return;
}

int del(void *data, char **args)
{
    data_t **current = data;

    for (int i = 0; args[i] != 0; i++) {
        if (is_a_nbr(args[i]) == 1)
            return 84;
    }
    for (int i = 0; args[i] != 0; i++) {
        remove_l(current, my_getnbr(args[i]));
    }
    return 0;
}

int disp(void *data, char **args)
{
    data_t *current = *((data_t **)data);

    if (args[0] != NULL)
        return 84;
    while (current != NULL) {
        my_putstr(current->type);
        my_putstr(" n°");
        my_put_nbr(current->value);
        my_putstr(" - \"");
        my_putstr(current->name);
        my_putstr("\"\n");
        current = current->prec;
    }
    return 0;
}
