/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:21:04 by johartma          #+#    #+#             */
/*   Updated: 2025/04/07 12:53:10 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf_s(const char *s)
{
	int	count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			ft_putchar(s[count]);
			count++;
		}
		return (count);
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}

int	ft_printf_per(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_printf_xx(const unsigned int x)
{
	int	count[1];

	*count = 0;
	ft_putnbr_flex_x((size_t) x, count, 16);
	return (*count);
}
