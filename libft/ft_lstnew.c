/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:08:35 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/19 14:00:04 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
*/
typedef struct t_list
{
	int		x;
	struct t_list	*next;
} t_list;

t_list	*ft_lstnew(int content)
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
		printf("%d", node->x);
		node = node->next;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;
	tmp = malloc(sizeof(t_list));
	tmp->x = new;
	tmp->next = *alst;	
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
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	tmp->x = new;
	tmp->next = NULL;
	if (alst == NULL)
	{
		alst = tmp;
	}
	while (alst->next != NULL)
		alst = alst->next;
	alst = tmp;
}


t_list	*ft_lstlast(t_list *lst)
{
	while(lst->next != NULL)
		lst = lst->next;
}

int	main(void)
{
	int	x = 1;	
	t_list *list;

	list = ft_lstnew(x);
	//ft_lstadd_front(list, new);
	ft_print_lst(list);		
	return (0);
}
