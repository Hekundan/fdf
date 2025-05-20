/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:36 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 20:49:48 by johartma         ###   ########.fr       */
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
	int	*src;

	src = point->fdf_coords;
	(point->projected)[0] = (src[0] * cosf(ISO_ANGLE))
		+ (src[1] * cosf(ISO_ANGLE + TWO_PI_3))
		+ (src[2] * fdf->z_scale * cosf(ISO_ANGLE - TWO_PI_3));
	(point->projected)[1] = (src[0] * sinf(ISO_ANGLE))
		+ (src[1] * sinf(ISO_ANGLE + TWO_PI_3))
		+ (src[2] * fdf->z_scale * sinf(ISO_ANGLE - TWO_PI_3));
	(point->projected)[2] = (float)(src[2] - fdf->extremes[0])
		/ (float)(fdf->extremes[1] - fdf->extremes[0] + 0.001f);
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
	fdf->z_scale = 3.0f / (float)(fdf->extremes[1] - fdf->extremes[0] + 1);
	calc_ind(fdf->data, fdf);
}

static void	apply_scale(t_points *p, float s, int ox, int oy)
{
	if (!p || p->calculated != 1)
		return ;
	p->projected[0] = p->projected[0] * s + ox;
	p->projected[1] = p->projected[1] * s + oy;
	p->calculated = 2;
	apply_scale(p->lower, s, ox, oy);
	apply_scale(p->right, s, ox, oy);
}

void	scale_projected_points(t_fdf *fdf)
{
	float	w;
	float	h;
	float	s;
	int		ox;
	int		oy;

	w = fdf->project_extremes[2] - fdf->project_extremes[0];
	h = fdf->project_extremes[3] - fdf->project_extremes[1];
	s = fminf((float)WINDOW_WIDTH / w, (float)WINDOW_HEIGHT / h) * 0.9;
	ox = (int)((WINDOW_WIDTH - w * s) * 0.5f
			- fdf->project_extremes[0] * s);
	oy = (int)((WINDOW_HEIGHT - h * s) * 0.5f
			- fdf->project_extremes[1] * s);
	apply_scale(fdf->data, s, ox, oy);
}
