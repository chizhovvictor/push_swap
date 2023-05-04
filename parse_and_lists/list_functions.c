/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:57:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/25 21:58:19 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		return (0);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del(int content)
{
	int	a;

	a = content;
	a = 0;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		a = ft_lstlast(*lst);
		a->next = new;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
