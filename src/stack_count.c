/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:54:50 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 01:48:14 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nth_value(t_stack *stack, int n)
{
	int	i;
	int	result;

	result = item_value(find_min_item(stack));
	i = 0;
	while (++i <= n)
		result = find_min_value_with_limit(stack, result);
	return (result);
}

int	count_meet_first_under(t_stack *stack, int under)
{
	t_list	*tmp;
	int			count;

	tmp = stack->top;
	count = 0;
	while (tmp)
	{
		if (item_value(tmp) < under)
			break ;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	count_meet_last_under(t_stack *stack, int under)
{
	t_list	*tmp;
	int		i;
	int		count;
	int		value;

	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (item_value(tmp) < under)
		{
			value = item_value(tmp);
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}
