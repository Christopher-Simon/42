/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 14:25:32 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_PRINTF_H_
# define _PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_flags
{
	int	size;
	int	width;
	int	prec;
	int	nb_size;
	int	neg;
	int	minus;
	int plus;
	int space;
	int zero;
} t_flags;

int	ft_printf(const char *s, ...);
int	find_nb_size(t_flags *flag, long int n);
int	find_prec(t_flags *flag, const char *s);
int	find_width(t_flags *flag, const char *s);
int find_hash(t_flags *flag, const char *s);
int find_zero(t_flags *flag, const char *s);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
char *ft_dec_to_hex(unsigned long i);
char *ft_itoa_long(long int n);
void get_flags(t_flags *flag, const char *s);
int flag_c(t_flags flag, int x, const char *s, int c);
int flag_s(t_flags flag, int x, const char *s, char *str);
int flag_p(t_flags flag, int x, const char *s, unsigned long i);
int flag_d(t_flags flag, int x, const char *s, int d);

#endif
