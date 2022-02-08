/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:43:17 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 00:58:42 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_ps *ps, int count)
{
	int	stack_size;

	stack_size = ps->a->size;
	if (count <= stack_size / 2)
	{
		while (count--)
			ra(ps);
	}
	else
	{
		stack_size = stack_size - count;
		while (stack_size--)
			rra(ps);
	}
}

void	rotate_stack_b(t_ps *ps, int count)
{
	int	stack_size;

	stack_size = ps->b->size;
	if (count <= stack_size / 2)
	{
		while (count--)
			rb(ps);
	}
	else
	{
		stack_size = stack_size - count;
		while (stack_size--)
			rrb(ps);
	}
}
