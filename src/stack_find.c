/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:21 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 02:11:43 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min_item(t_stack *stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = stack->top;
	min = tmp;
	while (tmp)
	{
		if (item_value(tmp) < item_value(min))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_item(t_stack *stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = stack->top;
	max = tmp;
	while (tmp)
	{
		if (item_value(tmp) > item_value(max))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min_value_with_limit(t_stack *stack, int upper)
{
	t_list	*tmp;
	int		min;

	tmp = stack->top;
	min = item_value(find_max_item(stack));
	while (tmp)
	{
		if (item_value(tmp) > upper)
		{
			if (item_value(tmp) < min)
				min = item_value(tmp);
		}
		tmp = tmp->next;
	}
	return (min);
}

int	item_value(t_list *item)
{
	return (*(int *)item->content);
}
