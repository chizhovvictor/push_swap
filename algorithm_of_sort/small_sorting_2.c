/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <vchizhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:23:12 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 14:25:32 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_max_a(t_list **a, int max_a_position)
{
	t_list	*tmp;
	int		i;
	int		max_a;

	tmp = *a;
	i = 0;
	while (i < max_a_position)
	{
		max_a = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (max_a);
}

int	find_position_max_a(t_list **a)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		position;

	tmp = *a;
	max = tmp->content;
	i = 1;
	while (tmp)
	{
		if (max <= tmp->content)
		{
			max = tmp->content;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

int	find_position_min_a(t_list **a)
{
	t_list	*tmp;
	int		i;
	int		min;
	int		position;

	tmp = *a;
	min = tmp->content;
	i = 0;
	position = 0;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

int	find_position_number(t_list **a, t_list **b)
{
	int		i;
	int		max_a_position;
	int		max_a;
	int		position;
	t_list	*tmp;

	max_a_position = find_position_max_a(a);
	max_a = return_max_a(a, max_a_position);
	i = 0;
	tmp = *a;
	position = -1;
	while (tmp)
	{
		if (tmp->content >= (*b)->content && max_a >= tmp->content)
		{
			max_a = tmp->content;
			position = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (position == -1)
		position = find_position_min_a(a);
	return (position);
}
