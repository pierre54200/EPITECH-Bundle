/*
** EPITECH PROJECT, 2024
** Display t3
** File description:
** t3
*/

static void my_display(char c)
{
    write(2, &c, 1);
}

int error(void)
{
    my_display('I');
    my_display('n');
    my_display('v');
    my_display('a');
    my_display('l');
    my_display('i');
    my_display('d');
    my_display(' ');
    my_display('s');
    my_display('i');
    my_display('z');
    my_display('e');
    my_display('\n');
    return;
}

void base_down(int x)
{
    my_putchar('C');
    line(x - 2);
    my_putchar('C');
    my_putchar('\n');
}

void line(int x)
{
    for (; x > 0; x--)
        my_putchar('B');
}

void vertical(void)
{
    my_putchar('B');
}

void space(int x)
{
    for (; x > 0; x--)
        my_putchar(' ');
}
