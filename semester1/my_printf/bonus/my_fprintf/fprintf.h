/*
** EPITECH PROJECT, 2024
** my_miniprintf.h
** File description:
** header
*/
#include "fproto.h"
#ifndef PRINT
  #define PRINT
typedef struct s_structure {
    char *flag;
    int (*fptr)(int, char *, int);
} s_structure_t;
typedef struct s_structure2 {
    char *flag;
    int (*fptr)(double, int, char *, int);
} s_structure2_t;
  /* data */

#endif /* PRINT */

#ifndef PRINTF2
  #define PRINTF2
const struct s_structure FLAGS[] = {
    {"d", &my_fput_nbr2},
    {"i", &my_fput_nbr2},
    {"o", &my_foctal},
    {"u", &my_funsigned_decimal},
    {"X", &my_fhexamaj},
    {"x", &my_fhexamin}
};
const struct s_structure2 FLAGS2[] = {
    {"f", &my_fput_double_f},
    {"F", &my_fput_double_f},
    {"e", &my_fput_double_e},
    {"E", &my_fput_double_e_maj}
};
#endif /* PRINTF2 */
