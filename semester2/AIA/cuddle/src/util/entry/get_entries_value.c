/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_entry_value
*/

#include "dataframe.h"

void *get_entry_value(dataframe_entry_t *entry)
{
    switch (entry->type) {
    case FLOAT:
        return &entry->float_value;
    case INT:
        return &entry->int_value;
    case UINT:
        return &entry->uint_value;
    case BOOL:
        return &entry->bool_value;
    case STRING:
        return entry->string_value;
    default:
        return NULL;
    }
}
