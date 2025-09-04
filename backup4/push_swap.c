/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* push_swap.c                                        :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2023/05/05 18:26:51 by aaybaz            #+#    #+#             */
/* Updated: 2025/09/04 19:50:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

// Função auxiliar para liberar a memória alocada por ft_split
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

// Função auxiliar para liberar todos os nós da pilha
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

// Função que preenche a pilha 'a' a partir dos argumentos validados
static int	fill_stack_from_args(char **args, t_push **a)
{
	int		i;
	int		num;
	t_push	*new_node;

	i = 0;
	while (args[i])
	{
		num = validate_and_convert(args[i]);
		new_node = malloc(sizeof(t_push));
		if (!new_node)
			do_error();
		new_node->number = num;
		new_node->next = NULL;
		lst_add_back(a, new_node);
		i++;
	}
	return (i); // Retorna a quantidade de números adicionados
}

// Nova função que junta todos os argumentos em uma string única
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
			do_error();
		full_str = ft_strjoin(tmp, " ");
		free(tmp);
		if (!full_str)
			do_error();
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
		return (0);
	joined_args = join_args(argc, argv);
	args = ft_split(joined_args, ' ');
	free(joined_args);
	if (!args || !*args) // Se não houver argumentos após o split
	{
		free_split(args);
		do_error(); // CORREÇÃO: Chamar do_error() em vez de sair silenciosamente
	}
	size = fill_stack_from_args(args, &a);
	check_rep(&a);
	free_split(args);
	if (!is_sorted(&a))
		sort(&a, &b, size);
	free_stack(&a);
	return (0);
}

