/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/19 21:24:11 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *parse_arguments(int argc, char **argv)
{
	t_stack *stack;
	char **  nums;
	int      i;

	stack = init_stack();
	while (argc > 1)
	{
		if (ft_strchr(argv[argc - 1], ' '))
		{
			nums = ft_split(argv[argc - 1], ' ');
			i = 0;
			while (nums[i + 1])
				i++;
			while (i > -1)
				stack_push(stack, ft_atoi(nums[i--]));
		}
		else
		{
			if (!stack_push(stack, ft_atoi(argv[argc - 1])))
				return (NULL);
		}
		argc--;
	}
	// TODO: free nums
	free(nums);
	return (stack);
}

int main(int argc, char **argv)
{
	t_ps ps;

	if (argc < 1)
		return (EXIT_SUCCESS);
	// TODO: parse argv
	ps.a = parse_arguments(argc, argv);
	print_stack(ps.a);
	// TODO: check if argv is valid
	// TODO: make a stack for each argument
	// TODO: sort the stacks
	// TODO: print the result
	// TODO: free the stacks
	return (EXIT_SUCCESS);
}
