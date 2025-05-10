/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:16:48 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 15:11:14 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	if (!n)
		return (0);
	if (!s)
		*(char *)s = 0;
	return (ft_memset(s, 0, n));
}
