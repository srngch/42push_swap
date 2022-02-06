/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:21 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/06 23:07:00 by sarchoi          ###   ########seoul.kr  */
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

int	find_median_value(t_stack *stack)
{
	t_list	*tmp;
	t_list	*median;
	int		min_value;
	int		max_value;
	int		diff_to_min;
	int		diff_to_max;

	min_value = *(int *)find_min_item(stack)->content;
	max_value = *(int *)find_max_item(stack)->content;
	tmp = stack->top;
	median = tmp;
	diff_to_min = *(int *)median->content - min_value;
	diff_to_max = max_value - *(int *)median->content;
	printf("min_value: %d, max_value: %d\n", min_value, max_value);
	printf("diff_to_min: %d, diff_to_max: %d\n", diff_to_min, diff_to_max);
	while (tmp)
	{
		printf("[%d] diff_to_min: %d, diff_to_max: %d\n", *(int *)tmp->content, *(int *)tmp->content - min_value, max_value - *(int *)tmp->content);
		if ((diff_to_min < *(int *)tmp->content - min_value) && \
			(diff_to_max < max_value - *(int *)tmp->content))
		{
			median = tmp;
			diff_to_min = *(int *)median->content - min_value;
			diff_to_max = max_value - *(int *)median->content;
			printf("!\n");
		}
		tmp = tmp->next;
	}
	return (*(int *)median->content);
}
