/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** type_as_string
*/

#include "dataframe.h"

char *type_as_string(column_type_t type)
{
    switch (type) {
    case STRING:
        return "string";
    case UINT:
        return "unsigned int";
    case INT:
        return "int";
    case FLOAT:
        return "float";
    case BOOL:
        return "bool";
    default:
        return NULL;
    }
}
