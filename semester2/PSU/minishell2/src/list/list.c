/*
** EPITECH PROJECT, 2025
** list.c
** File description:
** list
*/

#include "proto.h"

list_t *pop_back_list(list_t *list)
{
    list_node_t *temp;

    if (list == NULL)
        return NULL;
    if (list->first == list->last) {
        free(list);
        return NULL;
    }
    temp = list->last;
    list->last = list->last->previous;
    list->last->next = NULL;
    temp->next = NULL;
    temp->previous = NULL;
    free_array(temp->cmd->command);
    free(temp->cmd);
    free(temp);
    list->size -= 1;
    return list;
}

void clear_list(list_t *list)
{
    while (list != NULL)
        pop_back_list(list);
}

list_t *push_back(list_t *list, cmd_t *cmd)
{
    list_node_t *node = malloc(sizeof(list_node_t));

    node->cmd = cmd;
    node->next = NULL;
    node->previous = NULL;
    if (list == NULL) {
        list = malloc(sizeof(list_t));
        list->size = 1;
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->previous = list->last;
        list->last = node;
        list->size++;
    }
    return list;
}

list_t *push_front(list_t *list, cmd_t *cmd)
{
    list_node_t *node = malloc(sizeof(list_node_t));

    node->cmd = cmd;
    node->next = NULL;
    node->previous = NULL;
    if (list == NULL) {
        list = malloc(sizeof(list_t));
        list->size = 1;
        list->first = node;
        list->last = node;
    } else {
        list->first->previous = node;
        node->next = list->first;
        list->first = node;
        list->size++;
    }
    return list;
}
