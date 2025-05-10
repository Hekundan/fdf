/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:10:57 by johartma          #+#    #+#             */
/*   Updated: 2025/05/10 23:07:43 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../fdf.h"
#include <stdlib.h>
#include <fcntl.h>

t_list	*get_lines(char	*filename)
{
	t_list	*list;
	int		fd;Makefile
	char	*buf;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (NULL);
	buf = get_next_line(fd);
	while (buf)
	{
		ft_lstadd_back(&list, ft_lstnew(buf));
		if (!ft_lstlast(list))
		{
			ft_lstclear(&list, free);
			break ;
		}
		buf = get_next_line(fd);
	}
	close(fd);
	return (list);
}

t_points	*get_points(char *val, int x, int y)
{
	
}

t_fdf	*
