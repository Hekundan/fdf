/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:38:35 by johartma          #+#    #+#             */
/*   Updated: 2025/04/07 12:52:59 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

int	ft_printf_i(const int i)
{
	int	count[1];
	int	j;

	j = i;
	*count = 0;
	ft_putnbr_flex((ssize_t) j, count, 10);
	return (*count);
}

int	ft_printf_u(unsigned int u)
{
	int				count[1];
	unsigned int	j;

	j = u;
	*count = 0;
	ft_putnbr_flex((ssize_t) j, count, 10);
	return (*count);
}

int	ft_printf_c(const char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_printf_p(const void *p)
{
	int	count[1];

	*count = 0;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	*count += 2;
	ft_putnbr_p((uintptr_t) p, count, 16);
	return (*count);
}

int	ft_printf_x(const unsigned int x)
{
	int	count[1];

	*count = 0;
	ft_putnbr_flex((size_t) x, count, 16);
	return (*count);
}
