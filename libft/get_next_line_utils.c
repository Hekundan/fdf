/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:45:39 by johartma          #+#    #+#             */
/*   Updated: 2025/04/16 12:12:26 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

char	*cleanup(char **buffer, char **to_return)
{
	free (*buffer);
	free (*to_return);
	*buffer = NULL;
	*to_return = NULL;
	return (NULL);
}

void	ft_copy(const char *src, char *dest, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[start + i] = src[i];
		i++;
	}
}

ssize_t	read_to_buf(int fd, char **buffer)
{
	ssize_t	read_result;

	read_result = read(fd, *buffer, BUFFER_SIZE);
	if (read_result < 0)
		return (-1);
	(*buffer)[read_result] = '\0';
	return (read_result);
}

size_t	get_len(char *c)
{
	size_t	len;

	len = 0;
	if (*c)
	{
		while (c[len])
			len++;
	}
	return (len);
}

size_t	get_buf_len(char *c)
{
	size_t	len;

	len = 0;
	if (c)
	{
		if (c[len])
		{
			while (c[len] && (c[len] != '\n'))
				len++;
		}
		if (c[len] == '\n')
		{
			len++;
			return (len);
		}
	}
	return (len);
}
