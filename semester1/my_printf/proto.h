/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** struct for printf
*/
#include <stdarg.h>
#include <stddef.h>

#ifndef PROTO_H
    #define PROTO_H
int my_putstr2(va_list list, int nbvir, char *flag);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr2(va_list list, int nbvir, char *flag);
int my_printf(const char *format, ...);
void my_putchar(char c);
int my_putchar2(va_list list, int nbvir, char *flag);
int my_octal(va_list list, int nbvir, char *flag);
int my_unsigned_decimal(va_list list, int nbvir, char *flag);
int my_hexamaj(va_list list, int nbvir, char *flag);
int my_hexamin(va_list list, int nbvir, char *flag);
char *my_revstr(char *str);
int puissance_10(int i);
int counter(int counter);
double puissancedouble_10(int i);
int my_put_double_f(va_list list, int nbvir, char *flag);
int my_put_double(double nb, int counter);
double my_recup_decimal(double nb, int counter);
int my_put_double_e(va_list list, int nbvir, char *flag);
int my_put_double_e_maj(va_list list, int nbvir, char *flag);
int flag_handler_double(char *flag, double nb, int test);
int flag_handler_int(char *flag, int nb, int test, int i);
int my_adress(va_list list, int nbvir, char *flag);
int my_binary(va_list list, int nbvir, char *flag);
int my_binary_maj(va_list list, int nbvir, char *flag);
#endif /* PROTO_H */
