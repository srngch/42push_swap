/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 01:54:27 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_2(t_ps *ps)
{
	t_list	*a_top;

	a_top = ps->a->top;
	if (item_value(a_top) > item_value(a_top->next))
		return (ra(ps));
	return (FT_TRUE);
}

int	ps_sort_3(t_ps *ps)
{
	t_list	*min_item;
	t_list	*max_item;

	min_item = find_min_item(ps->a);
	max_item = find_max_item(ps->a);
	if (ps->a->top == min_item && stack_bottom(ps->a) == max_item)
		return (FT_TRUE);
	if (ps->a->top == min_item && stack_bottom(ps->a) != max_item)
		return (sa(ps) && ra(ps));
	if (ps->a->top == max_item && stack_bottom(ps->a) == min_item)
		return (sa(ps) && rra(ps));
	if (ps->a->top == max_item && stack_bottom(ps->a) != min_item)
		return (ra(ps));
	if (ps->a->top != min_item && stack_bottom(ps->a) == max_item)
		return (sa(ps));
	if (ps->a->top != max_item && stack_bottom(ps->a) == min_item)
		return (rra(ps));
	return (FT_FALSE);
}

int	ps_sort_4(t_ps *ps)
{
	t_list	*min;
	t_list	*tmp;
	int		count;

	min = find_min_item(ps->a);
	tmp = ps->a->top;
	count = 0;
	while (tmp != min)
	{
		tmp = tmp->next;
		count++;
	}
	rotate_stack_a(ps, count);
	pb(ps);
	ps_sort_3(ps);
	pa(ps);
	return (FT_TRUE);
}

int	ps_sort_5(t_ps *ps)
{
	int			i;
	t_list		*min;
	t_list		*tmp;
	int			count;

	i = 2;
	while (i--)
	{
		min = find_min_item(ps->a);
		tmp = ps->a->top;
		count = 0;
		while (tmp != min)
		{
			tmp = tmp->next;
			count++;
		}
		rotate_stack_a(ps, count);
		pb(ps);
	}
	ps_sort_3(ps);
	pa(ps);
	pa(ps);
	return (FT_TRUE);
}
