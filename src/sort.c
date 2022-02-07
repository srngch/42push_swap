/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/08 03:07:23 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_2 (t_ps *ps)
{
	t_list	*a_top;

	a_top = ps->a->top;
	if (a_top->content > a_top->next->content)
		return (ra(ps));
	return (FT_TRUE);
}

int	ps_sort_3 (t_ps *ps)
{
	t_list	*min_item;
	t_list	*max_item;

	min_item = find_min_item(ps->a);
	max_item = find_max_item(ps->a);
	if (stack_top(ps->a) == min_item && stack_bottom(ps->a) == max_item)
		return (FT_TRUE);
	if (stack_top(ps->a) == min_item && stack_bottom(ps->a) != max_item)
		return (sa(ps) && ra(ps));
	if (stack_top(ps->a) == max_item && stack_bottom(ps->a) == min_item)
		return (sa(ps) && rra(ps));
	if (stack_top(ps->a) == max_item && stack_bottom(ps->a) != min_item)
		return (ra(ps));
	if (stack_top(ps->a) != min_item && stack_bottom(ps->a) == max_item)
		return (sa(ps));
	if (stack_top(ps->a) != max_item && stack_bottom(ps->a) == min_item)
		return (rra(ps));
	return (FT_FALSE);
}

int	ps_sort_4 (t_ps *ps)
{
	t_list	*min;
	t_list	*max;

	min = find_min_item(ps->a);
	max = find_max_item(ps->a);
	if (stack_top(ps->a) == max)
		ra(ps);
	pb(ps);
	ps_sort_3(ps);
	while (*(int *)stack_top(ps->a) > *(int *)stack_top(ps->b))
		rra(ps);
	pa(ps);
	while (ps->a->top != min)
		rra(ps);
	return (FT_TRUE);
}

int	ps_sort_5(t_ps *ps)
{
	t_list	*min;
	t_list	*max;

	min = find_min_item(ps->a);
	max = find_max_item(ps->a);
	if (stack_top(ps->a) == max)
		ra(ps);
	pb(ps);
	ps_sort_3(ps);
	while (*(int *)stack_top(ps->a) > *(int *)stack_top(ps->b))
		rra(ps);
	pa(ps);
	while (ps->a->top != min)
		rra(ps);
	return (FT_TRUE);
}

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

static int	get_value(t_list *item)
{
	return (*(int *)item->content);
}

void	a_to_b(t_ps *ps)
{
	int		count;
	t_list	*tmp;
	t_list	*b_max;

	count = 0;
	tmp = stack_top(ps->b);
	b_max = find_max_item(ps->b);

	while (tmp)
	{
		if (
			get_value(stack_top(ps->b)) < get_value(stack_top(ps->a)) && \
			get_value(stack_top(ps->a)) < get_value(stack_bottom(ps->b))
		)
			break ;
		count++;
		if (
			get_value(stack_top(ps->a)) > get_value(b_max) && \
			tmp->next == b_max
		)
			break ;
		if (
			// b.tmp.next < a.top < b.tmp
			get_value(stack_top(ps->a)) < get_value(tmp) && \
			tmp->next && get_value(tmp->next) < get_value(stack_top(ps->a))
		)
			break ;
		if (
			// a.top < b.tmp && b.tmp.next == b.max
			get_value(stack_top(ps->a)) < get_value(tmp) &&
			tmp->next == b_max
		)
			break ;
		tmp = tmp->next;
	}
	rotate_stack_b(ps, count);
}

int	ps_sort_many (t_ps *ps)
{
	int	a_size;
	int	b_size;
	int	list_min_value;
	int	list_max_value;
	int	i;
	int tmp;
	int	range = 13;

	list_min_value = get_value(find_min_item(ps->a));
	list_max_value = get_value(find_max_item(ps->a));
	pb(ps);
	a_size = ps->a->size;
	i = range;
	while (a_size--)
	{
		tmp = get_nth_value(ps->a, i);
		if (get_value(ps->a->top) > tmp)
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
	while (get_value(ps->a->top) != list_min_value)
		ra(ps);
	return (FT_TRUE);
}
