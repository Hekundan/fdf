/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:56:47 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 16:34:46 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <error.h>
#include <stdlib.h>
#include <stdio.h>

static int	quit(t_mlx_combined *data)
{
	mlx_destroy_image(data->mlx->mlx, data->image->img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	free(data->image);
	free(data->mlx);
	exit(0);
	return (0);
}

static int	close_win(int key, t_mlx_combined *data)
{
	if (key == KEY_SYM_ESC)
	{
		quit(data);
	}
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
	scale_projected_points(fdf);
	mlx_vars = create_window();
	image = push_image(mlx_vars, fdf);
	free(fdf->data);
	(&comb)->mlx = mlx_vars;
	(&comb)->image = image;
	mlx_key_hook(mlx_vars->win, close_win, &comb);
	mlx_hook(mlx_vars->win, 17, 0, quit, &comb);
	mlx_loop(mlx_vars->mlx);
	return (0);
}
