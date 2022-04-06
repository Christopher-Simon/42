/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:44:50 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/05 15:52:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

int	flag_first(char c)
{
	if (c == '-' || c == '+' || c == ' '
		|| c == '0' || c == '#')
		return (1);
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	check_flags(char *s)
{
	int	i;

	i = 1;
	// printf("\nflag : %s\n", s);
	if (!ft_strchr(s, 'c') && !ft_strchr(s, 's')
		&& !ft_strchr(s, 'p') && !ft_strchr(s, 'd')
		&& !ft_strchr(s, 'i') && !ft_strchr(s, 'u')
		&& !ft_strchr(s, 'x') && !ft_strchr(s, 'X')
		&& !ft_strchr(&s[1], '%'))
		return (0);
	while (s[i] && !ft_isdigit(s[i]) && s[i] != '.')
	{
		if (!flag_first(s[i]))
			return (i);
		i++;
	}
	while (!ft_isalpha(s[i]) && s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return (i);
		i++;
	}
	return (0);
}

void	checker_one(char *s, char *str, int *j)
{
	int		i;
	char	*tab;
	int		d;

	tab = "#+ -0";
	i = *j;
	while (s[i] && (!ft_isdigit(s[i]) || s[i] == '0') && flag_first(s[i]))
	{
		d = 0;
		while (tab[d])
		{
			if (s[i] == tab[d] && str[d] == '.')
			{
				str[d] = tab[d];
				break ;
			}
			d++;
		}
		i++;
	}
	d = 0;
	*j = i;
}

void	checker_two(char *str, int *y, int c, int d)
{
	int	x;

	x = *y;
	while (str[d] && c < 3)
	{
		if (str[1] == '+')
			str[2] = '.';
		if (str[3] == '-')
			str[4] = '.';
		if (str[d] != '.')
		{
			if (c == 2 && str[d] == ' ' && str[3] == '-')
				ft_putchar_fd(str[3], 1);
			else if (c == 2 && str[d] == ' ' && str[4] == '0')
				ft_putchar_fd(str[4], 1);
			else
				ft_putchar_fd(str[d], 1);
			c++;
			x++;
		}
		d++;
	}
	*y = x;
}

int	put_flag(char *s)
{
	char	str[5];
	int		i;
	int		x;

	ft_memset(str, '.', 5);
	i = 1;
	x = 1;
	ft_putchar_fd('%', 1);
	checker_one(s, str, &i);
	checker_two(str, &x, 0, 0);
	ft_putstr_fd(&s[i], 1);
	x += ft_strlen(&s[i]);
	return (x);
}