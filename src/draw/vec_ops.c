/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:32:32 by johartma          #+#    #+#             */
/*   Updated: 2025/05/20 15:36:10 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_vec	vec_div(t_vec a, t_vec b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	return (a);
}
