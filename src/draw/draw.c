/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:56:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 16:18:48 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../fdf.h"
#include <error.h>
#include <stdlib.h>

static t_data	*init_image(void *mlx)
{
	t_data	*img;

	img = malloc(sizeof(*img));
	if (!img)
		error(1, 0, "Malloc Fail");
	img->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

static void	draw_lines(t_data *img, t_fdf *fdf, t_points *point)
{
	t_vec	a;
	t_vec	b;

	if (point->lower)
	{
		a = (t_vec){(point->projected)[0],
			(point->projected[1]),
			(point->projected[2])};
		b = (t_vec){(point->lower->projected)[0],
			(point->lower->projected[1]),
			(point->lower->projected[2])};
		draw_lines_core(a, b, fdf, img);
	}
	if (point->right)
	{
		a = (t_vec){(point->projected)[0],
			(point->projected[1]),
			(point->projected[2])};
		b = (t_vec){(point->right->projected)[0],
			(point->right->projected[1]),
			(point->right->projected[2])};
		draw_lines_core(a, b, fdf, img);
	}
}

t_data	*push_image(t_mlx_vars *mlx, t_fdf *fdf)
{
	t_data			*image;
	int				i;

	image = init_image(mlx->mlx);
	i = 0;
	while (i < ((fdf->dims[0]) * (fdf->dims[1])))
	{
		draw_lines(image, fdf, fdf->data + i);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, image->img, 0, 0);
	return (image);
}
