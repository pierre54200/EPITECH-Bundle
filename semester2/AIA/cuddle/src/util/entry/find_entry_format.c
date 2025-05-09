/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** find_entry_format
*/

#include "dataframe.h"

char *find_entry_format(dataframe_entry_t *entry)
{
    switch (entry->type) {
    case STRING:
        return "%s";
    case UINT:
        return "%u";
    case INT:
        return "%i";
    case FLOAT:
        return "%.2f";
    case BOOL:
        return "%i";
    default:
        return NULL;
    }
}
