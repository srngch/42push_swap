/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:41:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/02 21:33:39 by sarchoi          ###   ########seoul.kr  */
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
	t_list	*tmp;
	t_list	*min_item;
	t_list	*max_item;

	tmp = ps->a->top;
	min_item = tmp;
	max_item = tmp;
	while (tmp)
	{
		if (*(int *)tmp->content < *(int *)min_item->content)
			min_item = tmp;
		if (*(int *)tmp->content > *(int *)max_item->content)
			max_item = tmp;
		tmp = tmp->next;
	}
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
