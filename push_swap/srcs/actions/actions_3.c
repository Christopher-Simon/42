/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:09:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rr(t_full_stack *stack, int silent)
{
	if (!silent)
		ft_printf("rr\n");
	rotate_a(stack, 1);
	rotate_b(stack, 1);
}

void	rrr(t_full_stack *stack, int silent)
{
	if (!silent)
		ft_printf("rrr\n");
	reverse_rotate_a(stack, 1);
	reverse_rotate_b(stack, 1);
}
