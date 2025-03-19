/*
** EPITECH PROJECT, 2024
** diplay
** File description:
** display char
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

void circle(void)
{
    my_putchar('o');
}

void line(int x)
{
    for (; x > 0; x--)
        my_putchar('-');
}

void vertical(void)
{
    my_putchar('|');
}

void space(int x)
{
    for (; x > 0; x--)
        my_putchar(' ');
}
