/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:03:45 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/27 00:04:40 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_result(t_list **b)
{
	(*b)->count = 0;
	(*b)->rrb = 0;
	(*b)->ra = 0;
	(*b)->rra = 0;
	(*b)->count_rr = 0;
	(*b)->count_rrr = 0;
	(*b)->count_ra = 0;
	(*b)->count_rb = 0;
	(*b)->count_rra = 0;
	(*b)->count_rrb = 0;
	(*b)->result = 0;
}

void	sort_a(t_list **a, int ra_case, int rra_case)
{
	while (ra_case-- > 0)
		ra(a, 0);
	while (rra_case-- > 0)
		rra(a, 0);
}

void	sort_b(t_list **b, int rb_case, int rrb_case)
{
	while (rb_case-- > 0)
		rb(b, 0);
	while (rrb_case-- > 0)
		rrb(b, 0);
}

void	sort_a_b(t_list **a, t_list **b, int rr_case, int rrr_case)
{
	while (rr_case-- > 0)
		rr(a, b, 0);
	while (rrr_case-- > 0)
		rrr(a, b, 0);
	pa(a, b, 0);
}
