/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:18:08 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/23 01:36:46 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (r * sign);
}
