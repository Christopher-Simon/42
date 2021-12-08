#include "get_next_line.h"
#include <stdio.h>


char    *fill_buffer(char *s1, char *s2)
{
    char    *s_join;
    s_join = ft_strjoin((char const*)s1,(char const*)s2);
    free (s1);
    free (s2);
    return (s_join);
}

int main(void)
{
    char    *s1;
    char    *s2;
    int i = ft_strlen("ceci est un long tes");
    int j = ft_strlen("ceci est la suite d'");
    s1 = (char *)malloc(sizeof(char)*(i+1));
    s2 = (char *)malloc(sizeof(char)*(j+1));
    ft_strlcpy(s1, "ceci est un long tes", i);
    ft_strlcpy(s2, "ceci est la suite d'", j);
    printf("s1 : %s\n", s1);
    printf("s2 : %s\n", s2);
    s1 = fill_buffer(s1, s2);
    printf("s1 : %s\n", s1);

    j = ft_strlen("ceci est la suite d'");
    s2 = (char *)malloc(sizeof(char)*(j+1));
    ft_strlcpy(s2, "Encore ?", j);
    s1 = fill_buffer(s1, s2);
    printf("s1 : %s\n", s1);
    free(s1);
}