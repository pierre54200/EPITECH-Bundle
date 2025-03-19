/*
** EPITECH PROJECT, 2025
** hitbox.c
** File description:
** hitbox
*/

#include "../include/proto.h"

sfRectangleShape *create_rect(sfVector2f position)
{
    sfRectangleShape *rect;
    sfVector2f size = {20, 20};

    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfGreen);
    return rect;
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle;

    circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    return circle;
}
