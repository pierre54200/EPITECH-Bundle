/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_const
*/

#include "globbing.h"


const globbing_matcher_t globbing_matchers[] = {
    {"*", &globbing_matcher_any_wildcard},
    {"?", &globbing_matcher_single_wildcard},
    {"{", &globbing_matcher_choices},
    {"", &globbing_matcher_char}
};

const size_t globbing_matcher_count =
sizeof(globbing_matchers) / sizeof(globbing_matcher_t);
