/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:51:29 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 17:01:01 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node(t_list *b, int index)
{
	t_list	*tmp;
	int		count;

	tmp = b;
	count = 0;
	while (tmp != NULL)
	{
		if (count == index)
			return (tmp);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

int	max_count(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

int	compare(int a, int b)
{
	if (a >= b)
		return (1);
	else
		return (2);
}

int	check_count_of_sorted_elements(t_list **a)
{
	int		i;
	int		count;
	int		max_combo;
	int		position;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	while (i++ < (ft_lstsize(*a) - 1) && tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
			count++;
		else
		{
			max_combo = count;
			position = i;
			count = 0;
		}
	}
	if (max_combo + 1 < 5)
		return (-1);
	return (position);
}
