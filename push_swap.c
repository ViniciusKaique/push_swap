/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:39:29 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/08 13:39:30 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static void	free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

static int	fill_stack_from_args(char **args, t_list **a)
{
	int		i;
	int		num;
	t_list	*new_node;

	i = 0;
	while (args[i])
	{
		num = parse_number(args[i]);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			exit_error();
		new_node->number = num;
		new_node->next = NULL;
		ft_lst_add_back(a, new_node);
		i++;
	}
	return (i);
}
static int	parse_input(int argc, char **argv, t_list **a)
{
	int		i;
	int		total_size;
	char	**split_args;

	i = 1;
	total_size = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !*split_args)
		{
			free_split(split_args);
			exit_error();
		}
		total_size += fill_stack_from_args(split_args, a);
		free_split(split_args);
		i++;
	}
	return (total_size);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		total_size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return(0);
	total_size = parse_input(argc, argv, &a);
	check_rep(&a);
	if (!is_sorted(&a))
		sort(&a, &b, total_size);
	free_stack(&a);
	return (0);
}

