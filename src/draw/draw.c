/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:56:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 01:46:56 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../fdf.h"
#include <error.h>
#include <stdlib.h>

static t_data	*init_image(void *mlx)
{
	t_data	*img;

	img = malloc(sizeof(img));
	if (!img)
		error(1, 0, "Malloc Fail");
	img->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}


static void	fast_pxl_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	*get_scales(t_fdf *fdf)
{
	unsigned int	*scales;

	scales = malloc(sizeof(int) * 2);
	if (!scales)
		error(1, 0, "FU");
	scales[0] = (unsigned int) WINDOW_WIDTH / fdf->dims[0];
	scales[1] = (unsigned int) WINDOW_WIDTH / fdf->dims[1];
	return (scales);
}

static int	get_col(float col)
{
	int	colours[2];
	int	to_return_colour;

	colours[1] = 0;
	colours[0] = 50;
	to_return_colour = 0x00FF0000;
	to_return_colour = (to_return_colour & ~(0xFF << 16))
			| ((int)(col * 155) + 100);
	to_return_colour = (to_return_colour & ~(0xFF << 24))
			| ((int)(col * 255));
	return (to_return_colour);
}

static void	draw_lines_core(float a[3], float b[3], unsigned int scales[2],
		t_data *img)
{
	float				slope_y;
	float				slope_col;
	unsigned int		count;
	int					y;
	char				col;

	slope_y = (b[1] - a[1]) / (b[0] - a[0]);
	slope_col = (b[2] - a[2]) / (b[0] - a[0]);
	count = 0;
	while (count < scales[0])
	{
		y = (a[1] * scales[0]) + (b[0] * slope_y);
		col = get_col(a[2] + (b[0] * slope_col));
		fast_pxl_put(img, count, y, col);
	}
}

static void	draw_lines(t_data *img, unsigned int scales[2], t_points *point)
{
	if (point->lower)
	{
		draw_lines_core(point->projected,
			point->lower->projected, scales, img);
		draw_lines(img, scales, point->lower);
	}
	if (point->right)
	{
		draw_lines_core(point->projected,
			point->right->projected, scales, img);
		draw_lines(img, scales, point->right);
	}
}

t_data	*push_image(t_mlx_vars *mlx, t_fdf *fdf)
{
	t_data			*image;
	unsigned int	*scales;

	image = init_image(mlx->mlx);
	scales = get_scales(fdf);
	draw_lines(image, scales, fdf->data);
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, 0, 0);
	return (image);
}
