/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:36:37 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/06 10:36:21 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sort_arr(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
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

static int	*stack_to_array(t_push *a, int *array)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		array[i] = a->number;
		a = a->next;
		i++;
	}
	return (array);
}

static int	index_chr(int *sorted_array, int num)
{
	int	i;

	i = 0;
	while (sorted_array[i] != num)
		i++;
	return (i);
}

void	set_index(t_push **a, int size)
{
	t_push	*tmp;
	int		i;
	int		*array;
	int		*copy_array;

	tmp = *a;
	array = ft_calloc(size, sizeof(int));
	copy_array = ft_calloc(size, sizeof(int));
	if (!array || !copy_array)
		return ;
	stack_to_array(tmp, array);
	ft_memcpy(copy_array, array, size * sizeof(int));
	sort_arr(array, size);
	i = 0;
	while (tmp != NULL)
	{
		tmp->index = index_chr(array, copy_array[i]);
		tmp = tmp->next;
		i++;
	}
	free(array);
	free(copy_array);
}
