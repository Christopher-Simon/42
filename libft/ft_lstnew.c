/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:08:35 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/17 17:47:10 by chsimon          ###   ########.fr       */
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

t_list	*ft_lstnew(void *content)
{
	t_list *root;

	root = malloc(sizeof(t_list));	
	root->x = content;
	root->next = NULL;
	return (root);		
}


int	main(void)
{
	int	x[3] = {0,1,2};
	
	ft_lstnew(x);
	return (0);
}
