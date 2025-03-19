/*
** EPITECH PROJECT, 2024
** main
** File description:
** maintask05
*/

int main(int argc, char **argv)
{
    int i = 0;

    for (; argv[i] != '\0'; i++);
    for (; i >= 0; i--) {
        my_putstr(argv[i - 1]);
        my_putchar('\n');
        }
    return 0;
}
