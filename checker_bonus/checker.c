/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:26:43 by vchizhov          #+#    #+#             */
/*   Updated: 2023/05/04 14:05:46 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_result_of_checker(t_list *a, t_list *b)
{
	if (a == NULL)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	if (!check_for_unsorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
	{
		return (0);
	}
}

void	check_command2(char *command, t_list **a, t_list **b)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "rb\n", len))
		rb(b, 1);
	else if (!ft_strncmp(command, "rr\n", len))
		rr(a, b, 1);
	else if (!ft_strncmp(command, "rra\n", len))
		rra(a, 1);
	else if (!ft_strncmp(command, "rrb\n", len))
		rrb(b, 1);
	else if (!ft_strncmp(command, "rrr\n", len))
		rrr(a, b, 1);
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	check_command(char *command, t_list **a, t_list **b)
{
	int	len;

	len = ft_strlen(command);
	if (!ft_strncmp(command, "sa\n", len))
		sa(a, 1);
	else if (!ft_strncmp(command, "sb\n", len))
		sb(b, 1);
	else if (!ft_strncmp(command, "ss\n", len))
		ss(a, b, 1);
	else if (!ft_strncmp(command, "pa\n", len))
		pa(a, b, 1);
	else if (!ft_strncmp(command, "pb\n", len))
		pb(b, a, 1);
	else if (!ft_strncmp(command, "ra\n", len))
		ra(a, 1);
	else
		check_command2(command, a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*command;

	b = NULL;
	if (ac >= 2)
	{
		check_space(av);
		av = parse_arguments(av, ac);
		a = add_to_list(av);
		command = get_next_line(0);
		if (check_dublicate(a))
		{
			while (command > 0)
			{
				check_command(command, &a, &b);
				free(command);
				command = get_next_line(0);
			}
			final_result_of_checker(a, b);
		}
	}
	ft_lstclear(&a, (*del));
	return (0);
}
