/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:36 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 16:10:52 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include <error.h>
#include <float.h>
#include <stdlib.h>

static void	get_proj_extremes(t_points *point, t_fdf *fdf)
{
	if (point->projected[0] < fdf->project_extremes[0])
		fdf->project_extremes[0] = point->projected[0];
	if (point->projected[1] < fdf->project_extremes[1])
		fdf->project_extremes[1] = point->projected[1];
	if (point->projected[0] > fdf->project_extremes[2])
		fdf->project_extremes[2] = point->projected[0];
	if (point->projected[1] > fdf->project_extremes[3])
		fdf->project_extremes[3] = point->projected[1];
}

static void	calc_ind(t_points *point, t_fdf *fdf)
{
	unsigned int	*src;

	src = point->fdf_coords;
	(point->projected)[0] = (src[0] * cosf(ISO_ANGLE))
		+ (src[1] * cosf(ISO_ANGLE + TWO_PI_3)) 
		+ (src[2] * cosf(ISO_ANGLE - TWO_PI_3));
	
	(point->projected)[1] = (src[0] * sinf(ISO_ANGLE))
		+ (src[1] * sinf(ISO_ANGLE + TWO_PI_3))
		+ (src[2] * sinf(ISO_ANGLE - TWO_PI_3));
	(point->projected)[2] = (src[2] - fdf->extremes[0])
		/ (fdf->extremes[1] - fdf->extremes[0]);
	point->calculated = 1;
	get_proj_extremes(point, fdf);
	if (point->lower && !point->lower->calculated)
		calc_ind(point->lower, fdf);
	if (point->right && !point->right->calculated)
		calc_ind(point->right, fdf);
}


void	calc_vals(t_fdf *fdf)
{
	fdf->project_extremes[0] = FLT_MAX;
	fdf->project_extremes[1] = FLT_MAX;
	fdf->project_extremes[2] = FLT_MIN;
	fdf->project_extremes[3] = FLT_MIN;
	calc_ind(fdf->data, fdf);
}

float scale(t_fdf *fdf)
{
	float 	x;
	float	y;

	x = fdf->project_extremes[2] - fdf->project_extremes[0];
	y = fdf->project_extremes[3] - fdf->project_extremes[1];
	x = (WINDOW_WIDTH * 8)/(x * 10);
	y = (WINDOW_HEIGHT * 8)/(y * 10);
	if	(y < x)
		x = y;
	return (y);
}

int	*offset(t_fdf *fdf)
{
	int	width;
	int	height;
	int	*offset;

	offset = malloc(sizeof(int) * 2);
	if(!offset)
				error(1, 0, "Malloc Error");
	width = fdf->project_extremes[2] - fdf->project_extremes[0];
	height = fdf->project_extremes[3] - fdf->project_extremes[1];
	offset[0] = (WINDOW_WIDTH - width) / 2;
	offset[1] = (WINDOW_HEIGHT - height) / 2;
	return (offset);
}


