/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct hashtable_s {
    int nb;
    int (*fptr)(char *, int);
    char *key;
    int end;
    struct element_s *elem;
} hashtable_t;

typedef struct element_s {
    int nb;
    char *key;
    struct element_s *next;
} element_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
#endif /* HASHTABLE_H */
