/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_loader
*/

#include "globbing.h"
#include <stdio.h>

/**
** @brief Use to fill a array base on a globbing
** @param globbing The given globbing
** @param array_ptr A Pointer to a string array that will have every possible
**   input based on the globbing
** @return True the globbing match to anything
**/
bool globbing_load(char *globbing, char ***array_ptr)
{
    return globbing_dir_load(".", globbing, array_ptr);
}
