#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "globbing.h"
#include "string_utils.h"
#include "parser.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(globbing, globbing_any_wildcard)
{
    char **array = NULL;

    globbing_load("*", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_single_any_wildcard_at_start)
{
    char **array = NULL;

    globbing_load("?*", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_single_any_wildcard_at_end)
{
    char **array = NULL;

    globbing_load("*?", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_single_wildcard)
{
    char **array = NULL;

    globbing_load("?", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_single_wildcard_too_much)
{
    char **array = NULL;

    globbing_load("??????????????????????????????????????????", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_any_wildcard_failed)
{
    char **array = NULL;

    globbing_load("r*", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_char_and_wildcard)
{
    char **array = NULL;

    globbing_load("*f*", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_inner_folder)
{
    char **array = NULL;

    globbing_load("*/*.c", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_choices)
{
    char **array = NULL;

    globbing_load("{Make,my}*", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_incomplete_choices_1)
{
    char **array = NULL;

    globbing_load("{Make,my*", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_incomplete_choices_2)
{
    char **array = NULL;

    globbing_load("{Makemy*", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_incomplete_choices_3)
{
    char **array = NULL;

    globbing_load("{Makemy}*", &array);
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_complex)
{
    char **array = NULL;

    globbing_load("*/*/*.*", &array);
    if (array == NULL) {
        cr_assert(false, "Nothing was found using the globbing.");
    }
    free_str_array(array);
    cr_assert(1);
}

Test(globbing, globbing_depth)
{
    char **array = NULL;

    globbing_load("*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*", &array);
    if (array != NULL) {
        cr_assert(false, "Should not avoid the max depth");
    }
    cr_assert(1);
}

Test(globbing, globbing_empty)
{
    cr_assert(globbing_matcher_any_wildcard("*", ""));
}

Test(globbing, globbing_empty_failed_1)
{
    cr_assert(!globbing_matcher_any_wildcard("*e", ""));
}

Test(globbing, globbing_empty_failed_2)
{
    cr_assert(!globbing_matcher_any_wildcard("*e", "d"));
}

Test(globbing, globbing_skip_dir)
{
    char *result = globbing_skip_dir("random");

    cr_assert(result[0] == '\0');
}

Test(globbing, globbing_skip_multiple_dir)
{
    char *result = globbing_skip_dir("random//////a/b/c/e");

    cr_assert(result[0] == 'a');
}

Test(globbing, globbing_deep_search_check_1)
{
    bool result = globbing_should_deep_search("random//////a/b/c/e");

    cr_assert(result == true);
}

Test(globbing, globbing_deep_search_check_2)
{
    bool result = globbing_should_deep_search("random//////");

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_1)
{
    bool result = globbing_finder(NULL, 0);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_2)
{
    bool result = globbing_finder(NULL, 10);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_3)
{
    parser_tokens_t token = { 0 };
    bool result = globbing_finder(&token, 0);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_4)
{
    parser_tokens_t *token = parser_parse(NULL, "/*/*/*");
    bool result = globbing_finder(token, 6);

    cr_assert(result == true);
}

Test(globbing, globbing_finder_check_5)
{
    parser_tokens_t *token = parser_parse(NULL, "/\\*/*/*");
    bool result = globbing_finder(token, 6);

    cr_assert(result == true);
}

Test(globbing, globbing_finder_check_6)
{
    parser_tokens_t *token = parser_parse(NULL, "/\\*/?/*");
    bool result = globbing_finder(token, 6);

    cr_assert(result == true);
}

Test(globbing, globbing_finder_check_7)
{
    parser_tokens_t *token = parser_parse(NULL, "/\\{,}/?/*");
    bool result = globbing_finder(token, 6);

    cr_assert(result == true);
}

Test(globbing, globbing_finder_check_8)
{
    parser_tokens_t *token = parser_parse(NULL, "{,}");
    bool result = globbing_finder(token, 3);

    cr_assert(result == true);
}

Test(globbing, globbing_finder_check_9)
{
    parser_tokens_t *token = parser_parse(NULL, "{");
    bool result = globbing_finder(token, 1);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_10)
{
    parser_tokens_t *token = parser_parse(NULL, "{,");
    bool result = globbing_finder(token, 2);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_11)
{
    parser_tokens_t *token = parser_parse(NULL, ",}");
    bool result = globbing_finder(token, 2);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_12)
{
    parser_tokens_t *token = parser_parse(NULL, "{}");
    bool result = globbing_finder(token, 2);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_13)
{
    parser_tokens_t *token = parser_parse(NULL, "\\{\\,\\}");
    bool result = globbing_finder(token, 3);

    cr_assert(result == false);
}

Test(globbing, globbing_finder_check_14)
{
    parser_tokens_t *token = parser_parse(NULL, "{{,}");
    bool result = globbing_finder(token, 4);

    cr_assert(result == true);
}
