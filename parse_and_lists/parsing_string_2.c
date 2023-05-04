/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_string_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:38:53 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/30 18:39:21 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_space(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
			{
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (i != k)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

char	**parse_arguments(char **av, int ac)
{
	char	**new;
	char	*str;
	int		i;

	i = 1;
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < ac)
	{
		str = ft_strjoin(str, av[i]);
		i++;
	}
	new = ft_split(str, ' ');
	free(str);
	return (new);
}
