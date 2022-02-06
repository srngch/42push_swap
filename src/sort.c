/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/07 01:17:14 by sarchoi          ###   ########seoul.kr  */
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
	// printf("min: %d, max: %d\n", *(int *)min_item->content, *(int *)max_item->content);
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

void	rotate_stack_b(t_ps *ps, int count)
{
	int	b_size;

	b_size = ps->b->size;
	if (count <= b_size / 2)
	{
		while (count--)
			rb(ps);
	}
	else
	{
		b_size = b_size - count;
		while (b_size--)
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
	int		b_size;
	t_list	*tmp;
	t_list	*b_max;

	count = 0;
	b_size = ps->b->size;
	tmp = stack_top(ps->b);
	b_max = find_max_item(ps->b);

	if (b_size > 1)
	{
		if (get_value(stack_top(ps->a)) < get_value(b_max)) // 가장 큰 값이 b에 있음
		{
			while (tmp)
			{
				if (
					get_value(stack_top(ps->b)) < get_value(stack_top(ps->a)) && \
					get_value(stack_top(ps->a)) < get_value(stack_bottom(ps->b))
				)
					break;
				count++;
				if (
					// b.tmp.next < a.top < b.tmp
					get_value(stack_top(ps->a)) < get_value(tmp) && \
					tmp->next && get_value(tmp->next) < get_value(stack_top(ps->a))
				)
					break;
				if (
					// a.top < b.tmp && b.tmp.next == b.max
					get_value(stack_top(ps->a)) < get_value(tmp) &&
					tmp->next == b_max
				)
					break;
				tmp = tmp->next;
			}
			rotate_stack_b(ps, count);
		}
		else
		{
			while (tmp)
			{
				count++;
				if (tmp->next == b_max)
					break;
				tmp = tmp->next;
			}
			rotate_stack_b(ps, count);
		}
	}
	pb(ps);
}

int	ps_sort_many (t_ps *ps)
{
	int	a_size;
	int	b_size;
	int	a_stack_max_value;

	a_stack_max_value = *(int *)(find_max_item(ps->a)->content);
	pb(ps);
	a_size = ps->a->size;
	// printf(".stack_a: ");
	// print_stack(ps->a);
	// printf(".stack_b: ");
	// print_stack(ps->b);
	// printf("a_stack_max_value: %d\n", a_stack_max_value);
	while (a_size--)
	{
		// printf("------\n");
		// printf("b_top: %d\n", *(int *)ps->b->top->content);
		while (((*(int *)ps->b->top->content - (a_size / 15) < *(int *)ps->a->top->content) && \
		(*(int *)ps->a->top->content) < *(int *)ps->b->top->content + (a_size / 15)))
		{
			// printf("a_top: %d\n", *(int *)ps->a->top->content);
			ra(ps);
		}
		a_to_b(ps);
		// printf("stack_a: ");
		// print_stack(ps->a);
		// printf("stack_b: ");
		// print_stack(ps->b);
	}
	while (*(int *)ps->b->top->content != a_stack_max_value)
	{
		rrb(ps);
	}
	b_size = ps->b->size;
	// printf("a_to_b done\n");
	while (b_size--)
	{
		pa(ps);
	}
	return (FT_TRUE);
}
