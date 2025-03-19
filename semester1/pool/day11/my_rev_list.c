/*
** EPITECH PROJECT, 2024
** my_rev_list
** File description:
** revert a list
*/
#include <stdlib.h>
#include "include/my.h"
#include "include/mylist.h"

static int my_put_in_list(linked_list_t **list, char *av)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = av;
    element->next = *list;
    *list = element;
    return 0;
}

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *copy;

    copy = 0;
    while ((*begin) != 0) {
        my_put_in_list(&copy, (*begin)->data);
        (*begin) = (*begin)->next;
    }
    *begin = copy;
}
