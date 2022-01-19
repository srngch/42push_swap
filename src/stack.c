/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:26 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/19 21:30:21 by sarchoi          ###   ########seoul.kr  */
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
	data = *(int *)(item->content);
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
	int		*new_content;

	item = (t_list *)malloc(sizeof(t_list));
	if (!item)
		return (FT_FALSE);
	new_content = (int *)malloc(sizeof(int));
	if (!new_content)
		return (0);
	*new_content = data;
	item->content = new_content;
	if (!stack->top)
	{
		stack->top = item;
		stack->size++;
		return (FT_TRUE);
	}
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
// t_stack	*make_stack(t_stack *stack, int size, int **data)
// {
// 	t_stack	*new_stack;
// 	int		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (!stack_push(stack, *data[i]))
// 		{
// 			// TODO: free stack
// 			// free_stack(stack);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (new_stack);
// }

// init the stack
// return: the stack, NULL if fail
t_stack	*init_stack(void)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	print_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		printf("%d ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	return (FT_TRUE);
}