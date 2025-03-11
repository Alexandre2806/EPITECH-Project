/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** my_swap
*/

#include <unistd.h>
#include "my.h"

void my_swap(int *a, int *b)
{
    int d = *a;

    *a = *b;
    *b = d;
}
