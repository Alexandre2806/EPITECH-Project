/*
** EPITECH PROJECT, 2024
** my
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <time.h>

typedef struct flags_s {
    int flags_a;
    int flags_r;
    int flags_l;
} flags_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_cmp_case(const char *s1, const char *s2);
char *my_strdup(char const *src);
void assort_tri(char **tab);
void check_flags(char **argv, flags_t *flags);
void disp(char **names, flags_t *flags);
void free_all(char **names);
void my_rev_list(char **list, int size);
int names_nbr(char **names);
char *my_strdup(char const *src);
char *get_filename(char **argv, int i);
//void algo(char const *format, va_list args)
#endif
