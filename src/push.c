/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:11:19 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/06 11:11:21 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_push **list_a, t_push **list_b)
{
	t_push	*tmp;

	tmp = *list_b;
	*list_b = tmp->next;
	tmp->next = *list_a;
	*list_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_push **list_a, t_push **list_b)
{
	t_push	*tmp;

	tmp = *list_a;
	*list_a = tmp->next;
	tmp->next = *list_b;
	*list_b = tmp;
	write(1, "pb\n", 3);
}
