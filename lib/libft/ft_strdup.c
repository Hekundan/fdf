/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:51:07 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 17:01:02 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*dest;

	length = 0;
	while (src[length])
		length++;
	if (length == 0)
	{
		dest = malloc(1);
		if (dest == 0)
			return (0);
		*dest = 0;
		return (dest);
	}
	dest = malloc(length + 1);
	if (dest == 0)
		return (0);
	length = 0;
	while (src[length])
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = 0;
	return (dest);
}
