/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:37:05 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/08 13:37:06 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_list **a)
{
	t_list	*current;
	t_list	*comparer;
	int		index;

	current = *a;
	while (current)
	{
		comparer = *a;
		index = 0;
		while (comparer)
		{
			if (current->number > comparer->number)
				index++;
			comparer = comparer->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	max_pos(t_list **b, int max_index, int size)
{
	t_list	*p;
	int		index;
	int		found;

	index = 0;
	found = 0;
	p = *b;
	while (p && !found)
	{
		if (p->index == max_index)
			found = 1;
		else
			index++;
		p = p->next;
	}
	if (index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

int	min_pos(t_list **a, int min, int size)
{
	t_list	*p;
	int		min_index;
	int		found;

	min_index = 0;
	found = 0;
	p = *a;
	while (p != NULL && !found)
	{
		if (p->number == min)
			found = 1;
		else
			min_index++;
		p = p->next;
	}
	if (min_index < size / 2 + size % 2)
		return (0);
	else
		return (1);
}

void	sort_pa(t_list **a, t_list **b)
{
	while (*b != NULL)
	{
		int max = maxindex(b);
		int size_b = ft_lst_size(b);

		// se o maior não está no topo, gira 'b'
		if ((*b)->index != max)
		{
			if (!max_pos(b, max, size_b))
				rb(b);
			else
				rrb(b);
		}
		else
			pa(a, b);
	}
}


