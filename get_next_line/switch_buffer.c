#include "get_next_line.h"
#include <stdio.h>


char    *fill_buffer(char *s1, char *s2)
{
    s1 = ft_strjoin((char const*)s1,(char const*)s2);
    free(s2);
    return (s1);
}

int main(void)
{
    char    *s1;
    char    *s2;
    s1 = (char *)malloc(sizeof(char)*21);
    s2 = (char *)malloc(sizeof(char)*21);
    ft_strlcpy(s1, "ceci est un long test, peut-être trop long", 20);
    ft_strlcpy(s2, "ceci est la suite d'un long test, peut-être trop long", 20);
    printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);
    s1 = fill_buffer(s1, s2);
    free(s1);
    /*printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);
    s2 = (char *)malloc(sizeof(char)*21);
    ft_strlcpy(s2, "Encore ?", 20);
    s1 = fill_buffer(s1, s2);
    printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);*/
}