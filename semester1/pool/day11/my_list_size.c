/*
** EPITECH PROJECT, 2024
** my_list_size
** File description:
** size of a chained list
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int nb = 0;

    for (; begin != 0; nb++)
        begin = begin->next;
    return nb;
}
