/*
** EPITECH PROJECT, 2024
** B-PSU-100-LIL-1-1-myls-alexandre.delain
** File description:
** my_cmp_case.c
*/

int my_lower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int my_cmp_case(const char *s1, const char *s2)
{
    char c1;
    char c2;

    while (*s1 && *s2) {
        c1 = my_lower((unsigned char)*s1);
        c2 = my_lower((unsigned char)*s2);
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return my_lower((unsigned char)*s1) - my_lower((unsigned char)*s2);
}
