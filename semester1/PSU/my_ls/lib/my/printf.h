/*
** EPITECH PROJECT, 2024
** my_miniprintf.h
** File description:
** header
*/
#include "proto.h"
#include <stdarg.h>
#ifndef PRINT
  #define PRINT
typedef struct s_structure {
    char *flag;
    int (*fptr)(va_list, int, char *);
} s_structure_t;
  /* data */

#endif /* PRINT */

#ifndef PRINTF2
  #define PRINTF2
const struct s_structure FLAGS[] = {
    {"d", &my_put_nbr2},
    {"i", &my_put_nbr2},
    {"o", &my_octal},
    {"u", &my_unsigned_decimal},
    {"X", &my_hexamaj},
    {"x", &my_hexamin},
    {"f", &my_put_double_f},
    {"F", &my_put_double_f},
    {"e", &my_put_double_e},
    {"E", &my_put_double_e_maj},
    {"s", &my_putstr2},
    {"c", &my_putchar2},
    {"p", &my_adress},
    {"b", &my_binary},
    {"B", &my_binary_maj}
};
#endif /* PRINTF2 */
