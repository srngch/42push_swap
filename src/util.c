/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:21 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/04 01:47:57 by sarchoi          ###   ########seoul.kr  */
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
