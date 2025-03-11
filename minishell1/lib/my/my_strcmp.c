/*
** EPITECH PROJECT, 2024
** strcmp
** File description:
** strcmp
*/

#include "my.h"
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 84;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0' && s2[i] == '\0') {
            return (0);
        }
        i++;
    }
    return (s1[i] - s2[i]);
}
