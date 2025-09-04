/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:27:35 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/04 19:27:37 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Em push_swap.h */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Incluindo a libft, que nos dá acesso a todas as suas funções
# include "libft/libft.h"

// Includes padrão
# include <stdlib.h>
# include <unistd.h>

// Estrutura da nossa pilha
typedef struct s_push
{
	int				number;
	int				index;
	struct s_push	*next;
} t_push; // <-- O PONTO E VÍRGULA FALTANDO ESTAVA AQUI

// --- Funções de Parsing e Validação (src/utils_3.c) ---
int					validate_and_convert(const char *str);
void				check_rep(t_push **a);

// --- Operações (src/do_xx.c) ---
void				sa(t_push **list_a);
void				sb(t_push **list_b);
void				ss(t_push **list_a, t_push **list_b);
void				pa(t_push **list_a, t_push **list_b);
void				pb(t_push **list_a, t_push **list_b);
void				ra(t_push **list_a);
void				rb(t_push **list_b);
void				rr(t_push **list_a, t_push **list_b);
void				rra(t_push **list_a);
void				rrb(t_push **list_b);
void				rrr(t_push **list_a, t_push **list_b);

// --- Algoritmo de Sort (sort/) ---
void				sort(t_push **a, t_push **b, int count);
void				do_sort_2(t_push **a);
void				do_sort_3(t_push **a);
void				do_sort_5(t_push **a, t_push **b, int size);
void				do_sort_100(t_push **a, t_push **b);
void				do_sort_500(t_push **a, t_push **b);
void				do_sort_pa(t_push **a, t_push **b);

// --- Funções Utilitárias (src/utils_*.c) ---
void				do_error(void);
void				do_index(t_push **a, int size);
int					is_sorted(t_push **a);
int					lst_size(t_push **a);
void				lst_add_back(t_push **a, t_push *new_node);
int					minnum(t_push **a);
int					maxnum(t_push **a);
int					maxindex(t_push **a);
int					min_pos(t_push **a, int med, int i);
int					max_pos(t_push **a, int med, int i);

#endif
