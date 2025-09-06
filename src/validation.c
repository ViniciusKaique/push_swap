/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:28:49 by aaybaz            #+#    #+#             */
/*   Updated: 2025/09/06 10:37:04 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// Converte string para int validando formato e overflow
int	parse_number(const char *str)
{
	long	num;
	int		i;

	if (!str || *str == '\0')
		exit_error();
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		exit_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error();
		i++;
	}
	num = ft_atol(str);
	if (num < -2147483648 || num > 2147483647)
		exit_error();
	return ((int)num);
}

void	check_rep(t_push **a)
{
	t_push	*tmp1;
	t_push	*tmp2;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				exit_error();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
