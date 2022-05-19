/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:26:15 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 09:47:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>


void	ft_print_lst(t_list *node)
{
	while (node != NULL)
	{
		printf("%d->", *(int *)node->content);
		node = node->next;
	}
	printf("NULL\n\n");
}

void	delete(void *x)
{
//	free(x);
}	




void	f(void *content)
{
	*(int *)content += 1;
}




void	*f2(void *content)
{
	*(int *)content += 1;
}



int	main(void)
{
	int	x = 1;
	int	y = 5;
	int	z = 7;
	t_list	*list;
	t_list	*new_list;

	void	*p = &x;
	printf("create a list\n");
	list = ft_lstnew(p);
	ft_print_lst(list);
	
	printf("add to front\n");
	p = &y;
	new_list = ft_lstnew(p);	

	printf("add to front\n");
	ft_lstadd_front(&list, new_list);
	ft_print_lst(list);
	printf("size : %d\n", ft_lstsize(list));
	
	printf("---dernier element de la liste %d\n\n", *(int *)ft_lstlast(list)->content);
	
	printf("add to back\n");
	p = &z;
	new_list = ft_lstnew(p);	
	ft_lstadd_back(&list, new_list);
	ft_print_lst(list);
	
	printf("---dernier element de la liste %d\n\n", *(int *)ft_lstlast(list)->content);
	printf("---+1 tout all content\n");
	ft_lstiter(list,f);	
	ft_print_lst(list);
	
	printf("---+1 tout all content et nouvelle liste\n");
	ft_print_lst(list);
	new_list = ft_lstmap(list, f2, delete);	
	ft_print_lst(new_list);
	
	printf("---del one list\n");
	new_list=list->next;
	ft_lstdelone(list, delete);
	list = new_list;
	ft_print_lst(list);
	printf("---clear list\n");	
	ft_lstclear(&list, delete);
	return (0);
}
