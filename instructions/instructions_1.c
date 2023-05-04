/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:31:05 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/30 18:38:35 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head, int i)
{
	t_list	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **head, int i)
{
	t_list	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b, int i)
{
	sa(head_a, 1);
	sb(head_b, 1);
	if (i == 0)
		write(1, "ss\n", 3);
}

void	pa(t_list **dest_ref, t_list **source_ref, int i)
{
	t_list	*new_node;

	if (*source_ref == NULL)
		return ;
	new_node = *source_ref;
	*source_ref = (*source_ref)->next;
	new_node->next = *dest_ref;
	*dest_ref = new_node;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **dest_ref, t_list **source_ref, int i)
{
	t_list	*new_node;

	if (*source_ref == NULL)
		return ;
	new_node = *source_ref;
	*source_ref = (*source_ref)->next;
	new_node->next = *dest_ref;
	*dest_ref = new_node;
	if (i == 0)
		write(1, "pb\n", 3);
}
