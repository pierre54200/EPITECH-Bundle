/*
** EPITECH PROJECT, 2024
** ls.h
** File description:
** ls.h
*/
#ifndef PROTO_LS
  #define PROTO_LS
int my_ls(char **av, char *flag, int result);
int my_ls_empty(char *flag);
int my_ls_one(char **av, char *flag, int result);
int flag_l(const char *stock, int test);
int my_ls_flagless(char *av, int test);
int my_octal_stock(int nb);
int better_str(char *av2);
char **order(char **stock, int test);
char **my_swap_tab(char **stock, int i);
int my_ls_empty_r(char *flag);
int my_ls_r(char *av, char *flag, int result);
int my_ls_flagless_multi(char *av, int test);
int my_ls_one_r(char *av, char *flag, int result);
void isaflag(char *flag);
int my_ls_one_t(char *av, char *flag, int result);
int my_ls_t(char *av, char *flag, int result);
int my_ls_empty_t(char *flag);
#endif /* PROTO_LS */
