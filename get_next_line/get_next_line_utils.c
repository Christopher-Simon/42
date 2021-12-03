/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:04:52 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/03 16:46:27 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t  ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
        s++;
    return (i);
}

void    ft_putchar_fd(char *s, int fd)
{
    write(1, s, ft_strlen(s));
}