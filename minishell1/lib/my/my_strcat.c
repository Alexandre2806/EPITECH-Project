/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** strcat
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int taille = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++) {
        dest[taille + i] = src[i];
    }
    dest[taille + i] = '\0';
    return dest;
}
