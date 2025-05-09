/*
** EPITECH PROJECT, 2025
** fridge
** File description:
** fridge
*/

#include "../proto.h"

void save_file(fridge_t *fridge)
{
    FILE *file = fopen(".save", "w+");

    if (file == NULL)
        return;
    fprintf(file, "tomato = %d\n", fridge->tomato);
    fprintf(file, "dough = %d\n", fridge->dough);
    fprintf(file, "onion = %d\n", fridge->onion);
    fprintf(file, "pasta = %d\n", fridge->pasta);
    fprintf(file, "olive = %d\n", fridge->olive);
    fprintf(file, "pepper = %d\n", fridge->pepper);
    fprintf(file, "ham = %d\n", fridge->ham);
    fprintf(file, "cheese = %d\n", fridge->cheese);
    fclose(file);
}

void disp_fridge(fridge_t *fridge)
{
    printf("tomato = %d\n", fridge->tomato);
    printf("dough = %d\n", fridge->dough);
    printf("onion = %d\n", fridge->onion);
    printf("pasta = %d\n", fridge->pasta);
    printf("olive = %d\n", fridge->olive);
    printf("pepper = %d\n", fridge->pepper);
    printf("ham = %d\n", fridge->ham);
    printf("cheese = %d\n", fridge->cheese);
}
