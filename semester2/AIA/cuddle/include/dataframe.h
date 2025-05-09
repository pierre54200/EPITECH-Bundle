/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <alloca.h>
    #include <stdint.h>
    #include <errno.h>
    #include <math.h>
    #include <ctype.h>

    #define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct dataframe_shape_s {
    uint32_t nb_rows;
    uint32_t nb_columns;
} dataframe_shape_t;

typedef struct {
    char *column_name;
    uint32_t row_count;
    float minimal;
    float maximum;
    double standard_deviation;
    double mean;
} dataframe_describe_t;

typedef enum {
    STRING = 1 << 0,
    BOOL = 1 << 1,
    INT = 1 << 2,
    UINT = 1 << 3,
    FLOAT = 1 << 4,
    NUMERICAL = INT | UINT | FLOAT,
    ALL_TYPE = STRING | BOOL | INT | UINT | FLOAT
} column_type_t;

typedef struct column_header {
    column_type_t type;
    char *name;
} column_header_t;

typedef struct dataframe_entry {
    column_type_t type;
    union {
        bool bool_value;
        int32_t int_value;
        uint32_t uint_value;
        float float_value;
    };
    char *string_value;
} dataframe_entry_t;

typedef struct dataframe_row {
    uint32_t entry_count;
    dataframe_entry_t *entries;
    struct dataframe_row *next;
    struct dataframe_row *previous;
} dataframe_row_t;

typedef struct dataframe_s {
    uint32_t nb_rows;
    uint32_t nb_columns;
    char *separator;
    column_header_t *column_header;
    dataframe_row_t *first_row;
    dataframe_row_t *last_row;
} dataframe_t;


int load_frame_header(dataframe_t *frame, FILE *file);
int load_frame_body(dataframe_t *frame, FILE *file);
void load_column_type(dataframe_t *dataframe);

int push_row(dataframe_t *frame, dataframe_row_t *new_row);
int pushback_row(dataframe_t *frame, dataframe_row_t *new_row);
int pop_row(dataframe_t *frame, dataframe_row_t *row);

void df_free(dataframe_t *frame);
void destroy_rows(dataframe_t *frame);
void destroy_entries(dataframe_entry_t *entries, uint32_t entry_count);

dataframe_row_t *dupe_row(dataframe_row_t *row);
dataframe_row_t *create_row(dataframe_t *frame, char *line);
dataframe_t *dupe_header(dataframe_t *src);
dataframe_t *dupe_frame(dataframe_t *src);

// Core Functions //
dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);

// Basic Functions //
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_real_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_real_tail(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_reverse(dataframe_t *dataframe);

/**************
** This function is used to dump the content of a dataframe.
** @param dataframe The frame to dump.
**************/
void df_dump(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);
dataframe_shape_t df_shape(dataframe_t *dataframe);

// Filtering //
dataframe_t *df_filter(dataframe_t *dataframe,
    const char *column, bool (*filter_func)(void *value));

// Sorting //
dataframe_t *df_sort(dataframe_t *dataframe,
    const char *column, bool (*sort_func)(void *value1, void *value2));

// Aggregation //
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values));

// Transformation //
dataframe_t *df_apply(dataframe_t *dataframe,
    const char *column, void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe,
    const char *column, column_type_t downcast);

// Utilities //
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void **df_get_common_values(dataframe_t *dataframe,
    const char *column, const char *target_column_name,
    void *target_column_value);
void df_free(dataframe_t *dataframe);

int update_all_row(dataframe_t *frame,
    uint32_t column_index, column_type_t downcast);

// Bonus //
    #define MY_STRDUPA(s) (strcpy(alloca(strlen(s)), s))

void remove_trailing_char(char *str, char c);
bool is_valid_column_name(char *name);
uint32_t count_column(char *header_line, const char *separator);
bool find_column_index(
    dataframe_t *frame, uint32_t *column_index,
    const char *column_name);
char *file_next_line(bool skip_empty_line, char *comment_prefix, FILE *file);
void update_entry_type(dataframe_entry_t *entry, column_type_t type);
uint32_t count_numerical_column(const dataframe_t *frame);
int change_entry_type(dataframe_entry_t *entry, column_type_t type);

bool is_entry_equals(void *value, dataframe_entry_t *entry);
bool is_value_unique(void **values, dataframe_entry_t *entry);

char *str_to_lower(char *str);
char *type_as_string(column_type_t type);

bool is_signed_int(char *string);
bool is_unsigned_int(char *string);
bool is_float(char *string);
bool is_boolean(char *string);
bool is_numerical(char *string);

int get_signed_int(char *string);
uint32_t get_unsigned_int(char *string);
float get_float(char *string);
bool get_boolean(char *string);

bool to_boolean(dataframe_entry_t *entry);
bool to_float(dataframe_entry_t *entry);
bool to_signed_int(dataframe_entry_t *entry);
bool to_unsigned_int(dataframe_entry_t *entry);

float fget_entries_numerical_value(dataframe_entry_t *entries);
int32_t iget_entries_numerical_value(dataframe_entry_t *entries);
uint32_t uget_entries_numerical_value(dataframe_entry_t *entries);

void *get_entry_value(dataframe_entry_t *entries);
char *find_entry_format(dataframe_entry_t *entry);
int update_entry(dataframe_entry_t *entry, void *new_value);

int voidtablen(void **tab);
int tablen(const char **tab);

#endif
