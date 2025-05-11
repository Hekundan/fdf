/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:47 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 01:15:51 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <error.h>
#include <stdlib.h>

int	close_win(int key, t_data *image, t_mlx_vars *data)
{
	key = 0;
	mlx_destroy_image(data->mlx, image);
	free (image);
	destroy_window(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf			*fdf;
	t_mlx_vars		*mlx_vars;
	t_data			*image;
	t_mlx_combined	comb;

	if (!(argc == 2))
		error(1, 0, "Wrong number of arguments. One (1) Filename please!");
	fdf = parse_values(argv[1]);
	calc_vals(fdf);
	mlx_vars = create_window();
	image = push_image(mlx_vars, fdf);
	free(fdf->data);
	(&comb)->mlx = mlx_vars;
	(&comb)->image = image;
	mlx_hook(mlx_vars->mlx, 2, 1L << 0, close_win, &comb);
	return (0);
}
