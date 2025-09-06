/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:11:27 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/06 11:11:36 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
