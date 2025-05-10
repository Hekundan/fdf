/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:07:16 by johartma          #+#    #+#             */
/*   Updated: 2025/01/27 17:26:12 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_flex(ssize_t nb, int *count, int base_length)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		(*count)++; 
	}
	if ((nb / base_length) > 0)
		ft_putnbr_flex(nb / base_length, count, base_length);
	if ((nb % base_length) < 10)
		ft_putchar((nb % base_length) + '0');
	else
		ft_putchar((nb % base_length) - 10 + 'a');
	(*count)++;
}

void	ft_putnbr_p(uintptr_t nb, int *count, int base_length)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		(*count)++; 
	}
	if ((nb / base_length) > 0)
		ft_putnbr_flex(nb / base_length, count, base_length);
	if ((nb % base_length) < 10)
		ft_putchar((nb % base_length) + '0');
	else
		ft_putchar((nb % base_length) - 10 + 'a');
	(*count)++;
}

void	ft_putnbr_flex_x(unsigned int nb, int *count, int base_length)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		(*count)++; 
	}
	if ((nb / base_length) > 0)
		ft_putnbr_flex_x(nb / base_length, count, base_length);
	if ((nb % base_length) < 10)
		ft_putchar((nb % base_length) + '0');
	else
		ft_putchar((nb % base_length) - 10 + 'A');
	(*count)++;
}
