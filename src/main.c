/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/08 03:06:46 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort(t_ps *ps)
{
	if (ps->a->size == 1)
		return (FT_TRUE);
	if (ps->a->size == 2)
		return (ps_sort_2(ps));
	if (ps->a->size == 3)
		return (ps_sort_3(ps));
	else
		return (ps_sort_many(ps));
	return (FT_FALSE);
}

void	ps_sort_approximately(t_ps *ps)
{
	int		i;
	int		p1;
	int		p2;

	i = ps->a->size;
	p1 = get_nth_value(ps->a, ps->a->size / 5 * 2);
	p2 = get_nth_value(ps->a, ps->a->size / 4 * 3);
	while (i-- > 0)
	{
		if (*(int *)stack_top(ps->a)->content < p2)
		{
			pb(ps);
			if (*(int *)stack_top(ps->b)->content < p1)
				rb(ps);
		}
		else
			ra(ps);
	}
	i = ps->b->size;
	while (ps->b->size > 0)
		pa(ps);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
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
	ps.b = init_stack();
	ps_sort_approximately(&ps);
	ps_sort(&ps);
	// print_stack(ps.a);
	// TODO: sort the stacks
	// TODO: print the result
	// TODO: free the stacks
	return (EXIT_SUCCESS);
}
