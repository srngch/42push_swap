/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:16:07 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 01:48:14 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (!ft_isdigit(str[i]))
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}

int	check_range(char *str)
{
	if (ps_atol(str) < PS_INT_MIN || ps_atol(str) > PS_INT_MAX)
		return (FT_FALSE);
	return (FT_TRUE);
}

int	check_duplicates(t_stack *stack)
{
	t_list	*item;
	t_list	*item_next;
	int		i;

	item = stack->top;
	while (item)
	{
		item_next = item->next;
		i = 0;
		while (item_next)
		{
			if (item_value(item) == item_value(item_next))
				return (FT_FALSE);
			item_next = item_next->next;
			i++;
		}
		item = item->next;
	}
	return (FT_TRUE);
}

int	check_stack_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (item_value(tmp) > item_value(tmp->next))
			return (FT_FALSE);
		tmp = tmp->next;
	}
	return (FT_TRUE);
}
