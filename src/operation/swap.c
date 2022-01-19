/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:52:16 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/19 16:44:12 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_swap(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size < 2)
		return (FT_FALSE);
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->next = tmp;
	return (FT_TRUE);
}

int	sa(t_ps *ps)
{
	if (ps_swap(ps->a))
		return (FT_TRUE);
	return (FT_FALSE);
}

int	sb(t_ps *ps)
{
	if (ps_swap(ps->b))
		return (FT_TRUE);
	return (FT_FALSE);
}

int	ss(t_ps *ps)
{
	if (sa(ps) && sb(ps))
		return (FT_TRUE);
	return (FT_FALSE);
}
