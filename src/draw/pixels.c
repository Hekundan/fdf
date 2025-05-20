/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:22:31 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 16:18:43 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <math.h>

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

static int	get_col(float c)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 255;
	r = c * 255;
	g = 0;
	b = 255 - (c * 255);
	return (a << 24 | r << 16 | g << 8 | b);
}

static float	scale(t_fdf *fdf)
{
	float	x;
	float	y;

	x = fdf->project_extremes[2] - fdf->project_extremes[0];
	y = fdf->project_extremes[3] - fdf->project_extremes[1];
	x = (WINDOW_WIDTH * 8) / (x * 10);
	y = (WINDOW_HEIGHT * 8) / (y * 10);
	if (y < x)
		x = y;
	return (y);
}

void	draw_lines_core(t_vec a, t_vec b, t_fdf *fdf, t_data *img)
{
	t_vec	inc;
	float	steps;
	t_vec	p;
	float	i;

	inc = vec_sub(b, a);
	steps = fmaxf(fabsf(inc.x), fabsf(inc.y));
	if (steps == 0.f)
	{
		fast_pxl_put(img, (int)roundf(a.x * scale(fdf)),
			(int)roundf(a.y * scale(fdf)), get_col(a.z));
		return ;
	}
	inc = vec_div(inc, (t_vec){steps, steps, steps});
	p = a;
	i = 0;
	while (i < steps)
	{
		fast_pxl_put(img, (int) roundf(p.x),
			(int) roundf(p.y), get_col(p.z));
		i++;
		p = vec_add(p, inc);
	}
}
