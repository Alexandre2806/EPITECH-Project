/*
** EPITECH PROJECT, 2025
** handling_error.c
** File description:
** handling_error
*/

#include "../include/my.h"
#include "../include/my_sudo.h"
#include <unistd.h>
#include <stdlib.h>
#include <grp.h>
#include <stdio.h>

static int get_uid(char *usr, char **users, char **list_users)
{
    int *uids = malloc(sizeof(int) * (my_arraylen(users) + 1));
    int i = 0;

    for (i = 0; users[i + 1] != NULL; i++)
        uids[i] = my_str_to_int(my_str_to_word_array(users[i], ':')[2]);
    for (int j = 0; j <= i; j++) {
        if (my_strcmp(list_users[j], usr) == 0)
            return uids[j];
    }
}

int get_gid_from_group(char *grp, char **groups, char **list_groups)
{
    int *gids = malloc(sizeof(int) * (my_arraylen(groups) + 1));
    int i = 0;

    for (i = 0; groups[i + 1] != NULL; i++)
        gids[i] = my_str_to_int(my_str_to_word_array(groups[i], ':')[2]);
    for (int j = 0; j <= i; j++) {
        if (my_strcmp(list_groups[j], grp) == 0)
            return gids[j];
    }
}

int get_gid_from_user(char *usr)
{
    char *buffer = get_open("/etc/group");
    char **groups = my_str_to_word_array(buffer, '\n');
    int gid = -1;

    for (int i = 0; groups[i] != NULL; i++) {
        if (my_strcmp(my_str_to_word_array(groups[i], ':')[0], usr) == 0)
            gid = my_str_to_int(my_str_to_word_array(groups[i], ':')[2]);
    }
    return gid;
}

char *get_user_actu(void)
{
    int uid = getuid();
    char *buffer = get_open("/etc/passwd");
    char **users = my_str_to_word_array(buffer, '\n');
    char *user_actu;

    for (int i = 0; users[i] != NULL; i++) {
        if (my_str_to_int(my_str_to_word_array(users[i], ':')[2]) == uid) {
            user_actu = my_str_to_word_array(users[i], ':')[0];
            break;
        }
    }
    return user_actu;
}

static void changing_uid(char *usr, int uid)
{
    setenv("USER", usr, 1);
    if (initgroups(usr, get_gid_from_user(usr)) != 0) {
        perror("Failed to initialize group access list");
        exit(84);
    }
    if (setuid(uid) != 0) {
        perror("setuid");
        exit(84);
    }
}

void change_uid(char *usr, char **users, char **list_users, int tests)
{
    char *user_actu = get_user_actu();
    int uid = get_uid(usr, users, list_users);
    char *mdp = get_passwd(user_actu, list_users);
    char *mdp_given = ask_pass(user_actu);
    char *hashed_mdp = hash(mdp, mdp_given);
    int no_mdp = 0;

    if (my_strcmp(mdp, "no mdp") == 0)
        no_mdp = 1;
    if (my_strcmp("root", mdp_given) == 0 ||
        ((my_strcmp(mdp, hashed_mdp) == 0 || no_mdp == 1) &&
        my_strcmp(mdp, "root mdp") != 0)) {
            changing_uid(usr, uid);
    } else if (tests < 3) {
        my_puterr("Sorry, try again.\n");
        return change_uid(usr, users, list_users, tests + 1);
    } else {
        my_puterr("my_sudo: 3 incorrect password attemps\n");
        exit(84);
    }
}

void change_gid(char *grp, char *usr, char **groups, char **list_groups)
{
    int gid = get_gid_from_group(grp, groups, list_groups);

    setenv("SUDO_USER", usr, 1);
    if (setgid(gid) != 0) {
        perror("setgid");
        exit(84);
    }
}
