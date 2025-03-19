/*
** EPITECH PROJECT, 2024
** rush1
** File description:
** t1
*/

void body(int x, int y)
{
    for (; y > 2; y--) {
        vertical();
        space(x - 2);
        vertical();
        my_putchar('\n');
    }
}

void base(int x)
{
    circle();
    line(x - 2);
    circle();
    my_putchar('\n');
}

void spec_case_1(y)
{
    circle();
    my_putchar('\n');
    for (; y > 2; y--) {
        vertical();
        my_putchar('\n');
    }
    circle();
    my_putchar('\n');
}

void spec_cases(int x, int y)
{
    if (x == 1 && y == 1) {
        circle();
        my_putchar('\n');
        return;
    }
    if (y == 1) {
        circle();
        line(x - 2);
        circle();
        my_putchar('\n');
        return;
    }
    if (x == 1) {
        spec_case_1(y);
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        error();
        return;
    }
    if (x == 1 || y == 1) {
        spec_cases(x, y);
    } else {
        base(x);
        body(x, y);
        base(x);
    }
}
