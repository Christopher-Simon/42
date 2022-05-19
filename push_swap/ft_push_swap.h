/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/19 13:08:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

typedef struct s_stack
{
	int		value;
	bool	begin;	
}	t_stack;

s_stack *ft_stack_begin(int d);
s_stack *ft_stack_to_front(int d);
s_stack *ft_stack_new(int d);

#endif