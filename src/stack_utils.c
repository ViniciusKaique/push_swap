/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:12:03 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/06 11:12:05 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	minnum(t_push **a)
{
	int		min;
	t_push	*p;

	min = (*a)->number;
	p = *a;
	p = p->next;
	while (p != NULL)
	{
		if (p->number < min)
			min = p->number;
		p = p->next;
	}
	return (min);
}

int	maxnum(t_push **a)
{
	int		max;
	t_push	*p;

	max = (*a)->number;
	p = *a;
	p = p->next;
	while (p != NULL)
	{
		if (p->number > max)
			max = p->number;
		p = p->next;
	}
	return (max);
}

int	maxindex(t_push **a)
{
	int		max_index;
	t_push	*p;

	p = *a;
	max_index = p->index;
	p = p->next;
	while (p != NULL)
	{
		if (max_index < p->index)
			max_index = p->index;
		p = p->next;
	}
	return (max_index);
}
int	is_sorted(t_push **a)
{
	t_push	*tmp;

	if (!a || !*a)
		return (1);
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
