/*
** EPITECH PROJECT, 2025
** hidenp.c
** File description:
** hidenp
*/

#include <unistd.h>

int find_hide(char *a1, char *a2)
{
    int i = 0;

    for (int j = 0; a2[j] != 0; j++) {
        if (a1[i] == a2[j])
            i++;
        if (a1[i] == 0) {
            write(1, "1\n", 2);
            return 0;
        }
    }
    write(1, "0\n", 2);
    return 0;
}

int hidenp(char *a1, char *a2)
{
    int len1 = 0;
    int len2 = 0;

    for (; a1[len1] != 0; len1++);
    for (; a2[len2] != 0; len2++);
    if (len2 < len1) {
        write(1, "0\n", 2);
        return 0;
    }
    if (len1 == 0) {
        write(1, "1\n", 2);
        return 0;
    }
    find_hide(a1, a2);
    return 0;
}

void error(void)
{
    write(2, "Usage: ./hidenp needle haystack\n", 32);
    return;
}

int main(int ac, char **av)
{
    if (ac != 3) {
        error();
        return 84;
    }
    return hidenp(av[1], av[2]);
}
