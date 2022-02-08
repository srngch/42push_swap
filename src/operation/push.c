/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:56:49 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 02:40:08 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_push(t_stack *stack_from, t_stack *stack_to)
{
	int	content;

	if (!stack_from->top)
		return (FT_FALSE);
	content = stack_pop(stack_from);
	content = 1;
	stack_push(stack_to, content);
	return (FT_TRUE);
}

int	pa(t_ps *ps)
{
	if (ps_push(ps->b, ps->a))
	{
		ft_putstr_fd("pa\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

int	pb(t_ps *ps)
{
	if (ps_push(ps->a, ps->b))
	{
		ft_putstr_fd("pb\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}
