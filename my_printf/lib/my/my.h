/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my header
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>
    #include <stdarg.h>
    #include <dirent.h>

void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_put_float(double nb, int precision);
int my_put_octal(int nb);
int my_put_unsigned_nbr(int nb);
int my_put_hexa(int nb, int majuscule);
int my_put_pointer(void *p);
int my_put_e(double nb, int majuscule);
int my_put_g(double nb, int majuscule);
int case_g(char const *format, va_list args, int i);
int case_e(char const *format, va_list args, int i);
int case_fi(char const *format, va_list args, int i);
int case_ou(char const *format, va_list args, int i);
int case_p(char const *format, va_list args, int i);
int case_cpourcent(char const *format, va_list args, int i);
int case_sd(char const *format, va_list args, int i);
int case_x(char const *format, va_list args, int i);
int my_put_signed_long(long nb);
int my_put_signed_longlong(long long nb);
int my_put_unsigned_long(long nb);
int my_put_unsigned_longlong(long long nb);
int case_l(char const *format, va_list args, int i);
int find_number(char const *format, int debut);
int my_put_minus(int nb, int decalage);
int case_minus(char const *format, va_list args, int i);
int my_put_plus(int nb, int decal);
int case_plus(char const *format, va_list args, int i);
int my_put_zero(int nb, int decal);
int case_zero(char const *format, va_list args, int i);
int count_int(int nb);
int my_str_to_int(char const *str);

#endif
