/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:20:47 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/19 21:30:38 by sarchoi          ###   ########seoul.kr  */
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
int	stack_pop(t_stack *stack);
int	stack_push(t_stack *stack, int data);
int	stack_is_empty(t_stack *stack);
t_stack	*make_stack(t_stack *stack, int size, int **data);
t_stack	*init_stack(void);

// TEST
# include <stdio.h>
int	print_stack(t_stack *stack);

#endif
