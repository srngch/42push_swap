/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:20:47 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/07 21:23:21 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "get_next_line.h"

# include "ps_macro.h"
# include "ps_type.h"

t_list	*stack_top(t_stack *stack);
t_list	*stack_bottom(t_stack *stack);
int		stack_pop(t_stack *stack);
int		stack_push(t_stack *stack, int data);
int		stack_is_empty(t_stack *stack);
t_stack	*make_stack(t_stack *stack, int size, int **data);
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

int		check_integer(char *str);
int		check_range(char *str);
int		check_duplicates(t_stack *stack);

int		parse_arguments(t_stack	**stack, int argv_length, char **argv);

long	ft_atol(const char *str);

int		sa(t_ps *ps);
int		sb(t_ps *ps);
int		ss(t_ps *ps);
int		pa(t_ps *ps);
int		pb(t_ps *ps);
int		ra(t_ps *ps);
int		rb(t_ps *ps);
int		rr(t_ps *ps);
int		rra(t_ps *ps);
int		rrb(t_ps *ps);
int		rrr(t_ps *ps);

t_list	*find_min_item(t_stack *stack);
t_list	*find_max_item(t_stack *stack);
int			get_nth_value(t_stack *stack, int n);

int	count_meet_first_under(t_stack *stack, int under);
int	count_meet_last_under(t_stack *stack, int under);

int		ps_sort_2 (t_ps *ps);
int		ps_sort_3 (t_ps *ps);
int		ps_sort_4 (t_ps *ps);
int		ps_sort_many (t_ps *ps);

// TEST
# include <stdio.h>
int		print_stack(t_stack *stack);

#endif
