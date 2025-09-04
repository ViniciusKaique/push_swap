/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* do_rr.c                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:28:03 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/04 20:02:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

// Lógica de rotate, agora separada
static void	rotate(t_push **stack)
{
	t_push	*last;
	t_push	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_push **list_a)
{
	rotate(list_a);
	write(1, "ra\n", 3);
}

void	rb(t_push **list_b)
{
	rotate(list_b);
	write(1, "rb\n", 3);
}

void	rr(t_push **list_a, t_push **list_b)
{
	rotate(list_a);
	rotate(list_b);
	write(1, "rr\n", 3);
}
