/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:11:01 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 17:19:13 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_full_sorting(t_list **a, t_list **b)
{
	int	i;
	int	position_for_number;
	int	ra_case;
	int	rb_case;

	ra_case = 0;
	rb_case = 0;
	i = ft_lstsize(*b);
	while (i > 0)
	{
		position_analysis(a, b, ra_case, rb_case);
		i--;
	}
	position_for_number = find_position_min_a(a);
	if ((ft_lstsize(*a) / 2) < position_for_number)
		while ((ft_lstsize(*a) - position_for_number++) > 0)
			rra(a, 0);
	else
		while (position_for_number-- > 0)
			ra(a, 0);
}

void	full_sorting(t_list **a, t_list **b)
{
	int	count_sorted_elements;

	count_sorted_elements = check_count_of_sorted_elements(a);
	if (count_sorted_elements != -1)
	{
		if ((ft_lstsize(*a) / 2) < count_sorted_elements)
			while (count_sorted_elements++ < (ft_lstsize(*a) - 1))
				rra(a, 0);
		else
			while (count_sorted_elements-- >= 0)
				ra(a, 0);
	}
	while (ft_lstsize(*a) > 5)
		pb(b, a, 0);
	sorting_5(a, b);
	next_full_sorting(a, b);
}

void	push_in_b(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 3 && check_for_unsorted(*a))
		sorting_3(a);
	else if (ft_lstsize(*a) <= 5)
		sorting_5(a, b);
	else
		full_sorting(a, b);
}

void	sort_list(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (ft_lstsize(*a) == 2)
	{
		sa(a, 0);
		return ;
	}
	push_in_b(a, &b);
}
