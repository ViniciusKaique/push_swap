/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:36:26 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/08 13:36:28 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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

void	check_rep(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

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
