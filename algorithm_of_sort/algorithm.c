/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:46:54 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/27 00:05:04 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_down_rotation(t_list **b)
{
	if ((*b)->rrb != 0 && (*b)->rra != 0)
	{
		(*b)->count += max_count((*b)->rrb, (*b)->rra);
		(*b)->result = compare((*b)->rrb, (*b)->rra);
		if ((*b)->result == 1)
		{
			(*b)->count_rrr = (*b)->rra;
			(*b)->count_rrb = (*b)->rrb - (*b)->rra;
		}
		else
		{
			(*b)->count_rrr = (*b)->rrb;
			(*b)->count_rra = (*b)->rra - (*b)->rrb;
		}
	}
	else
	{
		(*b)->count += (*b)->rrb + (*b)->rra;
		if ((*b)->rrb)
			(*b)->count_rrb = (*b)->rrb;
		if ((*b)->rra)
			(*b)->count_rra = (*b)->rra;
	}
}

void	count_up_rotation(t_list **b)
{
	if ((*b)->rb != 0 && (*b)->ra != 0)
	{
		(*b)->count += max_count((*b)->rb, (*b)->ra);
		(*b)->result = compare((*b)->rb, (*b)->ra);
		if ((*b)->result == 1)
		{
			(*b)->count_rr = (*b)->ra;
			(*b)->count_rb = (*b)->rb - (*b)->ra;
		}
		else
		{
			(*b)->count_rr = (*b)->rb;
			(*b)->count_ra = (*b)->ra - (*b)->rb;
		}
	}
	else
	{
		(*b)->count += (*b)->rb + (*b)->ra;
		(*b)->count_rb = (*b)->rb;
		(*b)->count_ra = (*b)->ra;
	}
}

void	count_of_rotation_for_position(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	(*b)->rb = i;
	free_result(b);
	if ((ft_lstsize((*b)) / 2) < i)
	{
		(*b)->rrb = ft_lstsize((*b)) - i;
		(*b)->rb = 0;
	}
	tmp = get_node((*b), i);
	(*b)->ra = find_position_number(a, &tmp);
	if ((ft_lstsize(*a) / 2) < (*b)->ra)
	{
		(*b)->rra = ft_lstsize(*a) - (*b)->ra;
		(*b)->ra = 0;
	}
}

void	algorithm(t_list **a, t_list **b, int i)
{
	count_of_rotation_for_position(a, b, i);
	count_up_rotation(b);
	count_down_rotation(b);
}

void	position_analysis(t_list **a, t_list **b, int ra_case, int rb_case)
{
	int	i;
	int	rra_case;
	int	rrb_case;
	int	rr_case;
	int	rrr_case;

	i = -1;
	(*b)->start = ft_lstsize(*a);
	while (++i < ft_lstsize(*b))
	{
		algorithm(a, b, i);
		if ((*b)->count < (*b)->start)
		{
			(*b)->start = (*b)->count;
			ra_case = (*b)->count_ra;
			rb_case = (*b)->count_rb;
			rra_case = (*b)->count_rra;
			rrb_case = (*b)->count_rrb;
			rr_case = (*b)->count_rr;
			rrr_case = (*b)->count_rrr;
		}
	}
	sort_a(a, ra_case, rra_case);
	sort_b(b, rb_case, rrb_case);
	sort_a_b(a, b, rr_case, rrr_case);
}
