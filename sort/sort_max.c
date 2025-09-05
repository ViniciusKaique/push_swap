/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* sort_max.c                                         :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:27:13 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/05 16:25:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Ordena pilhas grandes (> 5 elementos) movendo elementos em "chunks"
 * (pedaços) da pilha 'a' para a 'b' com base em seus índices.
 * * @param a A pilha de origem.
 * @param b A pilha de destino.
 * @param chunk_size O tamanho do grupo de números a ser movido para 'b' 
 * em cada iteração.
 */
void	do_sort_big(t_push **a, t_push **b, int chunk_size)
{
	int	i;

	i = 0;
	while ((*a) != NULL)
	{
		// Se o índice for menor que o contador 'i', significa que pertence
		// a um chunk anterior. Movemos para 'b' e rotacionamos 'b' para
		// colocar este elemento no lugar certo.
		if (i > 0 && (*a)->index < i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		// Se o índice pertencer ao chunk atual, apenas movemos para 'b'.
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		// Se o índice for de um chunk futuro, rotacionamos 'a' para procurar
		// por números que pertençam ao chunk atual.
		else if ((*a)->index >= i + chunk_size)
			ra(a);
	}
	// Após mover todos para 'b', movemos de volta para 'a' em ordem.
	do_sort_pa(a, b);
}
