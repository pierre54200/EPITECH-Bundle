/*
** EPITECH PROJECT, 2024
** Rush 1
** File description:
** Task 2
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

void spec_cases(int x, int y)
{
    if (x == 1 && y == 1) {
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    if (y == 1) {
        my_putchar('*');
        line(x - 2);
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    if (x == 1) {
        spec_case_1(y);
    }
}

void base_up(int x)
{
    my_putchar('/');
    line(x - 2);
    my_putchar(92);
    my_putchar('\n');
}

void spec_case_1(y)
{
    my_putchar('*');
    my_putchar('\n');
    for (; y > 2; y--) {
        vertical();
        my_putchar('\n');
    }
    my_putchar('*');
    my_putchar('\n');
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
        base_up(x);
        body(x, y);
        base_down(x);
    }
}
