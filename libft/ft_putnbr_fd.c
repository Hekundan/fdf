/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:50:14 by johartma          #+#    #+#             */
/*   Updated: 2024/11/08 12:55:37 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	buffer;

	if (n < 0)
	{
		buffer = -n;
		ft_putchar_fd('-', fd);
	}
	else
		buffer = n;
	if ((buffer / 10) > 0)
		ft_putnbr_fd(buffer / 10, fd);
	ft_putchar_fd((buffer % 10) + '0', fd);
}
