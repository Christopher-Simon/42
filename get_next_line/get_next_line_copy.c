/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:28:14 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/08 15:30:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char    *get_buf(int fd, char *buf, int *final)
{
    int     ret;
    
    ret = read(fd, buf, BUFFER_SIZE);
    if (ret == 0)
    {
        (*final)++;
       // printf("final = %d\n", (*final));
    }
    buf[ret] = '\0';
    return (buf);
}

char    *backtrack(int fd, char *buf, char* memory, int *final)
{
    char    *line;
    size_t  i;

    if (ft_strchr(memory,'\n') == 0)
        get_buf(fd, buf, final);
    else 
        return (memory);
    /*if (ft_strlen(buf)<BUFFER_SIZE)
    {
        (*final)++;
        printf("%s\n", memory);
        printf("%s\n", buf);
    }*/
    //printf("%d\n", (*final));
    //printf("buf : %s\n", buf);
    i = 0;
    line = ft_strjoin(memory, buf);
    free (memory);
    if (!line)
        return (NULL);
    while (line[i] && line[i] != '\n')
        i++;
    //printf("line : %s\n\n", line);
    //printf("final : %d", *final);
    if (ft_strchr(line,'\n')==0 && *final == 0)
        line = backtrack(fd, buf, line, final);
    return (line);
}

char    *get_next_line(int fd)
{
    char            buf[BUFFER_SIZE + 1];
    char            *line;
    size_t          i;
    static char     *memory;
    int             final;
    
    final = 0;
    if (!memory)
    {
        memory = malloc(sizeof(char) + 1);
        if (!memory)
            return (0);
        memory[0] = '\0';
    }
    //printf("memory : %s\n", memory);
    //buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    line = backtrack(fd, buf, memory, &final);
    if (!*line)
    {
        //free (memory);
        free (line);
        //free (buf);
        return (NULL);
    }
    //printf("line ft : %s\n\n", line);
    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    //printf("i : %ld\n", ft_strlen(line) - i);
    memory = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!memory)
        return (0);
    if (!final)
    {
        ft_strlcpy(memory, &line[i+1], ft_strlen(line) - i + 1);
        line[i+1] = '\0';
    }
    else
        ft_strlcpy(memory, &line[i], ft_strlen(line) - i + 1);
    //printf("memory _ft: %s\n", memory);
    //free(buf);
    //printf("final %d\n", final);
    /*if (final > 0)
    {
        //printf("ca rentre\n");
        //printf("line :%s\n", line);
        
      //  free(memory);
        //printf("%s\n%s\n\n", line, NULL);
        return (line);
    }*/
    return (line);
}

int main(void)
{
    int fd;
    int ret;
    char *line;
    
    fd = open("Test", O_RDONLY);
    if (fd == -1)
    {
        printf("non");
        return (0);
    }
    line = get_next_line(fd);
    
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
       // line = get_next_line(fd);
        //i++;
    }
    free (line);
    /*line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);*/
    
    if (close(fd) == -1)
    {
        printf("\nclose echec");
        return (0);
    }
    printf("\nclose success");
    return (0);
}