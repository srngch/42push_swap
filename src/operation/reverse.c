/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:20:00 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/02 21:39:28 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_reverse(t_stack *stack)
{
	t_list	*tmp_bottom;
	t_list	*before_tmp_bottom;

	if (!stack->top)
		return (FT_FALSE);
	if (stack->size == 0)
		return (FT_TRUE);
	tmp_bottom = stack->top;
	while (tmp_bottom->next)
	{
		before_tmp_bottom = tmp_bottom;
		tmp_bottom = tmp_bottom->next;
	}
	before_tmp_bottom->next = NULL;
	tmp_bottom->next = stack->top;
	stack->top = tmp_bottom;
	return (FT_TRUE);
}

int	rra(t_ps *ps)
{
	if (ps_reverse(ps->a))
	{
		ft_putstr_fd("rra\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

int	rrb(t_ps *ps)
{
	if (ps_reverse(ps->b))
	{
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

int	rrr(t_ps *ps)
{
	if (rra(ps) && rrb(ps))
	{
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}
