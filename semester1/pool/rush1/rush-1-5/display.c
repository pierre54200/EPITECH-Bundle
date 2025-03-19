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

void pointa(void)
{
    my_putchar('A');
}

void pointb(int x)
{
    for (; x > 0; x--)
        my_putchar('B');
}

void pointc(void)
{
    my_putchar('C');
}

void space(int x)
{
    for (; x > 0; x--)
        my_putchar(' ');
}
