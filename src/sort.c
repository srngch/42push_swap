/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/04 02:24:35 by sarchoi          ###   ########seoul.kr  */
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

void	a_to_b(t_ps *ps)
{
	int		count;
	int		b_size;
	t_list	*tmp;
	t_list	*max_now;

	count = 0;
	b_size = ps->b->size;
	tmp = ps->b->top;
	printf("tmp1: %d\n", *(int *)ps->b->top->content);
	max_now = find_max_item(ps->b);
	printf("tmp2: %d\n", *(int *)ps->b->top->content);
	if (b_size > 1)
	{
		while (tmp && tmp > ps->a->top)
		{
			count++;
			tmp = tmp->next;
			if (tmp == max_now)
				break ;
		}
		if (count == 0)
			printf("0\n");
		else if (count <= b_size / 2)
		{
			while (count--)
				rb(ps);
		}
		else
		{
			while (b_size - count-- > 0)
			{
				rrb(ps);
			}
			rrb(ps);
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
	printf(".stack_a: ");
	print_stack(ps->a);
	printf(".stack_b: ");
	print_stack(ps->b);
	printf("a_stack_max_value: %d\n", a_stack_max_value);
	while (a_size--)
	{
		printf("------\n");
		a_to_b(ps);
		printf("stack_a: ");
		print_stack(ps->a);
		printf("stack_b: ");
		print_stack(ps->b);
	}
	b_size = ps->b->size;
	printf("a_to_b done\n");
	while (b_size--)
	{
		pa(ps);
	}
	return (FT_TRUE);
}
