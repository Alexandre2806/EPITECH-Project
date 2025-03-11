/*
** EPITECH PROJECT, 2024
** revstr
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char *rev = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = len - 1;

    while (j != -1) {
        rev[i] = str[j];
        i++;
        j--;
    }
    rev[len] = '\0';
    return rev;
}
