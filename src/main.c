/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/02 21:33:42 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// WIP
int	ps_sort(t_ps *ps)
{
	if (ps->a->size == 1)
		return (FT_TRUE);
	if (ps->a->size == 2)
		return (ps_sort_2(ps));
	if (ps->a->size == 3)
		return (ps_sort_3(ps));
	else
		ft_putstr_fd("4 or more elements\n", 1);
	return (FT_FALSE);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 1)
		return (EXIT_SUCCESS);
	ps.a = init_stack();
	if (!parse_arguments(&ps.a, argc - 1, argv + 1))
	{
		printf("Error: parse\n");
		free_stack(ps.a);
		return (EXIT_FAILURE);
	}
	if (!check_duplicates(ps.a))
	{
		printf("Error: duplicates\n");
		free_stack(ps.a);
		return (EXIT_FAILURE);
	}
	// print_stack(ps.a);
	ps_sort(&ps);
	// print_stack(ps.a);
	// TODO: sort the stacks
	// TODO: print the result
	// TODO: free the stacks
	return (EXIT_SUCCESS);
}
