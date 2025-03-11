/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** my_isneg
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
