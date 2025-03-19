/*
** EPITECH PROJECT, 2025
** insert.c
** File description:
** insert
*/

#include <criterion/criterion.h>
#include "../include/hashtable.h"

Test(hash, hash_size_4)
{
    char str[] = "Hello";
    int hashed = hash(str, 4);

    cr_assert_(hashed == 458166892);
}

Test(hash, hash2)
{
    char str[] = "Hello";
    int hashed = hash(str, 4);
    int hashed2 = hash(str, 5);

    cr_assert_(hashed != hashed2);
}

Test(hash, hash_same)
{
    char str[] = "Hello";
    int hashed = hash(str, 4);
    int hashed2 = hash(str, 4);

    cr_assert_(hashed == hashed2);
}

Test(hash, hash1)
{
    char str[] = "Hello";
    char str2[] = "salutmonpote";
    int hashed = hash(str, 10);
    int hashed2 = hash(str2, 10);

    cr_assert_(hashed != hashed2);
}

Test(hash, hash_almost_same)
{
    char str[] = "H";
    char str2[] = "I";
    int hashed = hash(str, 10);
    int hashed2 = hash(str2, 10);

    cr_assert_(hashed != hashed2);
}

Test(hash, hash_2time)
{
    char str[] = "H";
    char str2[] = "HH";
    int hashed = hash(str, 10);
    int hashed2 = hash(str2, 10);

    cr_assert_(hashed != hashed2);
}

Test(hash, hash_strvoid)
{
    char *str = NULL;
    int hashed = hash(str, 10);

    cr_assert_(hashed == 84);
}

Test(hash, hash_len_zero)
{
    char str[] = "caca";
    int hashed = hash(str, 0);

    cr_assert_(hashed == 84);
}

Test(hash, hash_len_neg)
{
    char str[] = "caca";
    int hashed = hash(str, -1);

    cr_assert_(hashed == 84);
}

Test(hash, hash_lonzero)
{
    char str[] = "";
    int hashed = hash(str, 10);

    cr_assert_(hashed == 84);
}

Test(new_hashtable, new_hashtable_neg)
{
    cr_assert_(new_hashtable(&hash, -1) == NULL);
}

Test(new_hashtable, new_hashtable_classic)
{
    cr_assert_(new_hashtable(&hash, 10) != NULL);
}

Test(ht_search, searchNULL)
{
    cr_assert_(ht_search(NULL, "salut") == NULL);
}

Test(ht_search, search_empty)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    cr_assert_(ht_search(ht, "salut") == NULL);
}

Test(ht_search, search_classic)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "salut", "salut");
    ht_insert(ht, "cc", "salut");
    cr_assert_(ht_search(ht, "salut") != NULL);
}

Test(ht_search, search_null)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    cr_assert_(ht_search(ht, NULL) == NULL);
}

Test(ht_insert, insert_normal)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    cr_assert_(ht_insert(ht, "salut", "cc") == 0);
}

Test(ht_insert, insert_key_null)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    cr_assert_(ht_insert(ht, NULL, "cc") == 84);
}

Test(ht_insert, insert_value_null)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    cr_assert_(ht_insert(ht, "cc", NULL) == 84);
}

Test(ht_insert, insert_null)
{
    hashtable_t *ht = NULL;

    cr_assert_(ht_insert(ht, NULL, "cc") == 84);
}

Test(delete_hashtable, insert_key_null)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    delete_hashtable(ht);
    cr_assert_(ht->key == NULL);
}

Test(my_strlen, strlen)
{
    cr_assert_(my_strlen("salut") == 5);
}
