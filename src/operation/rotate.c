/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:10:36 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 02:10:52 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_rotate(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->top)
		return (FT_FALSE);
	if (stack->size == 1)
		return (FT_TRUE);
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack->top;
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = NULL;
	return (FT_TRUE);
}

int	ra(t_ps *ps)
{
	if (ps_rotate(ps->a))
	{
		ft_putstr_fd("ra\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

int	rb(t_ps *ps)
{
	if (ps_rotate(ps->b))
	{
		ft_putstr_fd("rb\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

int	rr(t_ps *ps)
{
	if (ra(ps) && rb(ps))
	{
		ft_putstr_fd("rr\n", STDOUT_FILENO);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}
