/*
** EPITECH PROJECT, 2024
** mylist.h
** File description:
** //
*/

#ifndef MYLIST_H
     #define MYLIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(int ac, char *const *av);
int my_list_size(linked_list_t const *begin);
void my_rev_list(linked_list_t **begin);
#endif /*MYLIST_H*/
