/*
** EPITECH PROJECT, 2025
** dump.c
** File description:
** dump
*/

#include "../include/hashtable.h"

void ht_print(hashtable_t ht)
{
    while (ht.elem != NULL) {
        if (ht.elem->key != NULL) {
            my_putstr("> ");
            my_put_nbr(ht.elem->nb);
            my_putstr(" - ");
            my_putstr(ht.elem->key);
            my_putstr("\n");
        }
        ht.elem = ht.elem->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL || ht->end == -1)
        return;
    for (int i = 0; ht[i].end != 1; i++) {
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        if (ht[i].key != NULL)
            ht_print(ht[i]);
    }
    return;
}
