/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:40:12 by johartma          #+#    #+#             */
/*   Updated: 2024/11/19 20:06:44 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	newline;

	newline = '\n';
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, &newline, 1);
}
