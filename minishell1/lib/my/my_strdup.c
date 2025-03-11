/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-myls-alexandre.delain
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dup;

    if (src == NULL)
        return NULL;
    dup = malloc(sizeof(char) * (my_strlen(src) + 10));
    if (dup == NULL)
        return NULL;
    my_strcpy(dup, src);
    return dup;
}
