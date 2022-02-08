/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:46:50 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 03:09:35 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_ps *ps)
{
	int		count;
	t_list	*tmp;
	t_list	*b_max;

	count = 0;
	tmp = ps->b->top;
	b_max = find_max_item(ps->b);
	while (tmp)
	{
		if (item_value(ps->b->top) < item_value(ps->a->top) && \
		item_value(ps->a->top) < item_value(stack_bottom(ps->b)))
			break ;
		count++;
		if (item_value(ps->a->top) > item_value(b_max) && tmp->next == b_max)
			break ;
		if (item_value(ps->a->top) < item_value(tmp) && \
		tmp->next && item_value(tmp->next) < item_value(ps->a->top))
			break ;
		if (item_value(ps->a->top) < item_value(tmp) && tmp->next == b_max)
			break ;
		tmp = tmp->next;
	}
	rotate_stack_b(ps, count);
}

static void	set_stack_a(t_ps *ps, int a_size, int tmp)
{
	if (count_meet_first_under(ps->a, tmp) <= \
	a_size - count_meet_last_under(ps->a, tmp))
		rotate_stack_a(ps, count_meet_first_under(ps->a, tmp));
	else
		rotate_stack_a(ps, count_meet_last_under(ps->a, tmp));
}

int	ps_sort_many(t_ps *ps)
{
	int	a_size;
	int	list_min_value;
	int	i;
	int	tmp;

	list_min_value = item_value(find_min_item(ps->a));
	pb(ps);
	a_size = ps->a->size;
	i = PS_SORT_RANGE;
	while (a_size--)
	{
		tmp = get_nth_value(ps->a, i);
		if (tmp < item_value(ps->a->top))
			set_stack_a(ps, a_size, tmp);
		if (ps->b->size > 1)
			a_to_b(ps);
		pb(ps);
		if (i-- == 0)
			i = PS_SORT_RANGE;
	}
	while (ps->b->size)
		pa(ps);
	while (item_value(ps->a->top) != list_min_value)
		ra(ps);
	return (FT_TRUE);
}
