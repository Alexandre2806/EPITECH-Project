/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-alexandre.delain
** File description:
** mysh.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"

extern char **environ;

char *my_getenv(const char *name)
{
    for (int i = 0; environ[i] != NULL; i++) {
        if (my_strncmp(environ[i], name, my_strlen(name))
            == 0 && environ[i][my_strlen(name)] == '=') {
            return &environ[i][strlen(name) + 1];
        }
    }
    return NULL;
}

void execute_command(char **args, char *path)
{
    char cmd_path[1024];

    cmd_path[0] = '\0';
    while (path != NULL) {
        my_strcpy(cmd_path, path);
        my_strcat(cmd_path, "/");
        my_strcat(cmd_path, args[0]);
        if (execve(cmd_path, args, environ) == -1) {
            path = strtok(NULL, ":");
        } else
            break;
    }
}

void command_verif(char **args)
{
    char *home = my_getenv("HOME");

    if (my_strcmp(args[0], "cd") != 0)
        return;
    if (args[1] == NULL && home) {
        chdir(home);
        return;
    }
    if (my_strcmp(args[1], "~") == 0 && home)
        chdir(home);
    if (chdir(args[1]) == -1) {
        write(2, args[1], my_strlen(args[1]));
        write(2, ": Not a directory.\n", 20);
    }
}

static void exec_child(char **args)
{
    char *env_path = my_getenv("PATH");
    char *path = strtok(env_path, ":");

    execute_command(args, path);
    write(2, args[0], my_strlen(args[0]));
    write(2, ": Command not found.\n", 21);
    exit(84);
}

static void tokenize(char *input, char **args)
{
    char *token = strtok(input, " \n\t");
    int i = 0;

    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " \n\t");
        i++;
    }
    args[i] = NULL;
}

static void fork_and_exec(char **args)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(84);
    }
    if (pid == 0) {
        exec_child(args);
    } else
        waitpid(pid, NULL, 0);
}

void command_exec(char *input)
{
    char *args[100];

    tokenize(input, args);
    if (args[0] == NULL)
        return;
    if (my_strcmp(args[0], "exit") == 0) {
        free(input);
        exit(0);
    }
    if (my_strcmp(args[0], "cd") == 0) {
        command_verif(args);
    } else
        fork_and_exec(args);
}

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$> ", 3);
        read = getline(&input, &len, stdin);
        if (read == -1) {
            free(input);
            return 0;
        }
        command_exec(input);
    }
    free(input);
    return 0;
}
