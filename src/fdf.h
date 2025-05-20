/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:11:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 19:39:57 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H 
# define FDF_H
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1500
# define WINDOW_NAME "FDF"
# define ISO_ANGLE  0.523598f
# define TWO_PI_3   2.094395f
# define KEY_SYM_ESC	65307

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_points
{
	int				fdf_coords[3];
	float			projected[3];
	struct s_points	*lower;
	struct s_points	*right;
	char			calculated;

}	t_points;

typedef struct s_fdf
{
	int			dims[2];
	int			extremes[2];
	float		project_extremes[4];
	float		z_scale;
	t_points	*data;
}	t_fdf;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*win;
}	t_mlx_vars;

typedef struct s_mlx_combined
{
	t_mlx_vars	*mlx;
	t_data		*image;
}	t_mlx_combined;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

t_mlx_vars	*create_window(void);
void		destroy_window(t_mlx_vars *vars);
int			is_overflow(char *s);
t_fdf		*parse_values(char *filename);
void		calc_vals(t_fdf *fdf);
t_data		*push_image(t_mlx_vars *mlx, t_fdf *fdf);
void		scale_projected_points(t_fdf *fdf);
t_vec		vec_add(t_vec a, t_vec b);
t_vec		vec_sub(t_vec a, t_vec b);
t_vec		vec_div(t_vec a, t_vec b);
void		draw_lines_core(t_vec a, t_vec b, t_fdf *fdf, t_data *img);
int			is_not_numeric(char *c);

#endif
