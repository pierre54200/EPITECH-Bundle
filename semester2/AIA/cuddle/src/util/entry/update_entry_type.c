/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** update_entry_type
*/

#include "dataframe.h"

void update_entry_type(dataframe_entry_t *entry, column_type_t type)
{
    char *string = entry->string_value;

    entry->type = type;
    if (type == STRING)
        return;
    if (type == UINT)
        entry->uint_value = get_unsigned_int(string);
    if (type == INT)
        entry->int_value = get_signed_int(string);
    if (type == FLOAT)
        entry->float_value = get_float(string);
    if (type == BOOL)
        entry->bool_value = get_boolean(string);
}
