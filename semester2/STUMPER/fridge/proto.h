/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** proto
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct fridge_s {
    int tomato;
    int dough;
    int onion;
    int pasta;
    int olive;
    int pepper;
    int ham;
    int cheese;
} fridge_t;

#ifndef PROTO_H
    #define PROTO_H
int fridge(void);
void disp_fridge(fridge_t *fridge);
void add_to_fridge(char **cmd, fridge_t *fridge);
void make_command(fridge_t *f, char *ig);
int enough_pizza(fridge_t *f);
int enough_pasta(fridge_t *f);
void save_file(fridge_t *fridge);
#endif // PROTO_H //
