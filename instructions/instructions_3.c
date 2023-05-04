/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:31:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/25 21:53:58 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head, int i)
{
	t_list	*sec_last;
	t_list	*last;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	sec_last = NULL;
	last = *head;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **head, int i)
{
	t_list	*sec_last;
	t_list	*last;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	sec_last = NULL;
	last = *head;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **head_a, t_list **head_b, int i)
{
	rra(head_a, 1);
	rrb(head_b, 1);
	if (i == 0)
		write(1, "rrr\n", 4);
}
