/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:17:07 by johartma          #+#    #+#             */
/*   Updated: 2024/11/27 17:11:29 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length;
	char	*dest;

	length = 0;
	while (s[length])
		length++;
	if (length == 0)
	{
		dest = malloc(1);
		if (!dest)
			return (0);
		*dest = 0;
		return (dest);
	}
	dest = malloc(length + 1);
	if (! dest)
		return (0);
	length = 0;
	while (s[length])
	{
		dest[length] = f(length, s[length]);
		length++;
	}
	dest[length] = 0;
	return (dest);
}
