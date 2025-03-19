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
int my_fputstr2(char const *str, char *flag, int fd);
int my_fputstr(char const *str, int fd);
int my_fput_nbr(int nb, int fd);
int my_fput_nbr2(int nb, char *flag, int fd);
int my_fprintf(FILE *ffptr, const char *format, ...);
void my_fputchar(char c, int fd);
int my_foctal(int nb, char *flag, int fd);
int my_funsigned_decimal(int nb, char *flag, int fd);
int my_fhexamaj(int nb, char *flag, int fd);
int my_fhexamin(int nb, char *flag, int fd);
char *my_frevstr(char *str, int fd);
int fpuissance_10(int i);
int fcounter(int counter);
double fpuissancedouble_10(int i);
int my_fput_double_f(double nb, int nbvir, char *flag, int fd);
int my_fput_double(double nb, int counter, int fd);
double my_frecup_decimal(double nb, int counter, int fd);
int my_fput_double_e(double nb, int nbvir, char *flag, int fd);
int my_fput_double_e_maj(double nb, int nbvir, char *flag, int fd);
int fflag_handler_double(char *flag, double nb, int test, int fd);
int fflag_handler_int(char *flag, int nb, int test, int fd);
#endif /* PROTO_H */
