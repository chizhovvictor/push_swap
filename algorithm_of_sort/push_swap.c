/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:37:33 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 19:46:44 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac >= 2)
	{
		check_space(av);
		av = parse_arguments(av, ac);
		a = add_to_list(av);
		if (check_dublicate(a) && check_for_unsorted(a))
			sort_list(&a);
	}
	ft_lstclear(&a, (*del));
	return (0);
}
