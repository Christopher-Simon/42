/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 08:45:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

int	main(void)
{
	int		tab[] = {5 , 15 , 1};
	int 	count;
	t_stack	*a;
	t_stack	*b;

	count = 0;
	a = ft_begin(tab[0]);
	b = NULL;
	while (count++ < 2)
		ft_stack_new(a, tab[count]);
	print_stack(a, b);
	a = swap_a(a);
	print_stack(a, b);
	b = push_b(&a, b);
	print_stack(a, b);
	return (0);
}