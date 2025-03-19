/*
** EPITECH PROJECT, 2025
** passwd.c
** File description:
** password verification
*/

#include "../include/proto.h"

static int normalcrypt(pswdhash_t *pswd, int *pos, char *line)
{
    int dotpos = 0;
    int count = 0;

    for (int i = 0; line[i]; i++){
        if (line[i] == ':')
            count++;
        if (line[i] == ':' && count == 2){
            dotpos = i;
            break;
        }
    }
    pswd->salt = bmalloc(sizeof(char) * (pos[2] - pos[1] + 2));
    pswd->hash = bmalloc(sizeof(char) * (dotpos - pos[2] + 2));
    pswd->fullpw = bmalloc(sizeof(char) * (dotpos - pos[0] + 2));
    if (pswd->fullpw == NULL || pswd->hash == NULL || pswd->salt == NULL)
        return 84;
    snprintf(pswd->salt, pos[2] - pos[1] + 1, "%s", line + pos[1]);
    snprintf(pswd->hash, dotpos - pos[2] + 1, "%s", line + pos[2]);
    snprintf(pswd->fullpw, dotpos - pos[0] + 1, "%s", line + pos[0]);
    return 0;
}

static int yescrypt(pswdhash_t *pswd, int *pos, char *line)
{
    int dotpos = 0;
    int count = 0;

    for (int i = 0; line[i]; i++){
        if (line[i] == ':')
            count++;
        if (line[i] == ':' && count == 2){
            dotpos = i;
            break;
        }
    }
    pswd->salt = bmalloc(sizeof(char) * (pos[3] - pos[0] + 2));
    pswd->hash = bmalloc(sizeof(char) * (dotpos - pos[0] + 2));
    pswd->fullpw = bmalloc(sizeof(char) * (dotpos - pos[0] + 2));
    if (pswd->fullpw == NULL || pswd->hash == NULL || pswd->salt == NULL)
        return 84;
    snprintf(pswd->salt, pos[3] - pos[0] + 1, "%s", line + pos[0]);
    snprintf(pswd->hash, dotpos - pos[0] + 1, "%s", line + pos[0]);
    snprintf(pswd->fullpw, dotpos - pos[0] + 1, "%s", line + pos[0]);
    return 0;
}

void show_passwd(pswdhash_t pswd)
{
    printf("Password :\n sai : %s\nprefix : %s\nsalt : %s\nhash"
    " : %s\nfullpw: %s\nEND\n", pswd.sai, pswd.prefix, pswd.salt, pswd.hash
    , pswd.fullpw);
}

static int freepswd(pswdhash_t *pswd)
{
    free(pswd->hash);
    free(pswd->sai);
    free(pswd->prefix);
    free(pswd->salt);
    return 1;
}

int makepswd(pswdhash_t *pswd, char *line, char *user)
{
    int pos[5];
    int count = 0;

    for (int i = 0; line[i]; i++){
        if (line[i] == '$'){
            pos[count] = i;
            count++;
        }
    }
    pswd->sai = bmalloc(sizeof(char) * (strlen(user) + 2));
    pswd->prefix = bmalloc(sizeof(char) * (pos[1] - pos[0] + 2));
    if (pswd->prefix == NULL || pswd->sai == NULL)
        return 84;
    strcpy(pswd->sai, user);
    snprintf(pswd->prefix, pos[1] - pos[0] + 1, "%s", line + pos[0]);
    if (strcmp("$y", pswd->prefix) == 0)
        yescrypt(pswd, pos, line);
    else
        normalcrypt(pswd, pos, line);
    return 0;
}

pswdhash_t getpassword(char *user)
{
    char *line = find_in_file("/etc/shadow", user);
    pswdhash_t pswd;

    if (line != NULL)
        makepswd(&pswd, line, user);
    return (pswd);
}

int check_password(char *input, char *user)
{
    pswdhash_t pswd = getpassword(user);
    int malloclen = (strcmp(pswd.prefix, "$y") == 0) ? strlen(pswd.hash) + 1 :
    strlen(pswd.hash) + strlen(pswd.prefix) + strlen(pswd.salt) + 1;
    char *salt = bmalloc(sizeof(char) * (malloclen + 1));

    if (salt == NULL)
        return 84;
    if (strcmp(pswd.prefix, "$y") == 0){
        strcpy(salt, pswd.salt);
    } else
        sprintf(salt, "%s%s%s", pswd.prefix, pswd.salt, pswd.hash);
    if (strcmp(pswd.fullpw, crypt(input, salt)) == 0){
        free(salt);
        return freepswd(&pswd);
    }
    free(salt);
    freepswd(&pswd);
    return 0;
}
