/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:28:20 by johartma          #+#    #+#             */
/*   Updated: 2024/11/20 14:14:30 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			count;

	count = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (count < n)
	{
		if (t1[count] != t2[count])
		{
			return (t1[count] - t2[count]);
		}
		count++;
	}
	return (0);
}
