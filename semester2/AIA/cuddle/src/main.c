/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** main
*/

#include "../include/dataframe.h"

static int dump_row(dataframe_row_t *row)
{
    printf("Next: %p\n", row->next);
    printf("Prev: %p\n", row->previous);
    printf("Entry Count: %u\n", row->entry_count);
    printf("Entries: %p\n", row->entries);
    for (uint32_t i = 0; i < row->entry_count; i++) {
        printf("Entry[%u] %p[%s]\n", i, row->entries[i].string_value,
            row->entries[i].string_value);
    }
    return 0;
}

static void df_dump_test(dataframe_t *frame)
{
    printf("===============\n");
    df_dump(frame);
    printf("=====\n");
    pop_row(frame, frame->first_row);
    df_dump(frame);
    printf("=====\n");
    pop_row(frame, frame->last_row);
    df_dump(frame);
    printf("=====\n");
    pop_row(frame, frame->first_row->next);
    df_dump(frame);
    printf("===============\n");
}

static void *update_age(void *value)
{
    int *new = malloc(sizeof(uint32_t));

    *new = (*(uint32_t *)value) * 2;
    return new;
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

void *agg_func(void **values, int nb_values)
{
    int *sum = malloc(sizeof(int));

    *sum = 0;
    for (int i = 0; i < nb_values; i++) {
        *sum += *(int *) values[i];
    }
    return sum;
}

static void test_bis(void)
{
    dataframe_t *basic = df_read_csv("tests/csv_files/data.csv", ",");

    df_dump(basic);
    printf("\n");
    df_describe(basic);
    df_free(basic);
}

int main(int argc, char **argv)
{
    printf("%lu\n", strlen("Léo"));
    test_bis();
    return 0;
}
