/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:42 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/15 17:13:34 by sarchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv)
{
	// TODO: check if argv is valid
	// TODO: make a stack for each argument
	// TODO: sort the stacks
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		// TODO: error or not ?
		return (EXIT_SUCCESS);
	}
	push_swap(argc, argv);
	return (EXIT_SUCCESS);
}
