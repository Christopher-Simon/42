/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:28:14 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/06 22:39:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char    *switch_buffer(int fd)
{
    
}

char    *get_next_line(int fd)
{
    char    *buf;
    char    *line; 
    int     ret;
    size_t     i;
    size_t     flag;

    flag == 0;
    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    ret = read(fd, buf, BUFFER_SIZE);
    buf[ret] = '\0';
    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
            flag == 1;
        i++;
    }
    printf("%ld\n", i);
    if (flag == 1)
    {
        line = (char *)malloc(sizeof(char) * i);
        ft_strlcpy(line, (const char *)buf, i);
    }
    return (line);
}

int main(void)
{
    int fd;
    int ret;
    
    fd = open("Test", O_RDONLY);
    if (fd == -1)
    {
        printf("non");
        return (0);
    }
    printf("%s\n", get_next_line(fd));
    if (close(fd) == -1)
    {
        printf("close echec");
        return (0);
    }
    printf("close succes");
    return (0);
}