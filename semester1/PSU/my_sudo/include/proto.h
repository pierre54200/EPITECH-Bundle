/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** prototy
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>

#ifndef PROTO_H
    #define PROTO_H
    #define _GNU_SOURCE
    #define __XOPEN_SOURCE
typedef struct pswdhash_s {
    char *sai;
    char *prefix;
    char *salt;
    char *hash;
    char *fullpw;
} pswdhash_t;

int execute(char **argv);
int check_password(char *input, char *user);
int check_command(char **argv);
int find_in_string(char *src, char *str);
int check_grp(char *username);
char *useri(int uid);
char *find_in_file(char *path, char *str);
char *bmalloc(int size);
#endif /* PROTO_H */
