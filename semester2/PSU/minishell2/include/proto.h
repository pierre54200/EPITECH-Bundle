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
#include <fcntl.h>

#ifndef PROTO_H
    #define PROTO_H
    #define PROTO_H
    #define AC_GREEN "\033[1;32m"
    #define AC_BLUE "\033[1;34m"
    #define AC_NORMAL "\x1b[m"
    #define AC_RED "\033[1;31m"
typedef struct cmd_s {
    char **command;
    char *command_line;
    int pipe;
    int stdin;
    char *stdin_str;
    int stdout;
    char *stdout_str;
} cmd_t;

typedef struct list_node_s {
    struct cmd_s *cmd;
    struct list_node_s *next;
    struct list_node_s *previous;
} list_node_t;

typedef struct list_s {
    int size;
    struct list_node_s *first;
    struct list_node_s *last;
} list_t;

typedef struct s_shell {
    struct list_s *cmd;
    char *home;
    char **env;
    char **path;
    int exit;
    char *cd;
    int test;
} shell_t;

// basic functions //
int my_strcmp(char *s1, char *s2);
int my_getnbr(char *str);
int my_putstr(char *str);
char **my_str_to_word_array(char *str, char *sep);
int my_strlen(char *str);
int my_tablen(char **tab);
char *bmalloc(int size);
char **btmalloc(int size);
int is_a_nbr(char *str);
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
int my_str_isprintable(char const *str);
int my_puts(char *str);
int is_a_char(char a);
int find_in_tab_line(char **tab, char *str, int pos);
char *my_strcot(char *dest, char *src);
int counter(char *source, char *want);
int is_in(char want, char *source);
char *del_part(char *str, int begin, int len);
char *dup_part(char *str, int begin, int *len, char *sep);
void clean_str(char *str);
int first_sign(char *str, char want);

// execute //
int exec(list_node_t *list, shell_t *shell, char **av);
int build_exe(char **stock, shell_t *shell);
void execute_in_child(char **av, shell_t *shell);
void error_exe(int waitime, shell_t *shell);
void pipe_exec(list_node_t *list, shell_t *shell);

// shell //
int mysh(char *line, shell_t *shell);
int loop(char **env, shell_t *shell);
void get_cmd(char *line, shell_t *shell);

// free //
void free_everything(shell_t *shell);
void free_array(char **tab);
void free_env(shell_t *shell);
void free_path(shell_t *shell);
void free_cmd(shell_t *shell);

// built-in //
void cd_caster(char **stock, shell_t *shell);
void my_setenv(char **stock, shell_t *shell);
void my_unsetenv(char **stock, shell_t *shell);


// cmd //
char **split_cmd(char *str, char *sep);


// signal //
void sigint(int);
void sigfault(int);

int my_puttostr(char *str, int n, char c);
int my_putnstr(char *str, int n);
int my_put_nbr(int nb);

// list //
list_t *push_front(list_t *list, cmd_t *cmd);
list_t *push_back(list_t *list, cmd_t *cmd);
list_t *pop_back_list(list_t *list);
void clear_list(list_t *list);

// stdin //
void init_stdin(cmd_t *cmd, char **str);
int swap_stdin(list_node_t *list, int *des, int *fd);

// stdout //
void init_stdout(cmd_t *cmd, char **str);
int swap_stdout(list_node_t *list, int *des, int *fd);
#endif /* PROTO_H */
