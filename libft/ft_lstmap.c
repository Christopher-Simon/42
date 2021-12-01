/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:25:22 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 09:33:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*second_list;
	t_list	*second_list_back;
	
	(*f)(lst->content);
	second_list = ft_lstnew(lst->content);
	if (!second_list )
	{
		ft_lstclear(&second_list, del);
		return (0);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		(*f)(lst->content);
		second_list_back = ft_lstnew(lst->content);
		if (!second_list_back )
		{
			ft_lstclear(&second_list, del);
			return (0);
		}
		ft_lstadd_back(&second_list, second_list_back);	
		lst = lst->next;
	}
	return (second_list);	
}
