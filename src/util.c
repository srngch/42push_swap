/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:21 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/08 03:07:46 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: should free memory before call this function
void	ft_exit_with_error_msg(void)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_list	*find_min_item(t_stack *stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = stack->top;
	min = tmp;
	while (tmp)
	{
		if (*(int *)tmp->content < *(int *)min->content)
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
		if (*(int *)tmp->content > *(int *)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

static int	find_min_value_with_limit(t_stack *stack, int upper)
{
	t_list	*tmp;
	int			min;

	tmp = stack->top;
	min = *(int *)find_max_item(stack)->content;
	while (tmp)
	{
		if (*(int *)tmp->content > upper)
		{
			if (*(int *)tmp->content < min)
				min = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	get_nth_value(t_stack *stack, int n)
{
	int	i;
	int	result;

	result = *(int *)find_min_item(stack)->content;
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
		if (*(int *)tmp->content < under)
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
		if (*(int *)tmp->content < under)
		{
			value = *(int *)tmp->content;
			count = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}

int	has_under(t_stack *stack, int under)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (*(int *)tmp->content < under)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
