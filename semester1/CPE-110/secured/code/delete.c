/*
** EPITECH PROJECT, 2025
** delete.c
** File description:
** delete
*/

#include "../include/hashtable.h"

element_t *delete(hashtable_t ht, int nb)
{
    while (ht.elem != NULL) {
        if (ht.elem->nb == nb)
            ht.elem->key = NULL;
        ht.elem = ht.elem->next;
    }
    return ht.elem;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int len = 0;
    int nb = 0;
    int i = 0;

    if (ht == NULL || ht->end == -1 || key == NULL)
        return 84;
    if (key[0] == 0)
        return 84;
    for (; ht[len].end != 1; len++);
    nb = ht->fptr(key, len);
    i = nb % len;
    delete(ht[i], nb);
    return 0;
}
