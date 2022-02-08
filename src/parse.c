/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:22:19 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 00:32:39 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	get_split_length(char **nums)
{
	unsigned int	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

static void	free_split(char **nums)
{
	unsigned int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	parse_arguments(t_stack	**stack, int argv_length, char **argv)
{
	char	**split;

	while (argv_length)
	{
		if (ft_strchr(argv[argv_length - 1], ' '))
		{
			split = ft_split(argv[argv_length - 1], ' ');
			if (!parse_arguments(stack, get_split_length(split), split))
			{
				free_split(split);
				return (FT_FALSE);
			}
			free_split(split);
		}
		else
		{
			if (!check_integer(argv[argv_length - 1])
				|| !check_range(argv[argv_length - 1])
				|| !stack_push(*stack, ft_atoi(argv[argv_length - 1])))
				return (FT_FALSE);
		}
		argv_length--;
	}
	return (FT_TRUE);
}
