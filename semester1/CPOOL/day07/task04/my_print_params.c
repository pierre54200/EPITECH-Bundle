/*
** EPITECH PROJECT, 2024
** main
** File description:
** main task04
*/

int main(int argc, char **argv)
{
    int i = 0;

    while (argv[i] != '\0') {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
