/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:36:37 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/05 17:01:14 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

// A libft não possui uma função de sort, então mantemos esta por enquanto.
// Uma melhoria futura poderia ser a troca por um algoritmo mais eficiente.
int	*sort_arr(int *array, int size) {
  int i;
  int j;
  int tmp;

  i = 0;
  while (i < size - 1) {
    j = i + 1;
    while (j < size) {
      if (array[i] > array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
      j++;
    }
    i++;
  }
  return (array);
}

// Converte a lista encadeada para um array de inteiros.
static int	*do_arr(t_push *a, int *array) {
  int i;

  i = 0;
  while (a != NULL) {
    array[i] = a->number;
    a = a->next;
    i++;
  }
  return (array);
}

// Encontra o índice de um número em um array ordenado.
static int	index_chr(int *sorted_array, int num) {
  int i;

  i = 0;
  while (sorted_array[i] != num)
    i++;
  return (i);
}

// Atribui um índice a cada elemento da pilha com base em sua posição ordenada.
// Esta versão usa ft_calloc e ft_memcpy da libft para mais segurança e clareza.
void	do_index(t_push **a, int size) {
  t_push *tmp;
  int i;
  int *array;
  int *copy_array;

  tmp = *a;
  // USA ft_calloc: Mais seguro que malloc, já inicializa a memória com zeros.
  array = ft_calloc(size, sizeof(int));
  copy_array = ft_calloc(size, sizeof(int));
  if (!array || !copy_array)
    return ;
  do_arr(tmp, array);
  // USA ft_memcpy: Substitui a função manual 'do_copy_arr'.
  ft_memcpy(copy_array, array, size * sizeof(int));
  sort_arr(array, size);
  i = 0;
  while (tmp != NULL) {
    tmp->index = index_chr(array, copy_array[i]);
    tmp = tmp->next;
    i++;
  }
  free(array);
  free(copy_array);
}

