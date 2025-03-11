/*
** EPITECH PROJECT, 2024
** ncopy
** File description:
** ncopy
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
