/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:08:35 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/23 17:14:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
*/
typedef struct s_list
{
	void		*content;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(void	*content)
{
	t_list *root;

	root = malloc(sizeof(t_list));	
	if (!root)
		return (0);
	root->content = content;
	root->next = NULL;
	return (root);		
}

void	ft_print_lst(t_list *node)
{
	while (node != NULL)
	{
		printf("%d->", *(int *)node->content);
		node = node->next;
	}
	printf("NULL\n\n");
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

t_list	*ft_lstlast(t_list *lst)
{
	while(lst->next != NULL)
		lst = lst->next;
	return (lst);
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

void	delete(void *x)
{
//	free(x);
}	

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);	
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

void	f(void *content)
{
	*(int *)content += 1;
}


void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

void	*f2(void *content)
{
	*(int *)content += 1;
}

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
		if (!second_list )
		{
			ft_lstclear(&second_list, del);
			return (0);
		}
		ft_lstadd_back(&second_list, second_list_back);	
		lst = lst->next;
	}
	return (second_list);	
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
	ft_print_lst(new_list);
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
