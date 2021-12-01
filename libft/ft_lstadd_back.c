/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:24:12 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 09:31:05 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*mem;
	mem = *alst;
	new->next = NULL;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	(*alst)->next = new;	
	*alst = mem;
}
