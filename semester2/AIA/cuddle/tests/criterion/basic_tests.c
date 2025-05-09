/*
** EPITECH PROJECT, 2025
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"

static char *file[4] = {
    "./tests/criterion/files/basic.csv",
    "./tests/criterion/files/basic2.csv",
    "./tests/criterion/files/random.csv",
    "./tests/criterion/files/empty.csv"
};

static char *file_test[3] = {
    "./tests/criterion/files/test1.csv",
    "./tests/criterion/files/test2.csv",
    "./tests/criterion/files/test3.csv"
};

Test(write, basic_write)
{
    FILE *file1 = fopen(file[0], "r");
    FILE *file2 = fopen(file_test[0], "r");
    dataframe_t *frame = df_read_csv(file[0], ",");

    df_write_csv(frame, file_test[0]);
    cr_assert_file_contents_eq(file1, file2);
    df_free(frame);
}

Test(write, write_nowhere)
{
    dataframe_t *frame = df_read_csv(file[0], ",");

    cr_assert_(df_write_csv(frame, "build") == 84);
    df_free(frame);
}

Test(write, null_sep)
{
    FILE *file1 = fopen(file[0], "r");
    FILE *file2 = fopen(file_test[0], "r");
    dataframe_t *frame = df_read_csv(file[0], NULL);

    df_write_csv(frame, file_test[0]);
    cr_assert_file_contents_eq(file1, file2);
    df_free(frame);
}

Test(write, wrong_file)
{
    dataframe_t *frame = df_read_csv(file[2], NULL);

    cr_assert_(frame == NULL);
}

Test(write, other_sep)
{
    FILE *file1 = fopen(file[1], "r");
    FILE *file2 = fopen(file_test[1], "r");
    dataframe_t *frame = df_read_csv(file[1], ";");

    df_write_csv(frame, file_test[1]);
    cr_assert_file_contents_eq(file1, file2);
    df_free(frame);
}

Test(write, empty)
{
    FILE *file1 = fopen(file[3], "r");
    FILE *file2 = fopen(file_test[2], "r");
    dataframe_t *frame = df_read_csv(file[3], ";");

    df_write_csv(frame, file_test[2]);
    cr_assert_file_contents_eq(file1, file2);
    df_free(frame);
}

Test(read, null_frame)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_write_csv(frame, file_test[0]) == 84);
}

Test(read, null_filepath)
{
    dataframe_t *frame = df_read_csv(file[0], ";");

    cr_assert_(df_write_csv(frame, NULL) == 84);
    df_free(frame);
}

Test(free, null)
{
    dataframe_t *frame = NULL;

    df_free(frame);
}

Test(free, sep_null)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    df_free(frame);
}

Test(free, file_empty)
{
    dataframe_t *frame = df_read_csv(file_test[2], NULL);

    df_free(frame);
}

Test(free, destroy_entries)
{
    destroy_entries(NULL, 0);
}

static bool filter_func(void *value)
{
    return *(int *)value > 30;
}

static bool sort_func(void *value1, void *value2)
{
    return *(int *)value1 > *(int *)value2;
}

static void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));

    *new_value = *(int *)value * 2;
    return new_value;
}

static void *apply_func_bis(void *value)
{
    char *str = (char *)value;

    if (str[strlen(str) - 1] == 'e')
        str[strlen(str) - 1] = '\0';
    return str;
}

Test(filter, null_db)
{
    cr_assert_(df_filter(NULL, "test", filter_func) == NULL);
}

Test(filter, null_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_filter(frame, NULL, filter_func) == NULL);
    df_free(frame);
}

Test(filter, wrong_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_filter(frame, "caca", filter_func) == NULL);
    df_free(frame);
}

Test(filter, null_fun)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_filter(frame, "name", NULL) == NULL);
    df_free(frame);
}

Test(filter, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);
    dataframe_t *filter = df_filter(frame, "name", filter_func);

    cr_assert_(filter != NULL);
    df_free(frame);
    df_free(filter);
}

Test(sorting, null_db)
{
    cr_assert_(df_sort(NULL, "test", sort_func) == NULL);
}

Test(sorting, null_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_sort(frame, NULL, sort_func) == NULL);
    df_free(frame);
}

Test(sorting, wrong_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_sort(frame, "caca", sort_func) == NULL);
    df_free(frame);
}

Test(sorting, null_fun)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_sort(frame, "name", NULL) == NULL);
    df_free(frame);
}

Test(sorting, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);
    dataframe_t *sort = df_sort(frame, "name", sort_func);

    cr_assert_(sort != NULL);
    df_free(frame);
    df_free(sort);
}

Test(aggregation, null_db)
{
    const char **test = {NULL};
    cr_assert_(df_groupby(NULL, "test", test, NULL) == NULL);
}

Test(aggregation, v1)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);
    const char **test = {NULL};

    cr_assert_(df_groupby(frame, NULL, test, NULL) == NULL);
    df_free(frame);
}

Test(aggregation, v2)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_groupby(frame, "test", NULL, NULL) == NULL);
    df_free(frame);
}

Test(aggregation, fun_null)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);
    const char **test = {NULL};

    cr_assert_(df_groupby(frame, "test", test, NULL) == NULL);
    df_free(frame);
}

Test(apply, db_null)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_apply(frame, "name", apply_func) == NULL);
    df_free(frame);
}

Test(apply, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_apply(frame, "name", apply_func) != NULL);
    df_free(frame);
}

Test(apply, wrong_clm)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_apply(frame, "test", apply_func) == NULL);
    df_free(frame);
}

Test(apply, fun_null)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_apply(frame, "name", NULL) == NULL);
    df_free(frame);
}

Test(unique_value, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_unique_values(frame, "name") != NULL);
    df_free(frame);
}

Test(unique_value, null_frame)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_get_unique_values(frame, "name") == NULL);
}

Test(unique_value, wrong_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_unique_values(frame, "caca") == NULL);
    df_free(frame);
}

Test(unique_value, null_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_unique_values(frame, NULL) == NULL);
    df_free(frame);
}

Test(value, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_values(frame, "name") != NULL);
    df_free(frame);
}

Test(value, null_frame)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_get_values(frame, "name") == NULL);
}

Test(value, wrong_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_values(frame, "caca") == NULL);
    df_free(frame);
}

Test(value, null_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_values(frame, NULL) == NULL);
    df_free(frame);
}

Test(values, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_value(frame, 1, "name") != NULL);
    df_free(frame);
}

Test(values, null_frame)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_get_value(frame, 1, "name") == NULL);
}

Test(values, wrong_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_value(frame, 1, "caca") == NULL);
    df_free(frame);
}

Test(values, null_column)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_value(frame, 1, NULL) == NULL);
    df_free(frame);
}

Test(values, val_neg)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_get_value(frame, -1, "name") == NULL);
    df_free(frame);
}

Test(describe, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    df_describe(frame);
    df_free(frame);
}

Test(describe, null)
{
    dataframe_t *frame = NULL;

    df_describe(frame);
}

Test(dump, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    df_dump(frame);
    df_free(frame);
}

Test(dump, null)
{
    dataframe_t *frame = NULL;

    df_dump(frame);
}

Test(info, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    df_info(frame);
    df_free(frame);
}

Test(info, null)
{
    dataframe_t *frame = NULL;

    df_info(frame);
}

Test(shape, normal)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);

    cr_assert_(df_shape(frame).nb_columns != 0);
    cr_assert_(df_shape(frame).nb_rows != 0);
    df_free(frame);
}

Test(shape, null)
{
    dataframe_t *frame = NULL;

    cr_assert_(df_shape(frame).nb_columns == 0);
    cr_assert_(df_shape(frame).nb_rows == 0);
    df_shape(frame);
}

Test(pop_row, null_frame)
{
    dataframe_t *frame = NULL;
    dataframe_row_t *row = malloc(1);

    cr_assert_(pop_row(frame, row));
    df_shape(frame);
    free(row);
}

Test(pop_row, null_row)
{
    dataframe_t *frame = df_read_csv(file[0], NULL);
    dataframe_row_t *row = NULL;

    cr_assert_(pop_row(frame, row));
    df_shape(frame);
}
