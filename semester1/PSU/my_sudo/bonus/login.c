/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main
*/

#include "../include/proto.h"


char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void setup_log(int TPID, char *tty_nb, char *username)
{
    char *towrite = malloc(100);
    FILE *file = fopen(concat("files/", tty_nb), "w+");

    sprintf(towrite, "session : %d\nusers :\n%s\n", TPID, username);
    fwrite(towrite, strlen(towrite), 1, file);
    free(towrite);
    fclose(file);
}

void append_log(int TPID, char *username, char *tty_nb)
{
    char *file_str = malloc(1000);
    char **file_array = NULL;
    FILE *file = fopen(concat("files/", tty_nb), "r+");

    fread(file_str, 1000, 1, file);
    file_array = my_str_to_word_array(file_str);
    if (file_array[2] && TPID == atoi(file_array[2])){
        fwrite(username, strlen(username) + 1, 1, file);
        fwrite("\n", 2, 1, file);
    }
    fclose(file);
    if (file_array[2] && TPID != atoi(file_array[2])){
        remove(concat("files/", tty_nb));
        setup_log(TPID, tty_nb, username);
    }
    free(file_str);
    for (int i = 0; file_array[i]; i++){
        free(file_array[i]);
        }
    free(file_array);
}

void log_user(char *username)
{
    int TPID = getppid();
    char *tty_nb = strtok(ttyname(STDIN_FILENO), "/dev/pts/");
    FILE *file = fopen(concat("files/", tty_nb), "r+");

    if (file == NULL){
        setup_log(TPID, tty_nb, username);
    } else {
        fclose(file);
        append_log(TPID, username, tty_nb);
    }
}

int is_logged(char *username)
{
    char *line = NULL;
    char *tty_nb = strtok(ttyname(STDIN_FILENO), "/dev/pts/");
    int TPID = getppid();
    size_t len = 0;
    ssize_t nread = 0;
    FILE *file = fopen(concat("files/", tty_nb), "r");
    char *usercmp = malloc(sizeof(char) * (strlen(username) + 1));

    if (file == NULL){
        free(usercmp);
        return 0;
    }
    nread = getline(&line, &len, file);
    if (TPID != atoi(line + 10)){
        free(usercmp);
        return 0;
    }
    while (nread != -1){
        nread = getline(&line, &len, file);
        strncpy(usercmp, line, strlen(username));
        if (nread != -1 && strcmp(username, usercmp) == 0){
            free(usercmp);
            return 1;
        }
    }
    free(usercmp);
    return 0;
}
