/*
** EPITECH PROJECT, 2024
** midstar
** File description:
** mid of the star
*/

void line(int size)
{
    point(size * 2 + 1);
    space(size * 2 - 3);
    point(size * 2 + 1);
    enter();
}

void upmid(int size)
{
    int i = 1;

    for (; size > i; i++) {
        space(i);
        point(1);
        space(6 * size - 2 * i - 3);
        point(1);
        enter();
    }
}

void botmid(int size)
{
    int i = 1;

    for (; size + 1 > i; i++) {
        space(size - i + 1);
        point(1);
        space(4 * size + 2 * i - 5);
        point(1);
        enter();
    }
}

void bot(int size)
{
    int i = 1;

    for (; size > i; i++) {
        space(2 * size + i - 1);
        point(1);
        space(2 * size - 1 - 2 * i);
        point(1);
        enter();
    }
    space(3 * size - 1);
    point(1);
    enter();
}
