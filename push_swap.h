/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* push_swap.h                                        :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/09/04 19:27:35 by vinpache          #+#    #+#             */
/* Updated: 2025/09/05 16:27:00 by vinpache         ###   ########.fr       */
/* */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push
{
	int				number;
	int				index;
	struct s_push	*next;
}					t_push;

/* --- Funções de Parsing e Validação --- */
int					parse_number(const char *str);
void				check_rep(t_push **a);

/* --- Operações --- */
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

/* --- Algoritmo de Sort --- */
void				sort(t_push **a, t_push **b, int count);
void				sort_2(t_push **a);
void				sort_3(t_push **a);
void				sort_5(t_push **a, t_push **b, int size);
void				sort_big(t_push **a, t_push **b, int chunk_size);
void				sort_pa(t_push **a, t_push **b);

/* --- Funções Utilitárias --- */
void				exit_error(void);
void				set_index(t_push **a, int size);
int					is_sorted(t_push **a);
int					lst_size(t_push **a);
void				lst_add_back(t_push **a, t_push *new_node);
int					minnum(t_push **a);
int					maxnum(t_push **a);
int					maxindex(t_push **a);
int					min_pos(t_push **a, int med, int i);
int					max_pos(t_push **a, int med, int i);

#endif

