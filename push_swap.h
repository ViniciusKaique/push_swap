/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:39:56 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/08 13:39:58 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int					parse_number(const char *str);
void				check_rep(t_list **a);

void				sa(t_list **list_a);
void				sb(t_list **list_b);
void				ss(t_list **list_a, t_list **list_b);
void				pa(t_list **list_a, t_list **list_b);
void				pb(t_list **list_a, t_list **list_b);
void				ra(t_list **list_a);
void				rb(t_list **list_b);
void				rr(t_list **list_a, t_list **list_b);
void				rra(t_list **list_a);
void				rrb(t_list **list_b);
void				rrr(t_list **list_a, t_list **list_b);

void				sort(t_list **a, t_list **b, int count);
void				sort_2(t_list **a);
void				sort_3(t_list **a);
void				sort_5(t_list **a, t_list **b, int size);
void				sort_big(t_list **a, t_list **b, int chunk_size);
void				sort_pa(t_list **a, t_list **b);

void				exit_error(void);
void				set_index(t_list **a);
int					is_sorted(t_list **a);
int					minnum(t_list **a);
int					maxnum(t_list **a);
int					maxindex(t_list **a);
int					min_pos(t_list **a, int med, int i);
int					max_pos(t_list **a, int med, int i);

#endif