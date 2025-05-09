/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_loader
*/

#include "globbing.h"
#include "string_utils.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <alloca.h>

static char **list_file(char *dir_path, char *globbing)
{
    char **array = NULL;
    DIR *dir = opendir(dir_path);
    struct dirent *file = NULL;

    if (dir == NULL)
        return NULL;
    do {
        file = readdir(dir);
        if (file == NULL || file->d_name[0] == '.')
            continue;
        if (globbing_matcher(globbing, file->d_name))
            array = add_to_array(array, file->d_name);
    } while (file != NULL);
    closedir(dir);
    return array;
}

static bool globbing_dir_rec_load(char *dir,
    char *globbing, char ***array_ptr, size_t depth)
{
    char *current_globbing = globbing_isolate(globbing, RALLOCA(globbing));
    bool should_deep_search = globbing_should_deep_search(globbing);
    char **result = list_file(dir, current_globbing);

    if (result == NULL)
        return false;
    for (size_t i = 0; result[i] && !should_deep_search; i++) {
        (*array_ptr) = add_to_array(*array_ptr, GBUILD_PATH(dir, result[i]));
    }
    for (size_t i = 0; result[i] && should_deep_search && depth < DEPTH; i++) {
        globbing_dir_rec_load(GBUILD_PATH(dir, result[i]),
            globbing_skip_dir(globbing), array_ptr, depth + 1);
    }
    free_str_array(result);
    return array_ptr != NULL;
}

/**
** @brief Use to fill a array base on a globbing
** @param dir_from The directory where to search.
** @param globbing The given globbing
** @param array_ptr A Pointer to a string array that will have every possible
**   input based on the globbing
** @param depth The current depth
** @return True the globbing match to anything
**/
bool globbing_dir_load(char *dir, char *globbing, char ***array_ptr)
{
    return globbing_dir_rec_load(dir, globbing, array_ptr, 0);
}
