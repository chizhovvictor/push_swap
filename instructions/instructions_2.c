/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:31:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/25 21:53:38 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head, int i)
{
	t_list	*first_node;
	t_list	*last_node;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	first_node = *head;
	last_node = *head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	*head = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **head, int i)
{
	t_list	*first_node;
	t_list	*last_node;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	first_node = *head;
	last_node = *head;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	*head = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rr(t_list **head_a, t_list **head_b, int i)
{
	ra(head_a, 1);
	ra(head_b, 1);
	if (i == 0)
		write(1, "rr\n", 3);
}
