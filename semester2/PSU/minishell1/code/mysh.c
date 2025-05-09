/*
** EPITECH PROJECT, 2025
** mysh.c
** File description:
** mysh
*/

#include "../include/proto.h"

char **home(char **stock, shell_t *shell)
{
    for (int i = 0; stock[i] != 0; i++) {
        if (stock[i][0] == '~' && my_strlen(stock[i]) == 1)
            stock[i] = my_strdup(shell->home);
    }
    return stock;
}

int mysh(char *line, shell_t *shell)
{
    char **stock = my_str_to_word_array(line);

    free(line);
    if (stock[0][0] == 0)
        return 0;
    home(stock, shell);
    if (build_exe(stock, shell) == 1)
        return 0;
    exec(stock, shell);
    free_stock(stock);
    return 0;
}
