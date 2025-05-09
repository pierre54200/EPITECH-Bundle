/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_entry_equals
*/

#include "dataframe.h"

bool is_entry_equals(void *value, dataframe_entry_t *entry)
{
    void *entry_value = NULL;

    if (value == NULL || entry == NULL) {
        return false;
    }
    entry_value = get_entry_value(entry);
    switch (entry->type) {
    case STRING:
        return strcmp((char *)value, (char *)entry->string_value) == 0;
    case UINT:
        return (*(uint32_t *)value) == (*(uint32_t *)entry->string_value);
    case INT:
        return (*(int32_t *)value) == (*(int32_t *)entry_value);
    case FLOAT:
        return (*(float *)value) == (*(float *)entry_value);
    case BOOL:
        return (*(bool *)value) == (*(bool *)entry_value);
    default:
        return false;
    }
}
