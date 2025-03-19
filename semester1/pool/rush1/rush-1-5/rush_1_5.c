/*
** EPITECH PROJECT, 2024
** rush1
** File description:
** t5
*/

void body(int x, int y)
{
    for (; y > 2; y--) {
        pointb(1);
        space(x - 2);
        pointb(1);
        my_putchar('\n');
    }
}

void base1(int x)
{
    pointa();
    pointb(x - 2);
    pointc();
    my_putchar('\n');
}

void spec_cases_2(int y)
{
    for (; y > 0; y--) {
        pointb(1);
        my_putchar('\n');
    }
}

void spec_cases_1(int x, int y)
{
    if (x == 1 && y == 1) {
        pointb(1);
        my_putchar('\n');
        return;
    }
    if (y == 1) {
        pointb(x);
        my_putchar('\n');
        return;
    }
    if (x == 1) {
        spec_cases_2(y);
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        error();
        return;
    }
    if (x == 1 || y == 1) {
        spec_cases_1(x, y);
    } else {
        base1(x);
        body(x, y);
        base2(x);
    }
}
