/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:39:39 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/06 10:39:42 by vinpache         ###   ########.fr       */
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

static void	free_stack(t_push **stack)
{
	t_push	*current;
	t_push	*tmp;

	current = *stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}

static int	fill_stack_from_args(char **args, t_push **a)
{
	int		i;
	int		num;
	t_push	*new_node;

	i = 0;
	while (args[i])
	{
		num = parse_number(args[i]);
		new_node = malloc(sizeof(t_push));
		if (!new_node)
			exit_error();
		new_node->number = num;
		new_node->next = NULL;
		lst_add_back(a, new_node);
		i++;
	}
	return (i);
}

static char	*join_args(int argc, char **argv)
{
	char	*full_str;
	char	*tmp;
	int		i;

	full_str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(full_str, argv[i]);
		free(full_str);
		if (!tmp)
			exit_error();
		full_str = ft_strjoin(tmp, " ");
		free(tmp);
		if (!full_str)
			exit_error();
		i++;
	}
	return (full_str);
}

int	main(int argc, char *argv[])
{
	t_push	*a;
	t_push	*b;
	char	**args;
	char	*joined_args;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit_error();
	joined_args = join_args(argc, argv);
	args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!args || !*args)
	{
		free_split(args);
		exit_error();
	}
	size = fill_stack_from_args(args, &a);
	check_rep(&a);
	free_split(args);
	if (!is_sorted(&a))
		sort(&a, &b, size);
	free_stack(&a);
	return (0);
}
