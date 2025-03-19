/*
** EPITECH PROJECT, 2024
** proto.h
** File description:
** proto.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include <dirent.h>
#include <ctype.h>
#include <getopt.h>

#ifndef PROTO_H
     #define PROTO_H
int my_getloadavg(void);
int my_top(int clock, int counter);
int my_getnbr(char const *str);
int task(void);
double *cpu_usage(double *user);
int mem_handler(void);
int task_manager(void);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
#endif /*PROTO_H*/
