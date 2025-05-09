/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_entries_numerical_value
*/

#include "dataframe.h"

float fget_entries_numerical_value(dataframe_entry_t *entries)
{
    switch (entries->type) {
    case FLOAT:
        return entries->float_value;
    case INT:
        return (float) entries->int_value;
    case UINT:
        return (float) entries->uint_value;
    default:
        return 0;
    }
}

int32_t iget_entries_numerical_value(dataframe_entry_t *entries)
{
    switch (entries->type) {
    case FLOAT:
        return (int32_t) entries->float_value;
    case INT:
        return entries->int_value;
    case UINT:
        return (int32_t) entries->uint_value;
    default:
        return 0;
    }
}

uint32_t uget_entries_numerical_value(dataframe_entry_t *entries)
{
    switch (entries->type) {
    case FLOAT:
        return (uint32_t) entries->float_value;
    case INT:
        return (uint32_t) entries->int_value;
    case UINT:
        return entries->uint_value;
    default:
        return 0;
    }
}
