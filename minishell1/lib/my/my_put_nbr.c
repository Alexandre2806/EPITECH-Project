/*
** EPITECH PROJECT, 2024
** putnbr
** File description:
** putnbr
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_put_nbr(int number)
{
    if (number < 0) {
        number = - number;
        my_putchar('-');
    }
    if (number < 10) {
        number = number + 48;
        my_putchar(number);
    } else {
        my_put_nbr(number / 10);
        my_put_nbr(number % 10);
    }
}
