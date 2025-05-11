/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:10:57 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 01:30:32 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <error.h>
#include <limits.h>

static int	is_not_numeric(char *c)
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

static t_list	*get_lines(char	*filename)
{
	t_list	*list;
	int		fd;
	char	*buf;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (!fd)
		error(1, 0, "Invalid filename");
	buf = get_next_line(fd);
	while (buf)
	{
		if (buf[ft_strlen(buf) - 1] == '\n') 
			buf[ft_strlen(buf) - 1] = 0;
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

static void	get_points(t_points *point, char *val,
	unsigned int pointcoords[2], t_fdf *fdf)
{
	point->fdf_coords[0] = pointcoords[0];
	point->fdf_coords[1] = pointcoords[1];
	if (is_not_numeric(val))
		error(1, 0, "Non-Numeric-Input");
	if (is_overflow(val))
		error(1, 0, "Integer overflow in input");
	point->fdf_coords[2] = ft_atoi(val);
	if (point->fdf_coords[2] < (fdf->extremes)[0])
		(fdf->extremes)[0] = point->fdf_coords[2];
	if (point->fdf_coords[2] > (fdf->extremes)[1])
		(fdf->extremes)[1] = point->fdf_coords[2];
	if (pointcoords[0] < (fdf->dims)[0])
		point->right = point + 1;
	else
		point->right = NULL;
	if (pointcoords[1] < (fdf->dims)[1])
		point->lower = point + (fdf->dims[0] * pointcoords[1])
			+ pointcoords[0];
	else
		point->lower = 0;
	point->calculated = 0;
}

static void	parse_core(t_points *points, t_fdf *fdf, t_list *lines)
{
	char			**cur_line;
	unsigned int	pos[3];

	pos[1] = 0;
	while (lines)
	{
		pos[0] = 0;
		cur_line = ft_split(lines->content, ' ');
		while (cur_line && cur_line[pos[0]])
			pos[0]++;
		if (!(pos[0] == (fdf->dims)[0]))
			error(1, 0, "Inconsitent grid size");
		pos[0] = 0;
		while (pos[0] < (fdf->dims)[0])
		{
			get_points((points + (pos[1] * (fdf->dims)[0]) + pos[0]),
				cur_line[pos[0]], pos, fdf);
			free((cur_line[pos[0]]));
			pos[0]++;
		}
		free (cur_line);
		pos[1]++;
		lines = lines->next;
	}
}

static t_fdf	*init_values(t_list *lines)
{
	char	**cur_line;
	t_fdf	*self;

	self = malloc(sizeof(t_fdf));
	if (!self)
		error(1, 0, "Malloc Error");
	(self->dims)[1] = ft_lstsize(lines);
	(self->dims)[0] = 0;
	(self->extremes)[0] = INT_MAX;
	(self->extremes)[1] = INT_MIN;
	cur_line = ft_split(lines->content, ' ');
	while (cur_line && cur_line[(self->dims)[0]])
	{
		free((cur_line[(self->dims)[0]]));
		(self->dims)[0]++;
	}
	free(cur_line);
	return (self);
}

t_fdf
