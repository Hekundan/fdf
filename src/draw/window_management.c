/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:58:48 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 13:48:30 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <mlx.h>
#include <stdlib.h>

t_mlx_vars	*create_window(void)
{
	t_mlx_vars	*vars;

	vars = malloc(sizeof(t_mlx_vars));
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		free(vars);
		return (NULL);
	}
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_NAME);
	if (!vars->win)
	{
		free(vars->mlx);
		free(vars);
		return (NULL);
	}
	return (vars);
}

void	destroy_window(t_mlx_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	vars = NULL;
}
