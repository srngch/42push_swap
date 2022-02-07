/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/08 02:03:28 by sarchoi          ###   ########seoul.kr  */
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

//
void	ps_sort_approximately(t_ps *ps)
{
	int		a_size;
	int		p0;
	int		p1;
	int		p2;

	a_size = ps->a->size;
	// printf("a_size1: %d\n", a_size);
	p0 = get_nth_value(ps->a, ps->a->size * 0.25);
	p1 = get_nth_value(ps->a, ps->a->size * 0.5);
	p2 = get_nth_value(ps->a, ps->a->size * 0.75);
	// printf("p0: %d, p1: %d, p2: %d\n", p0, p1, p2);
	while (a_size-- > 0)
	{
		if (*(int *)stack_top(ps->a)->content < p1)
			ra(ps);
		else
		{
			pb(ps);
			if (p2 < *(int *)stack_top(ps->b)->content)
				rb(ps);
		}
	}
	a_size = ps->a->size;
	// printf("a_size2: %d\n", a_size);
	// while (a_size-- > 0)
	// {
	// 	// printf("[%d] %d]\n", a_size, *(int *)stack_top(ps->a)->content);
	// 	if (p0 < *(int *)stack_top(ps->a)->content)
	// 		pb(ps);
	// 	else
	// 		ra(ps);
	// }
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
	// print_stack(ps.a);
	// printf("%dth value: %d\n", ps.a->size / 2, get_nth_value(ps.a, ps.a->size / 2));
	// printf("first under 3: %d\n", count_meet_first_under(ps.a, 5));
	// printf("last under 3: %d\n", count_meet_last_under(ps.a, 5));

	ps.b = init_stack();
	ps_sort_approximately(&ps);
	ps_sort(&ps);
	// print_stack(ps.a);
	// TODO: sort the stacks
	// TODO: print the result
	// TODO: free the stacks
	return (EXIT_SUCCESS);
}
