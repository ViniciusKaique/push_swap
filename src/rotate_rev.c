/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* do_rrr.c                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:28:15 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/04 20:03:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

// Lógica de reverse rotate, agora separada
static void	reverse_rotate(t_push **stack)
{
	t_push	*last;
	t_push	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	prev->next = NULL;
}

void	rra(t_push **list_a)
{
	reverse_rotate(list_a);
	write(1, "rra\n", 4);
}

void	rrb(t_push **list_b)
{
	reverse_rotate(list_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push **list_a, t_push **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	write(1, "rrr\n", 4);
}
