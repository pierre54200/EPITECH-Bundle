/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_is_valid_char
*/

#include "alias.h"

/**
** @brief Use to know if a char is a valid char
** @param c The char
** @return True if the char is a valid alias char
**/
bool alias_is_valid_char(char c)
{
    return c == '\0' || c == ' ' || c == '\t' ||
        c == '&' || c == '|' ||
        c == '>' || c == '<' || c == ';';
}
