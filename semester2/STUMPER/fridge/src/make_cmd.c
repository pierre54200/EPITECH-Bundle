/*
** EPITECH PROJECT, 2025
** fridge
** File description:
** make command
*/

#include "../proto.h"

void make_command(fridge_t *f, char *ig)
{
    if (strcmp(ig, "pizza") == 0 && enough_pizza(f) == 0) {
        f->tomato -= 5;
        f->dough -= 1;
        f->onion -= 3;
        f->olive -= 8;
        f->pepper -= 8;
        f->ham -= 4;
        f->cheese -= 3;
        return;
    }
    if (strcmp(ig, "pasta") == 0 && enough_pasta(f) == 0) {
        f->tomato -= 5;
        f->pasta -= 2;
        f->olive -= 6;
        f->ham -= 4;
        f->cheese -= 3;
        return;
    }
    printf("\'%s\': meal unknown\n", ig);
}
