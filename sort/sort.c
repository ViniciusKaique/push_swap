/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* sort.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:27:35 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/05 16:26:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_push **a, t_push **b, int size)
{
	if (size >= 2 && size <= 5)
	{
		if (size == 2)
			do_sort_2(a);
		else if (size == 3)
			do_sort_3(a);
		else if (size == 4 || size == 5)
			do_sort_5(a, b, size);
	}
	if (size >= 6)
	{
		do_index(a, size);
		// ATUALIZADO: Chamamos a função genérica 'do_sort_big' e decidimos
		// o tamanho do chunk com base no tamanho total da pilha.
		if (size <= 100)
			do_sort_big(a, b, 15);
		else
			do_sort_big(a, b, 30);
	}
}
