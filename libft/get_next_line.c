/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:14:49 by johartma          #+#    #+#             */
/*   Updated: 2025/04/16 12:12:36 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

static int	buf_to_res(char **buffer, char **to_return)
{
	char	*new;
	size_t	return_len;
	size_t	buffer_len;
	size_t	tot_buffer_len;

	return_len = get_len(*to_return);
	buffer_len = get_buf_len(*buffer);
	tot_buffer_len = get_len(*buffer);
	if (!return_len && !buffer_len)
		return (-1);
	new = malloc(return_len + buffer_len + 1);
	if (!new)
		return (-1);
	ft_copy(*to_return, new, 0, return_len);
	ft_copy(*buffer, new, return_len, buffer_len);
	new[return_len + buffer_len] = '\0';
	free(*to_return);
	*to_return = new;
	ft_copy(*(buffer) + buffer_len, *buffer, 0, 1
		+ tot_buffer_len - buffer_len);
	if ((buffer_len > 0 && buffer_len < tot_buffer_len)
		|| ((*to_return)[return_len + buffer_len - 1] == '\n'))
		return (1);
	return (0);
}

static int	gnl_routine(int fd, char **buffer, char **to_return)
{
	ssize_t	read_result;
	ssize_t	buf_to_res_result;

	buf_to_res_result = 0;
	while (1)
	{
		if (!*buffer || !**buffer)
		{
			free(*buffer);
			*buffer = malloc(BUFFER_SIZE + 1);
			if (!*buffer)
				return (-1);
			read_result = read_to_buf(fd, buffer);
			if (read_result == -1)
				return (-1);
			(*buffer)[read_result] = '\0';
			if (read_result == 0)
				return (0); 
		}
		buf_to_res_result = buf_to_res(buffer, to_return);
		if (buf_to_res_result == 1)
			return (1);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1];
	char		*to_return[1];
	int			status;

	if (!*buffer)
	{
		*buffer = malloc(1);
		if (!*buffer)
			return (NULL);
		**buffer = '\0';
	}
	*to_return = malloc(1);
	if (!*to_return)
	{
		free(*buffer);
		return (NULL);
	}
	(*to_return)[0] = '\0';
	status = gnl_routine(fd, buffer, to_return);
	if (status == -1)
		return (cleanup(buffer, to_return));
	if (status == 0 && !(**to_return))
		return (cleanup(buffer, to_return));
	return (*to_return);
}
