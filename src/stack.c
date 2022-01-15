/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:26 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/15 17:13:03 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: use lst funtcions in libft

// get the top item of the stack
// return: the top item
t_list	*stack_top(t_stack *stack)
{
	if (stack->size == 0)
		return (NULL);
	return (stack->top);
}

// remove the top item of the stack
// return: data in removed item
int	stack_pop(t_stack *stack)
{
	t_list	*item;
	int		data;

	if (!stack->top)
		return (0);
	item = stack->top;
	data = *(item->content);
	stack->top = item->next;
	free(item);
	stack->size--;
	return (data);
}

// add item with received data to the top of the stack
// return: 1(TRUE) if success, 0(FALSE) if fail
int	stack_push(t_stack *stack, int data)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	if (!item)
		return (FT_FALSE);
	item->content = &data;
	item->next = stack->top;
	stack->top = item;
	stack->size++;
	return (FT_TRUE);
}

// check if the stack is empty
// return: 1(TRUE) if stack is empty, 0(FALSE) if not
int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

// make the stack
// return: the stack, NULL if fail
t_stack	*make_stack(t_stack *stack, int size, int **data)
{
	t_stack	*new_stack;
	int		i;

	i = 0;
	while (i < size)
	{
		if (!stack_push(stack, data[i]))
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (new_stack);
}