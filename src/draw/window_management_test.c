/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:10:47 by johartma          #+#    #+#             */
/*   Updated: 2025/05/10 21:32:18 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <unistd.h>

int	main(void)
{
	t_mlx_vars	*win;

	win = create_window();
	sleep(5);
	destroy_window(win);
}
