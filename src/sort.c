/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/06 17:38:27 by sarchoi          ###   ########seoul.kr  */
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
	t_list	*b_max;

	count = 0;
	b_size = ps->b->size;
	tmp = ps->b->top;
	// printf("tmp: %d\n", *(int *)ps->b->top->content);
	b_max = find_max_item(ps->b);
	// printf("max: %d\n", *(int *)b_max->content);
	if (b_size > 1)
	{
		if (*(int *)b_max->content > *(int *)ps->a->top->content)
		{
			if (
				((*(int *)stack_bottom(ps->b)->content) >
					(*(int *)ps->a->top->content))
				&& ((*(int *)stack_top(ps->b)->content) <
					(*(int *)ps->a->top->content))
			)
			{
				// printf("case1\n");
			}
			else
			{
				// printf("case2\n");
				while (tmp)
				{
					// printf("%d < %d == %d | ", *(int *)tmp->content, *(int *)ps->a->top->content, *(int *)tmp->content < *(int *)ps->a->top->content);
					count++;
					if ((*(int *)tmp->content > *(int *)ps->a->top->content && (tmp->next && *(int *)tmp->next->content <  *(int *)ps->a->top->content)))
					{
						// printf("\nbreak 1\n");
						break;
					}
					if (*(int *)tmp->content > *(int *)ps->a->top->content && tmp->next == b_max)
					{
						// printf("\nbreak 2\n");
						break;
					}
					tmp = tmp->next;
				}
				// printf("\n");
				if (count <= b_size / 2)
				{
					// printf("1. count: %d\n", count);
					// count++;
					while (count-- > 0)
					{
						// printf("do rb\n");
						rb(ps);
					}
				}
				else
				{
					// printf("2. count: %d\n", count);
					count = b_size - count;
					while (count-- > 0)
					{
						rrb(ps);
					}
				}
			}
		}
		else
		{
			if (*(int *)b_max->content == *(int *)ps->a->top->content)
			{
				// printf("3\n");
			}
			else
			{
				while (tmp && tmp != b_max)
				{
					count++;
					tmp = tmp->next;
				}
				if (count + 1 <= b_size / 2)
				{
					// printf("3. count: %d\n", count);
					while (count-- > 0)
					{
						rb(ps);
					}
				}
				else
				{
					count = b_size - count;
					// printf("4. count: %d\n", count);
					while (count-- > 0)
					{
						rrb(ps);
					}
				}
			}
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
