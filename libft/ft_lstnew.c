/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:08:35 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/22 18:10:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
*/
typedef struct t_list
{
	void		*x;
	struct t_list	*next;
} t_list;

t_list	*ft_lstnew(void	*content)
{
	t_list *root;

	root = malloc(sizeof(t_list));	
	root->x = content;
	root->next = NULL;
	return (root);		
}

void	ft_print_lst(t_list *node)
{
	while (node != NULL)
	{
		printf("%p->", node->x);
		node = node->next;
	}
	printf("NULL\n");
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;	
	*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while(lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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

/*
t_list	*ft_lstlast(t_list *lst)
{
	while(lst->next != NULL)
		lst = lst->next;
	return (lst);
}
*/
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
	ft_lstadd_front(&list, new_list);
	ft_print_lst(list);
	printf("size : %d\n", ft_lstsize(list));
	printf("add to back\n");
	p = &z;
	new_list = ft_lstnew(p);	
	ft_lstadd_back(&list, new_list);
	ft_print_lst(list);
	return (0);
}
