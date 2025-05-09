/*
** EPITECH PROJECT, 2025
** enough
** File description:
** enough
*/

#include "../proto.h"

static int enough_pizza_bis(fridge_t *f)
{
    if (f->olive < 8) {
        printf("\'make pizza\': not enough olive\n");
        return -1;
    }
    if (f->pepper < 8) {
        printf("\'make pizza\': not enough pepper\n");
        return -1;
    }
    if (f->ham < 4) {
        printf("\'make pizza\': not enough ham\n");
        return -1;
    }
    if (f->cheese < 3) {
        printf("\'make pizza\': not enough cheese\n");
        return -1;
    }
    return 0;
}

int enough_pizza(fridge_t *f)
{
    if (f->tomato < 5) {
        printf("\'make pizza\': not enough tomato\n");
        return -1;
    }
    if (f->dough < 1) {
        printf("\'make pizza\': not enough dough\n");
        return -1;
    }
    if (f->onion < 3) {
        printf("\'make pizza\': not enough onion\n");
        return -1;
    }
    return enough_pizza_bis(f);
}

int enough_pasta(fridge_t *f)
{
    if (f->tomato < 5)
        return printf("\'make pasta\': not enough tomato\n");
    if (f->pasta < 2) {
        printf("\'make pasta\': not enough pasta\n");
        return -1;
    }
    if (f->olive < 6) {
        printf("\'make pasta\': not enough olive\n");
        return -1;
    }
    if (f->ham < 4) {
        printf("\'make pasta\': not enough ham\n");
        return -1;
    }
    if (f->cheese < 3) {
        printf("\'make pasta\': not enough cheese\n");
        return -1;
    }
    return 0;
}
