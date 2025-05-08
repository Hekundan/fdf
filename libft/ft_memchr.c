/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:53:21 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 16:18:01 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	char			*s2;
	unsigned char	s3;
	unsigned char	c2;

	count = 0;
	s2 = (char *) s;
	c2 = c;
	while (count < n)
	{
		s3 = (unsigned char) *s2;
		if (s3 == c2)
			return ((void *) s2);
		s2++;
		count++;
	}
	return (0);
}
