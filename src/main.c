/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 03:05:38 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_approximately(t_ps *ps)
{
	int		i;
	int		p1;
	int		p2;

	i = ps->a->size;
	p1 = get_nth_value(ps->a, ps->a->size / 5 * 2);
	p2 = get_nth_value(ps->a, ps->a->size / 4 * 3);
	while (i--)
	{
		if (item_value(ps->a->top) < p2)
		{
			pb(ps);
			if (item_value(ps->b->top) < p1)
				rb(ps);
		}
		else
			ra(ps);
	}
	i = ps->b->size;
	while (ps->b->size)
		pa(ps);
}

static int	ps_sort(t_ps *ps)
{
	if (ps->a->size == 1)
		return (FT_TRUE);
	if (ps->a->size == 2)
		return (ps_sort_2(ps));
	if (ps->a->size == 3)
		return (ps_sort_3(ps));
	if (ps->a->size == 4)
		return (ps_sort_4(ps));
	if (ps->a->size == 5)
		return (ps_sort_5(ps));
	else
	{
		sort_approximately(ps);
		return (ps_sort_many(ps));
	}
	return (FT_FALSE);
}

int	ps_parse(t_stack *stack, int argc, char **argv)
{
	if (!parse_arguments(&stack, argc - 1, argv + 1))
	{
		ft_putstr_fd("Error: parse\n", STDOUT_FILENO);
		free_stack(stack);
		return (FT_FALSE);
	}
	if (!check_duplicates(stack))
	{
		ft_putstr_fd("Error: duplicates\n", STDOUT_FILENO);
		free_stack(stack);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (EXIT_SUCCESS);
	ps.a = init_stack();
	if (!ps_parse(ps.a, argc, argv))
		return (EXIT_FAILURE);
	if (check_stack_sorted(ps.a))
	{
		free_stack(ps.a);
		return (EXIT_SUCCESS);
	}
	ps.b = init_stack();
	ps_sort(&ps);
	free_stack(ps.a);
	free_stack(ps.b);
	return (EXIT_SUCCESS);
}
