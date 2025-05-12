/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:11:33 by johartma          #+#    #+#             */
/*   Updated: 2025/05/12 15:59:47 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H 
# define FDF_H
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define WINDOW_NAME "FDF"
# define ISO_ANGLE  0.523598f
# define TWO_PI_3   2.094395f

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_points
{
	unsigned int		fdf_coords[3];
	float				projected[3];
	struct s_points		*lower;
	struct s_points		*right;
	char				calculated;

}	t_points;

typedef struct s_fdf
{
	unsigned int	dims[2];
	unsigned int	extremes[2];
	float			project_extremes[4];
	t_points		*data;
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

int			close_win(int key, t_data *image, t_mlx_vars *data);
t_mlx_vars	*create_window(void);
void		destroy_window(t_mlx_vars *vars);
int			is_overflow(char *s);
t_fdf		*parse_values(char *filename);
void		calc_vals(t_fdf *fdf);
t_data		*push_image(t_mlx_vars *mlx, t_fdf *fdf);
float		scale(t_fdf *fdf);
int			*offset(t_fdf *fdf);
#endif
