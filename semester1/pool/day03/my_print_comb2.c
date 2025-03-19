/*
** EPITECH PROJECT, 2024
** my_print_comb2.c
** File description:
** task06
*/
int ascending_order2(char a, char b, char c, char d)
{
    if (d * 10 + c < a + b * 10) {
        my_putchar(d);
        my_putchar(c);
        my_putchar(' ');
        my_putchar(b);
        my_putchar(a);
        if (d == '9' && c == '8') {
            return (0);
        } else {
            my_putchar(',');
            my_putchar(' ');
        }
    }
    return (0);
}

int ascension2(int thousand, int hundred, int dozen, int digit)
{
    while (thousand < ':') {
        if (digit == '9') {
            digit = '0';
            dozen = dozen + 1;
        } else {
            digit = digit + 1;
        }
        if (dozen > '9') {
            dozen = '0';
            hundred = hundred + 1;
            }
        if (hundred > '9') {
            hundred = '0';
            thousand = thousand + 1;
            }
            ascending_order2(digit, dozen, hundred, thousand);
    }
    return (0);
}

int my_print_comb2(void)
{
    int mainthousand = '0';
    int mainhundred = '0';
    int maindozen = '0';
    int maindigit = '0';

    ascension2(mainthousand, mainhundred, maindozen, maindigit);
}
