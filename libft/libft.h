/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:28 by sarchoi           #+#    #+#             */
/*   Updated: 2022/02/09 15:38:46 by sarchoi          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);

char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# define	FT_SUCCESS 1
# define	FT_ERROR -1
# define	FT_EOF 0

# define	FT_TRUE 1
# define	FT_FALSE 0

#endif
