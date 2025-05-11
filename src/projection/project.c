/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:57:36 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 01:36:27 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"

static void	calc_ind(t_points *point, t_fdf *fdf)
{
	unsigned int	*src;

	src = point->fdf_coords;
	(point->projected)[0] = (src[0] * cosf(ANGLE))
		+ (src[1] * cosf(ANGLE + 2)) 
		+ (src[2] * cosf(ANGLE - 2));
	(point->projected)[1] = (src[0] * sinf(ANGLE))
		+ (src[1] * sinf(ANGLE + 2)) 
		+ (src[2] * sinf(ANGLE - 2));
	(point->projected)[2] = (src[2] - fdf->extremes[0])
		/ (fdf->extremes[1] - fdf->extremes[0]);
	point->calculated = 1;
	if (point->lower && !point->lower->calculated)
		calc_ind(point->lower, fdf);
	if (point->right && !point->right->calculated)
		calc_ind(point->right, fdf);
}

void	calc_vals(t_fdf *fdf)
{
	calc_ind(fdf->data, fdf);
}
