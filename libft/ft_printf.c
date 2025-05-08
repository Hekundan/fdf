/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:55 by johartma          #+#    #+#             */
/*   Updated: 2025/04/07 12:52:30 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

static int	write_conversion(va_list args, const char *fmt)
{
	if (*fmt == 'i' || *fmt == 'd')
		return (ft_printf_i(va_arg(args, const int)));
	else if (*fmt == 'u')
		return (ft_printf_u(va_arg(args, const unsigned int)));
	else if (*fmt == 's')
		return (ft_printf_s(va_arg(args, const char *)));
	else if (*fmt == 'c')
		return (ft_printf_c(va_arg(args, const int)));
	else if (*fmt == 'p')
		return (ft_printf_p(va_arg(args, const void *)));
	else if (*fmt == 'x')
		return (ft_printf_x(va_arg(args, const unsigned int)));
	else if (*fmt == 'X')
		return (ft_printf_xx(va_arg(args, const unsigned int)));
	else if (*fmt == '%')
		return (ft_printf_per());
	else
		return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count_printed_char;

	va_start(args, fmt);
	count_printed_char = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			count_printed_char += write_conversion(args, fmt + 1);
			if (*(fmt + 1) == 0)
				break ;
			fmt += 2;
		}
		else
		{
			ft_putchar(*fmt);
			count_printed_char++;
			fmt++;
		}
	}
	va_end(args);
	return (count_printed_char);
}
