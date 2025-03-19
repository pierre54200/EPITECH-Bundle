/*
** EPITECH PROJECT, 2025
** search.c
** File description:
** search
*/

#include "../include/hashtable.h"

char *find_ht(hashtable_t ht, int nb)
{
    while (ht.elem != NULL) {
        if (ht.elem->nb == nb) {
            return ht.elem->key;
        }
        ht.elem = ht.elem->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int len = 0;
    int nb = 0;
    int i = 0;

    if (ht == NULL || ht->end == -1 || key == NULL)
        return NULL;
    if (key[0] == 0)
        return NULL;
    for (; ht[len].end != 1; len++);
    nb = ht->fptr(key, len);
    i = nb % len;
    return find_ht(ht[i], nb);
}
