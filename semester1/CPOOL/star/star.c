/*
** EPITECH PROJECT, 2024
** star
** File description:
** display a star
*/
void star2(int size)
{
    space(1);
    point(1);
    space(3);
    point(1);
    enter();
    point(3);
    space(1);
    point(3);
    enter();
    space(3);
    point(1);
    enter();
}

void star1(int size)
{
    if (size == 0)
        return;
    space(3);
    point(1);
    enter();
    point(3);
    space(1);
    point(3);
    enter();
    star2(size);
}

void star(unsigned int size)
{
    if (size <= 1) {
        star1(size);
    } else {
        head(size);
        line(size);
        upmid(size);
        botmid(size);
        line(size);
        bot(size);
    }
}

void head(int size)
{
    int i = 1;

    space(3 * size - 1);
    point(1);
    enter();
    for (; size > i; i++) {
        space(3 * size - i - 1);
        point(1);
        space(2 * i - 1);
        point(1);
        enter();
    }
}
