/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:02:56 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/26 13:33:20 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_max_int(unsigned int res, int sign, t_list **stack)
{
	if (sign > 0)
	{
		if (res > 2147483647)
		{
			ft_lstclear(stack, (*del));
			write(1, "Error\n", 6);
			exit(1);
		}
		else
			return (res);
	}
	else if (sign < 0)
	{
		if (res > 2147483648)
		{
			ft_lstclear(stack, (*del));
			write(1, "Error\n", 6);
			exit(1);
		}
		else
			return (res);
	}
	return (0);
}

int	validation(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_dublicate(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = a;
	tmp2 = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_for_unsorted(t_list *a)
{
	t_list	*tmp;
	int		i;

	tmp = a;
	i = a->content;
	while (tmp)
	{
		if (i > tmp->content)
		{
			return (1);
		}
		i = tmp->content;
		tmp = tmp->next;
	}
	return (0);
}

t_list	*add_to_list(char **av)
{
	t_list	*a;
	int		check_number;
	int		i;
	int		num;

	a = NULL;
	check_number = 0;
	i = 0;
	while (av[i])
		check_number += validation(av[i++]);
	if (check_number == i)
	{
		i = 0;
		while (av[i])
		{
			num = ft_atoi(av[i++], &a);
			ft_lstadd_back(&a, ft_lstnew(num));
		}
		return (a);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
