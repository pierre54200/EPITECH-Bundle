/*
** EPITECH PROJECT, 2025
** proto.h
** File description:
** proto
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#ifndef PROTO_H
    #define PROTO_H
    #define PROTO_H
    #define AC_GREEN "\033[1;32m"
    #define AC_BLUE "\033[1;34m"
    #define AC_NORMAL "\x1b[m"
    #define AC_RED "\033[1;31m"
typedef struct s_shell {
    char *home;
    char **env;
    char **path;
    int exit;
    char *cd;
} shell_t;
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);
int my_putstr(char *str);
char **my_str_to_word_array(char *str);
int my_strlen(char *str);
int my_tablen(char **tab);
int mysh(char *line, shell_t *shell);
char *bmalloc(int size);
char **btmalloc(int size);
int is_a_nbr(char *str);
int exec(char **av, shell_t *shell);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
char **my_tabcpy(char **dest, char **src);
char **my_tabdup(char **src);
char *find_in_tab(char **tab, char *str, int pos);
int find_in_string(char *src, char *str);
char *my_strncpy(char *dest, char *src, int len);
char *my_strndup(char *src, int len);
char **get_paths(char **env);
char *my_strntcpy(char *dest, char *src, int len, char to);
char *my_strntdup(char *src, int len, char to);
char *my_strcat(char *dest, char const *src);
int loop(char **env, shell_t *shell);
int build_exe(char **stock, shell_t *shell);
void free_everything(shell_t *shell);
void free_stock(char **stock);
int my_str_isprintable(char const *str);
void cd_caster(char **stock, shell_t *shell);
int my_puts(char *str);
void my_setenv(char **stock, shell_t *shell);
void my_unsetenv(char **stock, shell_t *shell);
int is_a_char(char a);
void sigint(int);
void sigfault(int);
int find_in_tab_line(char **tab, char *str, int pos);
void free_env(shell_t *shell);
char *my_strcot(char *dest, char *src);
void free_path(shell_t *shell);
int my_puttostr(char *str, int n, char c);
int my_putnstr(char *str, int n);
int my_put_nbr(int nb);
#endif /* PROTO_H */
