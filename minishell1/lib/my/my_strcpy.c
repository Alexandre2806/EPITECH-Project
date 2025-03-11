/*
** EPITECH PROJECT, 2024
** copy
** File description:
** copy
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
