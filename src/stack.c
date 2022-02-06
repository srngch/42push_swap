/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:22:26 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/05 21:53:14 by sarchoi          ###   ########seoul.kr  */
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
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->size = 0;
		free(item);
		return (data);
	}
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

// check if the stack is empty
// return: 1(TRUE) if stack is empty, 0(FALSE) if not
int	stack_is_empty(t_stack *stack)
{
	if (!stack->top)
		return (FT_TRUE);
	return (FT_FALSE);
}

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

void	free_stack(t_stack *stack)
{
	t_list	*item;
	t_list	*next;

	item = stack->top;
	while (item)
	{
		next = item->next;
		free(item->content);
		free(item);
		item = next;
	}
	free(stack);
}

int	print_stack(t_stack *stack)
{
	t_list	*tmp;

	printf("p: ");
	tmp = stack->top;
	while (tmp)
	{
		printf("%d ", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	printf("\n");
	return (FT_TRUE);
}
