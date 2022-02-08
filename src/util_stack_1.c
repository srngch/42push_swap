/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:26 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 02:34:10 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_bottom(t_stack *stack)
{
	t_list	*bottom;

	if (stack->size == 0)
		return (NULL);
	bottom = stack->top;
	while (bottom->next)
		bottom = bottom->next;
	return (bottom);
}

int	stack_pop(t_stack *stack)
{
	t_list	*item;
	int		data;

	if (!stack->top)
		return (0);
	item = stack->top;
	data = item_value(item);
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->size = 0;
		free(item->content);
		free(item);
		return (data);
	}
	stack->top = item->next;
	free(item->content);
	free(item);
	stack->size--;
	return (data);
}

int	stack_push(t_stack *stack, int data)
{
	t_list	*item;
	int		*new_content;

	item = (t_list *)malloc(sizeof(t_list));
	if (!item)
		return (FT_FALSE);
	new_content = (int *)malloc(sizeof(int));
	if (!new_content)
		return (0);
	*new_content = data;
	item->content = new_content;
	if (stack->size == 0)
	{
		item->next = NULL;
		stack->top = item;
		stack->size++;
		return (FT_TRUE);
	}
	item->next = stack->top;
	stack->top = item;
	stack->size++;
	return (FT_TRUE);
}
