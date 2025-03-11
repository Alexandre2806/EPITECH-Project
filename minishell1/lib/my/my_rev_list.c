/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-myls-alexandre.delain
** File description:
** my_rev_list.c
*/

#include "my.h"

void my_rev_list(char **list, int size)
{
    char *temp;
    int i = 0;
    int j = size - 1;

    while (i < j) {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
        i++;
        j--;
    }
}
