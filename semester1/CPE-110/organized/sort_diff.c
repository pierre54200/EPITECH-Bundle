/*
** EPITECH PROJECT, 2024
** sort_diff.c
** File description:
** sort_diff
*/

#include "include/proto.h"
#include "include/shell.h"

static void sort_name_rev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (my_strcmp(current->name, current->prec->name) < 0) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_name_nrev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (my_strcmp(current->name, current->prec->name) > 0) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_name(data_t **data, int reverse, int i, int j)
{
    data_t *current = *data;

    if (*data == NULL || current->prec == NULL || i == j)
        return;
    while (current->prec != NULL) {
        if (reverse != 0)
            sort_name_nrev(current);
        if (reverse == 0)
            sort_name_rev(current);
        current = current->prec;
    }
    sort_name(data, reverse, i + 1, j);
    return;
}

static void sort_id_rev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (current->value < current->prec->value) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_id_nrev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (current->value > current->prec->value) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_id(data_t **data, int reverse, int i, int j)
{
    data_t *current = *data;

    if (*data == NULL || current->prec == NULL || i == j)
        return;
    while (current->prec != NULL) {
        if (reverse != 0)
            sort_id_nrev(current);
        if (reverse == 0)
            sort_id_rev(current);
        current = current->prec;
    }
    sort_id(data, reverse, i + 1, j);
    return;
}

static void sort_type_rev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (my_strcmp(current->type, current->prec->type) < 0) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_type_nrev(data_t *current)
{
    char *name;
    char *type;
    int stock = 0;

    if (my_strcmp(current->type, current->prec->type) > 0) {
        name = my_strdup(current->name);
        free(current->name);
        current->name = current->prec->name;
        current->prec->name = name;
        type = my_strdup(current->type);
        free(current->type);
        current->type = current->prec->type;
        current->prec->type = type;
        stock = current->value;
        current->value = current->prec->value;
        current->prec->value = stock;
    }
    return;
}

static void sort_type(data_t **data, int reverse, int i, int j)
{
    data_t *current = *data;

    if (*data == NULL || current->prec == NULL || i == j)
        return;
    while (current->prec != NULL) {
        if (reverse != 0)
            sort_type_nrev(current);
        if (reverse == 0)
            sort_type_rev(current);
        current = current->prec;
    }
    sort_type(data, reverse, i + 1, j);
    return;
}

void sort_diff(data_t **sorted, int sorting, int reverse)
{
    data_t *sort = *((data_t **)sorted);
    int i = 0;

    while (sort != NULL) {
        sort = sort->prec;
        i++;
    }
    if (sorting == NAME)
        sort_name(sorted, reverse, 0, 20);
    if (sorting == ID)
        sort_id(sorted, reverse, 0, 20);
    if (sorting == TYPE)
        sort_type(sorted, reverse, 0, 20);
    return;
}
