/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:41:28 by sarchoi           #+#    #+#             */
/*   Updated: 2022/01/19 15:53:23 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_TYPE_H
# define PS_TYPE_H

# include "libft.h"

// TODO: remove this
// typedef struct s_list
// {
// 	void			*content;  // data
// 	struct s_list	*next;     // pointer to next Node
// }	t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}				t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	int		size;
}				t_ps;

#endif
