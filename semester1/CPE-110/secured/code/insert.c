/*
** EPITECH PROJECT, 2025
** insert.c
** File description:
** insert
*/

#include "../include/hashtable.h"

int newnode(hashtable_t *ht, char *key, char *value, int i)
{
    int len = 0;
    element_t *new_node = malloc(sizeof(element_t));

    for (; ht[len].end != 1; len++);
    new_node->key = value;
    new_node->nb = ht->fptr(key, len);
    new_node->next = ht[i].elem;
    ht[i].elem = new_node;
    return 0;
}

int check_if_ex(hashtable_t ht, int nb)
{
    while (ht.elem != NULL) {
        if (ht.elem->nb == nb) {
            return 1;
        }
        ht.elem = ht.elem->next;
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int i = 0;
    int len = 0;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    if (key[0] == 0 || ht[0].end == -1)
        return 84;
    for (; ht[len].end != 1; len++);
    i = ht->fptr(key, len) % len;
    if (check_if_ex(ht[i], ht->fptr(key, len)) == 1)
        return 0;
    ht[i].key = "test";
    newnode(ht, key, value, i);
    return 0;
}
