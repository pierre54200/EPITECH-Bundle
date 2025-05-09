/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** entry_updater
*/

#include "dataframe.h"

int update_entry_string(dataframe_entry_t *entry, void *new_value)
{
    char *format = find_entry_format(entry);

    if (format == NULL) {
        return 84;
    }
    if (entry->type == STRING)
        new_value = &new_value;
    asprintf(&entry->string_value, format, *(void **)new_value);
    if (entry->string_value == NULL)
        return 84;
    return 0;
}

int update_entry(dataframe_entry_t *entry, void *new_value)
{
    if (entry == NULL || new_value == NULL) {
        return 84;
    }
    if (entry->string_value != NULL) {
        free(entry->string_value);
        entry->string_value = NULL;
    }
    if (update_entry_string(entry, new_value)) {
        return 84;
    }
    update_entry_type(entry, entry->type);
    return 0;
}
