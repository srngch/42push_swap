/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:46:50 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 02:14:02 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO
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
		if (
			item_value(ps->b->top) < item_value(ps->a->top) && \
			item_value(ps->a->top) < item_value(stack_bottom(ps->b))
		)
			break ;
		count++;
		if (
			item_value(ps->a->top) > item_value(b_max) && \
			tmp->next == b_max
		)
			break ;
		if (
			// b.tmp.next < a.top < b.tmp
			item_value(ps->a->top) < item_value(tmp) && \
			tmp->next && item_value(tmp->next) < item_value(ps->a->top)
		)
			break ;
		if (
			// a.top < b.tmp && b.tmp.next == b.max
			item_value(ps->a->top) < item_value(tmp) && \
			tmp->next == b_max
		)
			break ;
		tmp = tmp->next;
	}
	rotate_stack_b(ps, count);
}

// TODO
int	ps_sort_many (t_ps *ps)
{
	int	a_size;
	int	b_size;
	int	list_min_value;
	int	list_max_value;
	int	i;
	int tmp;
	int	range = 13;

	list_min_value = item_value(find_min_item(ps->a));
	list_max_value = item_value(find_max_item(ps->a));
	pb(ps);
	a_size = ps->a->size;
	i = range;
	while (a_size--)
	{
		tmp = get_nth_value(ps->a, i);
		if (item_value(ps->a->top) > tmp)
		{
			if (count_meet_first_under(ps->a, tmp) <= a_size - count_meet_last_under(ps->a, tmp))
				rotate_stack_a(ps, count_meet_first_under(ps->a, tmp));
			else
				rotate_stack_a(ps, count_meet_last_under(ps->a, tmp));
		}
		if (ps->b->size > 1)
			a_to_b(ps);
		pb(ps);
		i--;
		if (i == 0)
			i = range;
	}
	b_size = ps->b->size;
	while (b_size--)
	{
		pa(ps);
	}
	while (item_value(ps->a->top) != list_min_value)
		ra(ps);
	return (FT_TRUE);
}
