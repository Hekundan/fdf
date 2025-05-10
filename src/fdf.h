/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:11:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/10 22:52:34 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H 
# define FDF_H
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000
# define WINDOW_NAME "FDF"

typedef struct s_points
{
	unsigned int	fdf_coords[3];
	float			projected[3];
}	t_points;


typedef struct s_fdf
{
	unsigned int	dims[2];
	t_points		***data;
}	t_fdf;

//Just a shell for function pointers of simple y = f(x) float operations
typedef float	(*t_operation)(float x);

typedef struct s_rotation_matrix
{
	float		angle;
	t_operation	*operations[3][3];
	float		result_matrix[3][3];
}	t_rotation_matrix;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}	t_mlx_vars;

t_mlx_vars	*create_window(void);
void		destroy_window(t_mlx_vars *vars);
t_list		*get_lines(char	*filename);

#endif
