/*
** EPITECH PROJECT, 2025
** hashtable.c
** File description:
** hashtable
*/

#include "../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t) * (len + 1));

    if (len <= 0)
        return NULL;
    if (hashtable == NULL)
        return NULL;
    for (int i = 0; i != len; i++) {
        hashtable[i].fptr = hash;
        hashtable[i].end = 0;
        hashtable[i].elem = NULL;
    }
    hashtable[len].end = 1;
    return hashtable;
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL || ht->end == -1)
        return;
    ht->end = -1;
    ht = NULL;
    free(ht);
    return;
}
