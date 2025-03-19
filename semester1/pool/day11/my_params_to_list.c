/*
** EPITECH PROJECT, 2024
** my_params_to_list
** File description:
** //
*/
#include "include/my.h"
#include "include/mylist.h"
#include <stddef.h>
#include <stdlib.h>

static int my_put_in_list(linked_list_t **list, char *av)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = av;
    element->next = *list;
    *list = element;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list;

    list = 0;
    for (int i = 0; av[i] != 0; i++)
        my_put_in_list(&list, av[i]);
    return list;
}
