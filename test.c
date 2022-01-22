#include <stdio.h>
#include <stdlib.h>


static int	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	r;
	int				sign;

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

long			ft_atol(const char *str)
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


int main() {
	char *s_max_over;
	char *s_max;
	char *s_min;
	char *s_min_under;

	s_max_over = "2147483648";
	s_max = "2147483647";
	s_min = "-2147483648";
	s_min_under = "-2147483649";

	printf("%s\n", s_max_over);
	printf("%d\n", atoi(s_max_over));
	printf("%d\n\n", ft_atoi(s_max_over));
	printf("%ld\n\n", ft_atol(s_max_over));

	printf("%s\n", s_max);
	printf("%d\n", atoi(s_max));
	printf("%d\n\n", ft_atoi(s_max));

	printf("%s\n", s_min);
	printf("%d\n", atoi(s_min));
	printf("%d\n\n", ft_atoi(s_min));

	printf("%s\n", s_min_under);
	printf("%d\n", atoi(s_min_under));
	printf("%d\n\n", ft_atoi(s_min_under));
	printf("%ld\n\n", ft_atol(s_min_under));

	printf("%s\n", "-46976204900");
	printf("%d\n", atoi("-46976204900"));
	printf("%d\n", ft_atoi("-46976204900"));
	printf("%ld\n\n", ft_atol("-46976204900"));

	printf("%s\n", "-46976205000");
	printf("%d\n", atoi("-46976205000"));
	printf("%d\n", ft_atoi("-46976205000"));
	printf("%ld\n\n", ft_atol("-46976205000"));
}
