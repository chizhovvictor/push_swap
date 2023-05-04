/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <vchizhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:43:46 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 14:22:21 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			sa(a, 0);
			rra(a, 0);
		}
		else if (((*a)->next->content < (*a)->next->next->content)
			&& ((*a)->content > (*a)->next->next->content))
			ra(a, 0);
		else if (((*a)->next->content < (*a)->next->next->content)
			&& ((*a)->content < (*a)->next->next->content))
			sa(a, 0);
	}
	else if ((*a)->next->content > (*a)->content)
	{
		if ((*a)->content > (*a)->next->next->content)
			rra(a, 0);
		else if (((*a)->content < (*a)->next->next->content)
			&& ((*a)->next->content > (*a)->next->next->content))
		{
			rra(a, 0);
			sa(a, 0);
		}
	}
}

void	start_sorting_5(t_list **a, t_list **b)
{
	if (!check_for_unsorted(*a))
		return ;
	pb(b, a, 0);
	pb(b, a, 0);
	if (ft_lstsize(*a) == 2 && check_for_unsorted(*a))
		sa(a, 0);
	else if (ft_lstsize(*a) == 3 && check_for_unsorted(*a))
	{
		if (!check_for_unsorted(*a))
			return ;
		sorting_3(a);
	}
}

void	sorting_5(t_list **a, t_list **b)
{
	int	position_for_number;
	int	i;

	i = 0;
	start_sorting_5(a, b);
	while (i++ < 2)
	{
		position_for_number = find_position_number(a, b);
		if ((ft_lstsize(*a) / 2) < position_for_number)
			while ((ft_lstsize(*a) - position_for_number++) > 0)
				rra(a, 0);
		else
			while (position_for_number-- > 0)
				ra(a, 0);
		pa(a, b, 0);
	}
	position_for_number = find_position_min_a(a);
	if ((ft_lstsize(*a) / 2) < position_for_number)
		while ((ft_lstsize(*a) - position_for_number++) > 0)
			rra(a, 0);
	else
		while (position_for_number-- > 0)
			ra(a, 0);
}
