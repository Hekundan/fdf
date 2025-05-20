/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:13:30 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 16:14:04 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <limits.h>

int	is_whitespace(char c)
{
	if (((c >= 9) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

static	long long	ft_atoll(const char *str)
{
	long long	to_rtrn;
	int			sign;

	to_rtrn = 0;
	sign = 1;
	while (is_whitespace(*str) == 1)
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		to_rtrn *= 10;
		to_rtrn += (*str - '0');
		str++;
	}
	to_rtrn *= sign;
	return (to_rtrn);
}

int	is_overflow(char *s)
{
	long long	v;

	v = ft_atoll(s);
	if (v < INT_MIN || v > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	is_not_numeric(char *c)
{
	if (!c)
		return (-1);
	if (*c == '+' || *c == '-')
		c++;
	if (!*c)
		return (-1);
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (1);
		c++;
	}
	return (0);
}
