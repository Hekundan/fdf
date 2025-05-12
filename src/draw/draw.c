/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:56:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 16:30:11 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../fdf.h"
#include <error.h>
#include <stdlib.h>
#include <math.h>

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

	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT
		&& x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length)
			+ ((x * (data->bits_per_pixel) / 8));
		*(unsigned int *)dst = color;
	}
}

// static int	get_col(float c)
// {
// 	int	a;
// 	int	r;

// 	if (c < 0.f)
// 		c = 0.f;
// 	if (c > 1.f)
// 		c = 1.f;
// 	r = (int)(c * 155.f) + 100;
// 	a = (int)(c * 255.f);
// 	return (a << 24) | (r << 16);
// }

void draw_lines_core(float a[3], float b[3], t_fdf *fdf, t_data *img)
{
	float	inc[3];
	float	steps;
	float	p[3];
	int		i;
	int		*off;
	
	off = offset(fdf);
	inc[0] = (b[0] - a[0] * scale(fdf));
	inc[1] = (b[1] - a[1] * scale(fdf));
	inc[2] = b[2] - a[2];
	steps = fmaxf(fabsf(inc[0]), fabsf(inc[1]));
	if (steps == 0.f)
	{
		fast_pxl_put(img, (int)roundf(a[0] * scale(fdf)),
			(int)roundf(a[1] * scale(fdf)), 0x00FFFFF);
		return ;
	}
	inc[0] /= steps;
	inc[1] /= steps;
	inc[2] /= steps;
	p[0] = (a[0] * scale(fdf)) + off[0];
	p[1] = (a[1] * scale(fdf)) + off[1];
	p[2] = a[2];
	i = 0;
	while (i < steps)
	{
		fast_pxl_put(img, (int) roundf(p[0]), (int) roundf(p[01]), 0x00FFFFF);
		i++;
		p[0] += inc[0];
		p[1] += inc[1];
		p[2] += inc[2];
	}
}

static void	draw_lines(t_data *img, t_fdf *fdf, t_points *point)
{
	if (point->lower)
	{
		draw_lines_core(point->projected,
			point->lower->projected, fdf, img);
		draw_lines(img, fdf, point->lower);
	}
	if (point->right)
	{
		draw_lines_core(point->projected,
			point->right->projected, fdf, img);
		draw_lines(img, fdf, point->right);
	}
}

t_data	*push_image(t_mlx_vars *mlx, t_fdf *fdf)
{
	t_data		*image;

	image = init_image(mlx->mlx);
	draw_lines(image, fdf, fdf->data);
	mlx_put_image_to_window(mlx->mlx, mlx->win, image->img, 0, 0);
	return (image);
}
