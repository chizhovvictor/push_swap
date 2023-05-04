/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:59:41 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/25 22:02:37 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_list(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*length;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	length = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!length)
		return ((void *)0);
	while (s1[i])
	{
		length[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		length[i + j] = s2[j];
		j++;
	}
	length[i + j] = ' ';
	length[i + j + 1] = '\0';
	free((char *)s1);
	return (length);
}
