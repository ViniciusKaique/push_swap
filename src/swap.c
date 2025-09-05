/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* do_ss.c                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:28:28 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/04 20:01:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

// Lógica de swap, agora separada
static void	swap(t_push **stack)
{
	int	first;
	int	second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = (*stack)->next->number;
	second = (*stack)->number;
	(*stack)->number = first;
	(*stack)->next->number = second;
}

void	sa(t_push **list_a)
{
	swap(list_a);
	write(1, "sa\n", 3);
}

void	sb(t_push **list_b)
{
	swap(list_b);
	write(1, "sb\n", 3);
}

void	ss(t_push **list_a, t_push **list_b)
{
	swap(list_a);
	swap(list_b);
	write(1, "ss\n", 3);
}
