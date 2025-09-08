/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:36:57 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/08 13:36:58 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **a, t_list **b, int size)
{
	if (size >= 2 && size <= 5)
	{
		if (size == 2)
			sort_2(a);
		else if (size == 3)
			sort_3(a);
		else if (size == 4 || size == 5)
			sort_5(a, b, size);
	}
	if (size >= 6)
	{
		set_index(a);
		if (size <= 100)
			sort_big(a, b, 15);
		else
			sort_big(a, b, 30);
	}
}
void	sort_big(t_list **a, t_list **b, int chunk_size)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b);
			// em vez de rb(b) sozinho, podemos combinar:
			if ((*a) && (*a)->index >= i + chunk_size)
				rr(a, b); // ra + rb juntos
			else
				rb(b);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i + chunk_size)
			ra(a);
	}
	sort_pa(a, b);
}

void	sort_2(t_list **a)
{
	if ((*a)->next->number < (*a)->number)
		sa(a);
}

void	sort_3(t_list **a)
{	
	if ((*a)->number == maxnum(a))
	{
		ra(a);
		if ((*a)->number > (*a)->next->number)
			sa(a);
	}
	else if ((*a)->number == minnum(a) && (*a)->next->number == maxnum(a))
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->number != minnum(a) && (*a)->number > (*a)->next->number)
		sa(a);
	else if ((*a)->number != minnum(a) && (*a)->number < (*a)->next->number)
		rra(a);
}

void	sort_5(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while (i < size / 2 + size % 2)
	{
		if ((*a)->number > minnum(a) && !min_pos(a, minnum(a), ft_lst_size(a)))
			ra(a);
		else if ((*a)->number > minnum(a) && min_pos(a, minnum(a), ft_lst_size(a)))
			rra(a);
		else if ((*a)->number == minnum(a))
		{
			pb(a, b);
			i++;
		}
	}
	if ((*a)->number != minnum(a))
		sa(a);
	while ((*b))
		pa(a, b);
}