/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:20:28 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 16:57:02 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			cnt;
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *) src;
	cnt = 0;
	dest2 = dest;
	while (cnt < n && (dest || src))
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		cnt++;
	}
	return (dest);
}
