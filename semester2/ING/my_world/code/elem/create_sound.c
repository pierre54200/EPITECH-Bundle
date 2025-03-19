/*
** EPITECH PROJECT, 2025
** create_sound.c
** File description:
** sounds
*/

#include "../../include/proto.h"

void create_sound(world_t *world)
{
    world->dig = sfSound_create();
    sfSound_setBuffer(world->dig, sfSoundBuffer_createFromFile(DIG));
}
