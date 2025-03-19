/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** struct for printf
*/
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#ifndef PROTO_H
    #define PROTO_H
int my_dputstr2(char const *str, char *flag, int fd);
int my_dputstr(char const *str, int fd);
int my_dput_nbr(int nb, int fd);
int my_dput_nbr2(int nb, char *flag, int fd);
int my_dprintf(int fd, const char *format, ...);
void my_dputchar(char c, int fd);
int my_doctal(int nb, char *flag, int fd);
int my_dunsigned_decimal(int nb, char *flag, int fd);
int my_dhexamaj(int nb, char *flag, int fd);
int my_dhexamin(int nb, char *flag, int fd);
char *my_drevstr(char *str, int fd);
int dpuissance_10(int i);
int dcounter(int counter);
double dpuissancedouble_10(int i);
int my_dput_double_f(double nb, int nbvir, char *flag, int fd);
int my_dput_double(double nb, int counter, int fd);
double my_drecup_decimal(double nb, int counter, int fd);
int my_dput_double_e(double nb, int nbvir, char *flag, int fd);
int my_dput_double_e_maj(double nb, int nbvir, char *flag, int fd);
int dflag_handler_double(char *flag, double nb, int test, int fd);
int dflag_handler_int(char *flag, int nb, int test, int fd);
#endif /* PROTO_H */
